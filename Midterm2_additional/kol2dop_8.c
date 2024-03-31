// 2.1 - 8

#include <stdio.h>

int checkUp(char matrica[100][100], char zbor[16], int row, int col) {
    for(int i = 0; i < strlen(zbor); i++) {
        if(matrica[row - i][col] != zbor[i]) {
            return 0;
        }
    }

    return 1;
}

int checkDown(char matrica[100][100], char zbor[16], int row, int col) {
    for(int i = 0; i < strlen(zbor); i++) {
        if(matrica[row + i][col] != zbor[i]) {
            return 0;
        }
    }

    return 1;
}

int checkRight(char matrica[100][100], char zbor[16], int row, int col) {
    for(int i = 0; i < strlen(zbor); i++) {
        if(matrica[row][col + i] != zbor[i]) {
            return 0;
        }
    }
    return 1;
}

int checkLeft(char matrica[100][100], char zbor[16], int row, int col) {
    for(int i = 0; i < strlen(zbor); i++) {
        if(matrica[row][col - i] != zbor[i]) {
            return 0;
        }
    }
    return 1;
}

int check(char matrica[100][100], char zbor[16], int i, int j) {
    if(checkRight(matrica, zbor, i, j)) {
        printf("%d, %d -> %d, %d", i, j, i, j + strlen(zbor) - 1);
        return 1;
    } else if(checkLeft(matrica, zbor, i, j)) {
        printf("%d, %d -> %d, %d", i, j, i, j - strlen(zbor) + 1);
        return 1;
    } else if(checkUp(matrica, zbor, i, j)) {
        printf("%d, %d -> %d, %d", i, j, i - strlen(zbor) + 1, j);
        return 1;
    } else if(checkDown(matrica, zbor, i, j)) {
        printf("%d, %d -> %d, %d", i, j, i + strlen(zbor) - 1, j);
        return 1;
    }
}

int main() {
    int n, znamence = 0;
    scanf("%d", &n);

    char matrica[100][100];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf(" %c", &matrica[i][j]);
        }
    }

    char zbor[16];
    scanf("%s", zbor);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(check(matrica, zbor, i, j)) { return; }
        }
    }

    printf("Not Found");

    return 0;
}
