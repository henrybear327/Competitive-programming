#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NOTHING 0
#define BLACK 1
#define WHITE 2
#define USED_B 3
#define USED_W 4

int map[19][19];

void print_map()
{
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int dir_array[8][2] = {
    {-1, -1}, {1, 1}, {0, -1}, {0, 1}, {1, -1}, {-1, 1}, {-1, 0}, {1, 0},
};

int color, flag = 0;

int start_x, start_y, end_x, end_y;

int in_boundary(int x, int y)
{
    if (0 <= x && x < 19 && 0 <= y && y < 19)
        return true;
    else
        return false;
}

int visited[8];

void check_over_five(int x, int y, int dir, int count)
{
    // printf("Function start: %d %d %d %d\n", x + 1, y + 1, dir, count);
    if (count == 1) {
        start_x = x;
        start_y = y;
        for (int i = 0; i < 8; i++) {
            if (in_boundary(x + dir_array[i][0], y + dir_array[i][1])) { // in zone
                if (visited[i] != 1 &&
                    map[x + dir_array[i][0]][y + dir_array[i][1]] == color) {
                    if (flag == 1)
                        return;

                    visited[i] = 1;
                    check_over_five(x + dir_array[i][0], y + dir_array[i][1], i,
                                    count + 1);
                }
            }
        }
    } else {
        if (in_boundary(x + dir_array[dir][0], y + dir_array[dir][1])) { // in zone
            if (map[x + dir_array[dir][0]][y + dir_array[dir][1]] ==
                color) { // same color
                check_over_five(x + dir_array[dir][0], y + dir_array[dir][1], dir,
                                count + 1);
            } else {
                if (dir == 0 || dir == 2 || dir == 4 || dir == 6) { // change direction
                    if (visited[dir + 1] != 1 &&
                        map[start_x + dir_array[dir + 1][0]][start_y +
                                dir_array[dir + 1][1]] ==
                        color) {
                        visited[dir + 1] = 1;
                        check_over_five(start_x + dir_array[dir + 1][0],
                                        start_y + dir_array[dir + 1][1], dir + 1,
                                        count + 1);
                    } else {
                        if (count == 5) {
                            // great
                            printf("%d\n", color);
                            flag = 1;
                            end_x = x;
                            end_y = y;
                        } else {
                            return;
                        }
                    }
                } else {
                    if (count == 5) {
                        // great
                        printf("%d\n", color);
                        flag = 1;
                        end_x = x;
                        end_y = y;
                    } else {
                        return;
                    }
                }
            }
        } else {
            if (dir == 0 || dir == 2 || dir == 4 || dir == 6) { // change direction
                if (visited[dir + 1] != 1 &&
                    in_boundary(start_x + dir_array[dir + 1][0],
                                start_y + dir_array[dir + 1][1]) &&
                    map[start_x + dir_array[dir + 1][0]][start_y +
                            dir_array[dir + 1][1]] ==
                    color) {
                    visited[dir + 1] = 1;
                    check_over_five(start_x + dir_array[dir + 1][0],
                                    start_y + dir_array[dir + 1][1], dir + 1, count + 1);
                } else {
                    if (count == 5) {
                        // great
                        printf("%d\n", color);
                        flag = 1;
                        end_x = x;
                        end_y = y;
                    } else {
                        return;
                    }
                }
            } else {
                if (count == 5) {
                    // great
                    printf("%d\n", color);
                    flag = 1;
                    end_x = x;
                    end_y = y;
                } else {
                    return;
                }
            }
        }
    }
}

int main()
{
    int test_cases;
    while (scanf("%d", &test_cases) == 1) {
        while (test_cases--) {
            for (int i = 0; i < 19; i++) {
                for (int j = 0; j < 19; j++) {
                    scanf("%d", &map[i][j]);
                }
            }

            memset(visited, 0, sizeof(visited));

            for (int i = 0; i < 19 && flag != 1; i++) {
                for (int j = 0; j < 19 && flag != 1; j++) {
                    if (map[i][j] == BLACK || map[i][j] == WHITE) {
                        color = map[i][j];
                        // printf("New\n");
                        check_over_five(i, j, -1, 1);
                        memset(visited, 0, sizeof(visited));
                    }
                }
            }

            if (flag == 1) {
                start_x++;
                start_y++;
                end_x++;
                end_y++;
                if (start_y == end_y) { // vertical
                    if (start_x < end_x)
                        printf("%d %d\n", start_x, start_y);
                    else
                        printf("%d %d\n", end_x, end_y);
                } else if (start_y < end_y) {
                    printf("%d %d\n", start_x, start_y);
                } else
                    printf("%d %d\n", end_x, end_y);

                flag = 0;
            } else
                printf("0\n");
        }
    }
    return 0;
}
