#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAC_LEN 12
#define RAW_MAX_LEN 124
#define TEST_DATA_ROWS 20
#define TEST_DATA_COLS 64

// 函数声明
int validateMac(const char* mac);
int validateRaw(char* raw, int* rawSize);
void hexStringToBytes(const char* hex, unsigned char* bytes, int len);
int parsePackets(const unsigned char* rawBytes, int rawSize, unsigned char testData[TEST_DATA_ROWS][TEST_DATA_COLS], int* packetNum);
void generateAtString(const unsigned char testData[TEST_DATA_ROWS][TEST_DATA_COLS], int startPacket, int maxTotalLen, int maxPackets, char* atString, int* usedPackets);
void bytesToHexString(const unsigned char* bytes, int len, char* hexString);

int main(int argc, char* argv[]) {
    char testMac[MAC_LEN + 1];
    char testRaw[RAW_MAX_LEN + 3];
    int rawSize;
    unsigned char testData[TEST_DATA_ROWS][TEST_DATA_COLS] = { 0 };
    int packetNum;
    char advPktString[256] = { 0 };
    char scanPktString[256] = { 0 };
    int advPktNum, scanPktNum;

    // 输入处理
    if (argc >= 3) {
        strncpy(testMac, argv[1], MAC_LEN);
        testMac[MAC_LEN] = '\0';
        strncpy(testRaw, argv[2], RAW_MAX_LEN + 2);
        testRaw[RAW_MAX_LEN + 2] = '\0';
    }
    else {
        printf("请输入12位MAC地址（不带冒号）：");
        scanf("%12s", testMac);
        printf("请输入RAW数据（十六进制，可带0x前缀）：");
        scanf("%126s", testRaw);
    }

    // 校验MAC
    if (!validateMac(testMac)) 
        return 1;

    // 校验RAW
    if (!validateRaw(testRaw, &rawSize)) 
        return 1;

    // 转换RAW为字节数组
    hexStringToBytes(testRaw, testData[0], rawSize);

    // 解析packets
    if (!parsePackets(testData[0], rawSize, testData, &packetNum)) 
        return 1;

    // 生成ADVPKT (最多packetNum-1个packet)
    generateAtString(testData, 1, 31, packetNum - 1, advPktString, &advPktNum);

    // 生成SCANRES (剩余的packet)
    generateAtString(testData, 1 + advPktNum, 31, packetNum - advPktNum, scanPktString, &scanPktNum);

    // 输出结果
    printf("AT+ADVPKT=%s\n", advPktString);
    printf("AT+SCANRES=%s\n", scanPktString);
    printf("AT+MAC=%s\n", testMac);

    return 0;
}

// 校验MAC地址
int validateMac(const char* mac) {
    if (strlen(mac) != MAC_LEN) {
        fprintf(stderr, "MAC地址长度错误，请输入12位字符（不带冒号）\n");
        return 0;
    }
    for (int i = 0; i < MAC_LEN; i++) {
        if (!isxdigit((unsigned char)mac[i])) {
            fprintf(stderr, "MAC地址格式错误，只能是0-9, a-f, A-F\n");
            return 0;
        }
    }
    return 1;
}

// 校验RAW数据
int validateRaw(char* raw, int* rawSize) {
    char* p = raw;
    // 去掉0x前缀
    if (strncmp(raw, "0x", 2) == 0 || strncmp(raw, "0X", 2) == 0) p += 2;

    int len = strlen(p);
    if (len > RAW_MAX_LEN) {
        fprintf(stderr, "RAW数据超过长度范围\n");
        return 0;
    }
    if (len % 2 != 0) {
        fprintf(stderr, "RAW数据长度错误\n");
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isxdigit((unsigned char)p[i])) {
            fprintf(stderr, "RAW数据格式错误，只能是0-9, a-f, A-F\n");
            return 0;
        }
    }
    memmove(raw, p, len + 1);
    *rawSize = len / 2;
    return 1;
}

// 十六进制字符串转字节数组
void hexStringToBytes(const char* hex, unsigned char* bytes, int len) {
    char temp[3] = { 0 };
    for (int i = 0; i < len; i++) {
        temp[0] = hex[2 * i];
        temp[1] = hex[2 * i + 1];
        bytes[i] = (unsigned char)strtol(temp, NULL, 16);
    }
}

// 解析packets
int parsePackets(const unsigned char* rawBytes, int rawSize, unsigned char testData[TEST_DATA_ROWS][TEST_DATA_COLS], int* packetNum) {
    int j = 0;
    *packetNum = 0;
    while (j < rawSize) {
        unsigned char tempLen = rawBytes[j];
        int pktLen = tempLen + 1;
        if (j + pktLen > rawSize) {
            fprintf(stderr, "RAW数据解析错误：长度不足\n");
            return 0;
        }
        for (int jj = 0; jj < pktLen; jj++) {
            testData[1 + *packetNum][jj] = rawBytes[j + jj];
        }
        j += pktLen;
        (*packetNum)++;
        if (*packetNum >= TEST_DATA_ROWS - 1) {
            fprintf(stderr, "packet数量过多\n");
            return 0;
        }
    }
    if (*packetNum < 2) {
        fprintf(stderr, "packet包数量错误\n");
        return 0;
    }
    return 1;
}

// 生成AT命令字符串
void generateAtString(const unsigned char testData[TEST_DATA_ROWS][TEST_DATA_COLS], int startPacket, int maxTotalLen, int maxPackets, char* atString, int* usedPackets) {
    int totalLen = 0;
    *usedPackets = 0;
    atString[0] = '\0';
    while (*usedPackets < maxPackets) {
        int pktIndex = startPacket + *usedPackets;
        if (testData[pktIndex][0] == 0) break;
        int pktLen = testData[pktIndex][0] + 1;
        if (totalLen + pktLen > maxTotalLen) break;

        char hexStr[128] = { 0 };
        bytesToHexString(testData[pktIndex], pktLen, hexStr);
        strcat(atString, hexStr);
        totalLen += pktLen;
        (*usedPackets)++;
    }
}

// 字节数组转十六进制大写字符串
void bytesToHexString(const unsigned char* bytes, int len, char* hexString) {
    for (int i = 0; i < len; i++) {
        sprintf(hexString + 2 * i, "%02X", bytes[i]);
    }
}