#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20
#define MAX_SNAKE_SIZE 100

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point body[MAX_SNAKE_SIZE];
    int length;
    char direction;
} Snake;

void gotoxy(int x, int y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void hideCursor() {
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void drawMap() {
    int i;
    for (i = 0; i <= WIDTH; i++) {
        gotoxy(i, 0); printf("#");
        gotoxy(i, HEIGHT); printf("#");
    }
    for (i = 0; i <= HEIGHT; i++) {
        gotoxy(0, i); printf("#");
        gotoxy(WIDTH, i); printf("#");
    }
}

void initSnake(Snake *snake) {
    int i;
    snake->length = 3;
    for (i = 0; i < snake->length; i++) {
        snake->body[i].x = WIDTH / 2 - i;
        snake->body[i].y = HEIGHT / 2;
    }
    snake->direction = 'D'; // 初始向右
}

void drawSnake(Snake *snake) {
    int i;
    for (i = 0; i < snake->length; i++) {
        gotoxy(snake->body[i].x, snake->body[i].y);
        if (i == 0)
            printf("O"); // 蛇头
        else
            printf("o"); // 蛇身
    }
}

void eraseSnake(Snake *snake) {
    gotoxy(snake->body[snake->length - 1].x, snake->body[snake->length - 1].y);
    printf(" ");
}

void genFood(Point *food, Snake *snake) {
    int i, flag;
    do {
        flag = 0;
        food->x = rand() % (WIDTH - 2) + 1;
        food->y = rand() % (HEIGHT - 2) + 1;
        for (i = 0; i < snake->length; i++) {
            if (snake->body[i].x == food->x && snake->body[i].y == food->y) {
                flag = 1;
                break;
            }
        }
    } while (flag);
    gotoxy(food->x, food->y);
    printf("*");
}

int isCollision(Snake *snake) {
    int i;
    // 撞墙
    if (snake->body[0].x == 0 || snake->body[0].x == WIDTH ||
        snake->body[0].y == 0 || snake->body[0].y == HEIGHT)
        return 1;
    // 撞自己
    for (i = 1; i < snake->length; i++) {
        if (snake->body[0].x == snake->body[i].x &&
            snake->body[0].y == snake->body[i].y)
            return 1;
    }
    return 0;
}

void moveSnake(Snake *snake, int grow) {
    int i;
    for (i = snake->length - 1; i > 0; i--) {
        snake->body[i] = snake->body[i - 1];
    }
    switch (snake->direction) {
        case 'W': snake->body[0].y--; break;
        case 'S': snake->body[0].y++; break;
        case 'A': snake->body[0].x--; break;
        case 'D': snake->body[0].x++; break;
    }
    if (grow)
        snake->length++;
}

int main() {
    Snake snake;
    Point food;
    int score = 0, speed = 100, grow = 0;
    char ch;
    srand((unsigned)time(NULL));
    hideCursor();
    drawMap();
    initSnake(&snake);
    drawSnake(&snake);
    genFood(&food, &snake);

    while (1) {
        Sleep(speed);
        if (_kbhit()) {
            ch = _getch();
            if ((ch == 'w' || ch == 'W') && snake.direction != 'S') snake.direction = 'W';
            if ((ch == 's' || ch == 'S') && snake.direction != 'W') snake.direction = 'S';
            if ((ch == 'a' || ch == 'A') && snake.direction != 'D') snake.direction = 'A';
            if ((ch == 'd' || ch == 'D') && snake.direction != 'A') snake.direction = 'D';
        }
        eraseSnake(&snake);
        grow = 0;
        if (snake.body[0].x == food.x && snake.body[0].y == food.y) {
            grow = 1;
            score += 10;
            genFood(&food, &snake);
        }
        moveSnake(&snake, grow);
        drawSnake(&snake);
        gotoxy(WIDTH + 2, 2); printf("分数: %d", score);
        if (isCollision(&snake)) {
            gotoxy(WIDTH / 2 - 4, HEIGHT / 2); printf("游戏结束!");
            break;
        }
    }
    gotoxy(0, HEIGHT + 2);
    system("pause");
    return 0;
}