// 2.1 - 10

#include<stdio.h>
#include<ctype.h>
#include<string.h>

void wtf() {
    FILE *f = fopen("matrica.txt", "w");
    char c;
    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}

int cifri(int n) {
    int ct = 0;

    if(n == 0) return 1;

    while(n) {
        ct++;
        n /= 10;
    }

    return ct;
}

int funkcija(int n) {
    int r = 1, c = cifri(n);
    
    for(int i = 0; i < c; i++) {
        r *= 10;
    }
    
    return r;
}

int main() {
    wtf();
    //vasiot kod ovde
    
    FILE *f = fopen("matrica.txt", "r");
    
    int n, m, matrica[100][100], rez = 0;
    fscanf(f, "%d %d", &n, &m);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            fscanf(f, "%d", &matrica[i][j]);
        }
    }
    
    fclose(f);
    
    for(int j = 0; j < m; j++) {
        rez = 0;
        for(int i = 0; i < n; i++) {
            int broj = i * funkcija(j) + j;
            if(broj == matrica[i][j]) {
                rez++;
            }
        }
        
        printf("%d\n", rez);
    }
    
    return 0;
}
