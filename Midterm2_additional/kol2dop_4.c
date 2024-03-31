// 2.1 - 4
// Од тастатура се внесуваат димензиите m и n на матрица од цели броеви, Аmxn, ( 0 < m, n < 30 ) и нејзините елементи.
// Потоа се внесуваат два цели броја r и k  (индекси на редица/колона од матрицата, т.е. 0 <= r < m и 0 <= k < n).
// Да се напише програма која ja трансформира матрицата А така што елементите над редицата r и
// лево од колоната k се заменуваат со минималната вредност од матрицата А.
// Новодобиената матрица да се запише во датотека "matrica.txt".

#include <stdio.h>
void printFile() {
    FILE *f=fopen("matrica.txt","r");
    char line[1000];
    while(!feof(f)){
        fgets(line,1000,f);
        if (feof(f))
            break;
        printf("%s",line);
    }
    fclose(f);
}

int main() {
    //Vasiot kod tuka
    int m, n, r, k;
    scanf("%d %d %d %d", &m, &n, &r, &k);

    int matrica[30][30], min_vrednost=100000;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrica[i][j]);

            if(matrica[i][j] < min_vrednost)
                min_vrednost = matrica[i][j];
        }
    }

    FILE *f = fopen("matrica.txt", "w");

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            //printf("%d ", i < r && j < k ? min_vrednost : matrica[i][j]);
            fprintf(f, "%d ", i < r && j < k ? min_vrednost : matrica[i][j]);
        }
        fprintf(f, "\n");
        //printf("\n");
    }

    fclose(f);
    // do tuka
    printFile();
    return 0;
}