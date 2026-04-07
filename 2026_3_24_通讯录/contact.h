#pragma once

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
#define DEFAULT_SZ 3
#define INC_SZ 2


//人的信息
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

//静态
//通讯录信息
//typedef struct Contact
//{
//	PeoInfo data[MAX];
//	int count = 0;
//}Contact;

//动态
typedef struct Contact
{
	PeoInfo *data;
	int count = 0;
	//当前容量
	int capacity;
}Contact;

//初始化通讯录
int Inintcontact(Contact* pc);

//销毁信息
void DestroyContact(Contact* pc);

//添加信息
void AddContact(Contact* pc);

//显示信息
void ShowContact(const Contact* pc);

//删除信息
void DelContcat(Contact* pc);

//查找信息
void SearchContcat(Contact* pc);

//修改信息
void ModifyContcat(Contact* pc);

//排序信息（姓名）
void SostContact(Contact* pc);

//保存通讯录
void SaveContact(const Contact* pc);

//加载通讯录
void LoadContact(Contact* pc);