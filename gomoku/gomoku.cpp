// gomoku.cpp
#include "gomoku.h"
#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>

// ... 你的全局变量和辅助函数 ...

extern "C" {

    DLL_EXPORT void init_board() {
        // ... 实现 ...
    }

    DLL_EXPORT int player_move(int x, int y) {
        // ... 实现 ...
    }

    DLL_EXPORT int ai_move(int* x, int* y) {
        // ... 实现 ...
    }

    DLL_EXPORT int get_board(int x, int y) {
        // ... 实现 ...
    }

    DLL_EXPORT int check_win() {
        // ... 实现 ...
    }

} // extern "C"

static int board[15][15];
static int turn = 1; // 1玩家，2AI
static int winner = 0;

void init_board() {
    for (int i = 0; i < 15; ++i)
        for (int j = 0; j < 15; ++j)
            board[i][j] = 0;
    turn = 1;
    winner = 0;
    srand((unsigned)time(0)); // 正确
}

int get_board(int x, int y) {
    if (x < 0 || x >= 15 || y < 0 || y >= 15) return -1;
    return board[x][y];
}

int check_line(int x, int y, int dx, int dy, int who) {
    int cnt = 0;
    for (int i = -4; i <= 4; ++i) {
        int nx = x + i * dx, ny = y + i * dy;
        if (nx >= 0 && nx < 15 && ny >= 0 && ny < 15 && board[nx][ny] == who)
            ++cnt;
        else
            cnt = 0;
        if (cnt == 5) return 1;
    }
    return 0;
}

int check_win() {
    // 检查所有点
    for (int i = 0; i < 15; ++i)
        for (int j = 0; j < 15; ++j)
            for (int d = 0; d < 4; ++d) {
                int dx[4] = { 1, 0, 1, 1 }, dy[4] = { 0, 1, 1, -1 };
                for (int who = 1; who <= 2; ++who)
                    if (check_line(i, j, dx[d], dy[d], who))
                        return who;
            }
    // 检查平局
    int full = 1;
    for (int i = 0; i < 15; ++i)
        for (int j = 0; j < 15; ++j)
            if (board[i][j] == 0) full = 0;
    if (full) return 3;
    return 0;
}

int player_move(int x, int y) {
    if (winner) return 2;
    if (x < 0 || x >= 15 || y < 0 || y >= 15 || board[x][y] != 0) return 1;
    board[x][y] = 1;
    winner = check_win();
    turn = 2;
    return 0;
}

int ai_move(int* x, int* y) {
    if (winner) return 2;
    // 简单AI：随机找空位
    std::vector<std::pair<int, int>> empty;
    for (int i = 0; i < 15; ++i)
        for (int j = 0; j < 15; ++j)
            if (board[i][j] == 0)
                empty.push_back({ i, j });
    if (empty.empty()) return 2;
    int idx = std::rand() % empty.size();
    *x = empty[idx].first;
    *y = empty[idx].second;
    board[*x][*y] = 2;
    winner = check_win();
    turn = 1;
    return 0;
}