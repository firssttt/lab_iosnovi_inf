#include <stdio.h>
#include <stdlib.h>

int N, K, count = 0;
int **board; 
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

void move(int x, int y, int step) {
    if (step == K) {
        count++;
        return;
    }
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && board[nx][ny] == 0) {
            board[nx][ny] = 1;
            move(nx, ny, step + 1);
            board[nx][ny] = 0;
        }
    }
}

int main() {
    printf("Введите N (размер поля) и K (длину маршрута): ");
    scanf("%d %d", &N, &K);

    if (N <= 0 || K < 0) {
        printf("Ошибка ввода!\n");
        return 1;
    }

    board = (int **)malloc(N * sizeof(int *));
    
    for (int i = 0; i < N; i++) {
        board[i] = (int *)malloc(N * sizeof(int));
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    board[0][0] = 1;
    move(0, 0, 0);
    
    printf("Маршрутов: %d\n", count);

    for (int i = 0; i < N; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}
