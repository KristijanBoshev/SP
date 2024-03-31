// 2.1 - 12
// За секоја редица, да се испечати индексот на редицата и бројот на штосни броеви во таа редица во формат indeks_na_redica:
// broj_na_stosni_broevi_vo_taa_redica (види тест пример).
// Штосен број е број чија парност е иста со парноста на збирот од индексите на редицата и колоната на елементот.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void wtf() {
    FILE *f = fopen("matrica.txt", "w");
    char c;
    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}

int parnost(int a, int b) {
    return (a % 2 == 0 && b % 2 == 0) || (a % 2 != 0 && b % 2 != 0);
}

int main() {
    wtf();
    //vasiot kod ovde
    int n, m, matrica[100][100], rez[100] = {0};
    FILE *f = fopen("matrica.txt", "r");
    fscanf(f, "%d %d", &n, &m);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            fscanf(f, "%d", &matrica[i][j]);
        }
    }
    
    fclose(f);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(parnost(i + j, matrica[i][j])) {
                rez[i]++;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        printf("%d: %d\n", i, rez[i]);
    }
    
    return 0;
}
