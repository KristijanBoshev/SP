// 5. Задача
// Дадена е текстуална датотека (livce.txt) која претставува ливче во спортска обложувалница.
// На почетокот во датотеката, во посебен ред е запишана сумата на уплата (цел број).
// Потоа во секој ред од датотеката е запишан по еден тип во следниот формат:
// ab12 1 1.25
//  
// Првиот број е шифрата на типот (низа од знаци која не е подолга од 9 знаци), вториот број е типот (може да биде 1, 0 или 2) додека третиот број е коефициентот (реален број).
// Ваша задача е да се испечати типот со најголем коефициент како и можната добивка на ливчето. Доколку има повеќе типови со ист максимален коефициент, да се испечати првиот.
// Можната добивка се пресметува како производ на сите коефициенти со сумата на уплата.

#include <stdio.h>

// ne menuvaj ovde
void wf() {
    FILE *f = fopen("livce.txt", "w");
    char c;
    while((c = getchar()) != '#') { fputc(c, f); }
    fclose(f);
}

int main() {
    wf();
    // vasiot kod pocnuva od ovde

    FILE *f;
    if(!(f = fopen("livce.txt", "r"))) return -1;

    int n, indeks = 0;
    char shifra[100][100];
    int tip[100];
    float koef[100];

    fscanf(f, "%d", &n);

    while(!feof(f)) {
        fscanf(f, "%s %d %f", shifra[indeks], &tip[indeks], &koef[indeks]);
        if(feof(f)) break;
        indeks++;
    }

    float s = n, maxKoeficient = 0;
    int r = indeks;

    for(int i = 0; i < indeks; i++) {
        s *= koef[i];

        if(koef[i] > maxKoeficient) {
            maxKoeficient = koef[i];
            r = i;
        }
    }

    printf("%s %d %.2f\n%.2f", shifra[r], tip[r], koef[r], s);

    return 0;
}

