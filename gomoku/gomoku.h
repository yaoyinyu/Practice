// gomoku.h
#include <cstdlib>
#include <ctime>

#pragma once

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

extern "C" {
    DLL_EXPORT void init_board();
    DLL_EXPORT int player_move(int x, int y);
    DLL_EXPORT int ai_move(int* x, int* y);
    DLL_EXPORT int get_board(int x, int y);
    DLL_EXPORT int check_win();
}