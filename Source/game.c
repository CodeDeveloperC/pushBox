//game.c
#include<stdio.h>
#include <conio.h>
#include <stdlib.h>

// 0:空地 :
// 1:目的地 :☆
// 2:墙壁 :■
// 4:箱子 :□
// 8:玩家 :♂

int line = 0, row = 0;
enum _state {
    space = 0,
    destination = 1,
    wall = 2,
    box = 4,
    player = 8
} state;

int map[13][14] = {
        {space, space, space, space, wall,  wall,  wall,  wall,  wall,        wall,        space,       space,       space, space},
        {space, space, space, space, wall,  space, space, space, space,       wall,        space,       space,       space, space},
        {space, wall,  wall,  wall,  wall,  space, space, box,   box,         wall,        wall,        wall,        wall,  wall},
        {space, wall,  space, space, space, wall,  space, space, space,       wall,        space,       space,       space, wall},
        {space, wall,  space, box,   space, space, space, box,   space,       space,       space,       box,         space, wall},
        {space, wall,  space, space, space, wall,  wall,  space, wall,        wall,        wall,        wall,        wall,  wall},
        {wall,  wall,  wall,  wall,  box,   wall,  wall,  space, space,       space,       space,       space,       space, wall},
        {wall,  space, space, space, box,   space, wall,  space, space,       space,       player,      space,       space, wall},
        {wall,  space, box,   space, box,   space, wall,  space, wall,        wall,        wall,        wall,        wall,  wall},
        {wall,  wall,  space, space, box,   space, wall,  space, wall,        destination, destination, destination, wall,  space},
        {space, wall,  space, wall,  wall,  space, space, space, space,       destination, destination, destination, wall,  space},
        {space, wall,  space, space, space, space, wall,  wall,  destination, destination, destination, destination, wall,  space},
        {space, wall,  wall,  wall,  wall,  wall,  wall,  wall,  wall,        wall,        wall,        wall,        wall,  space}

};

//打印地图
void DrawMap(int map[][14]);

//左移
void MoveLeft();

//右移
void MoveRight();

//上移
void MoveUp();

//下移
void MoveDown();

//判断箱子是否全部到达目的地
int IsVictory();

int main(void) {

    DrawMap(map);
    char key = 0;
    int num = 0;


    while (1) {
        key = _getch();
        switch (key) {
            //左移
            case 'A':
            case 'a':
                switch (map[line][row - 1]) {
                    case space:
                    case destination:
                        MoveLeft();
                        break;

                    case box:
                    case box + destination:
                        if (map[line][row - 2] == space || map[line][row - 2] == destination) {
                            map[line][row - 2] += box;
                            map[line][row - 1] -= box;
                            MoveLeft();
                        }
                        break;
                }
                break;

                //上移
            case 'w':
            case 'W':
                switch (map[line - 1][row]) {
                    case space:
                    case destination:
                        MoveUp();
                        break;

                    case box:
                    case box + destination:
                        if (map[line - 2][row] == space || map[line - 2][row] == destination) {
                            map[line - 2][row] += box;
                            map[line - 1][row] -= box;
                            MoveUp();
                        }
                        break;
                }
                break;

                //下移
            case 's':
            case 'S':
                switch (map[line + 1][row]) {
                    case space:
                    case destination:
                        MoveDown();
                        break;

                    case box:
                    case box + destination:
                        if (map[line + 2][row] == space || map[line + 2][row] == destination) {
                            map[line + 2][row] += box;
                            map[line + 1][row] -= box;
                            MoveDown();
                        }
                        break;
                }
                break;

                //右移
            case 'd':
            case 'D':
                switch (map[line][row + 1]) {
                    case space:
                    case destination:
                        MoveRight();
                        break;

                    case box:
                    case box + destination:
                        if (map[line][row + 2] == space || map[line][row + 2] == destination) {
                            map[line][row + 2] += box;
                            map[line][row + 1] -= box;
                            MoveRight();
                        }
                        break;
                }
                break;
        }

        system("cls");
        DrawMap(map);
    }


    return 0;
}


void DrawMap(int map[][14]) {
    int i = 0, j = 0;
    for (i = 0; i < 13; ++i) {
        for (j = 0; j < 14; ++j) {
            switch (map[i][j]) {
                case space:
                    printf("  ");
                    break;

                case destination:
                    printf("☆");
                    break;

                case destination + box:
                    printf("★");
                    break;

                case wall:
                    printf("■");
                    break;

                case box:
                    printf("□");
                    break;

                case player:
                case player + destination:
                    printf("♂");
                    line = i;
                    row = j;
                    break;

                default:
                    break;
            }
        }

        printf("\n");
    }
}


void MoveUp() {
    map[line][row] -= player;
    map[line - 1][row] += player;
}

void MoveDown() {
    map[line][row] -= player;
    map[line + 1][row] += player;
}

void MoveLeft() {
    map[line][row] -= player;
    map[line][row - 1] += player;
}

void MoveRight() {
    map[line][row] -= player;
    map[line][row + 1] += player;
}

int IsVictory() {
    int i, j, victory = 0;
    for (i = 0; i < 13; ++i) {
        for (j = 0; j < 14; ++j) {
            if (map[i][j] == box)
                break;
        }
    }

    if (i >= 12 && j >= 13) {
        victory = 1;
    }

    return victory;
}


