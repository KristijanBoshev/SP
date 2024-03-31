// 2.1 - 2
// Од тастатура се чита природен број N (N < 400).
// Да се напише програма којашто формира квадратна матрица што ги содржи броевите од 1 до N по растечки редослед на следниот начин:
// во првата колона во правец од горе надолу, па продолжува во втората колона од долу нагоре, па продолжува во третата колона од горе надолу итн.
// Да се избере најмалата димензија на матрицата во која ќе ги собере сите броеви до N. Доколку има преостанати празни места,
// тие да се пополнат со нули.

#include <stdio.h>
void printFile() {
    FILE *f=fopen("shema.txt","r");
    char line[1000];
    while(!feof(f)){
        fgets(line,1000,f);
        if (feof(f))
            break;
        printf("%s",line);
    }
    fclose(f);
}

int najblizokKvadrat(int n) {
    int k = 1;
    while(k * k < n) {
        k++;
    }

    return k;
}

int main() {
    //Vasiot kod tuka
    FILE *f = fopen("shema.txt", "w");
    
    if(!f) {
        return 0;
    }
    
    int m, matrica[100][100] = {0}, curr = 1;
    scanf("%d", &m);

    int n = najblizokKvadrat(m);

    for(int i = 0; i < n; i++) {
        if((i + 1) % 2 != 0) {
            for(int j = 0; j < n; j++) {
                if(curr <= m)
                    matrica[i][j] = curr++;
            }
        } else {
            for(int j = n - 1; j >= 0; j--) {
                if(curr <= m)
                    matrica[i][j] = curr++;
            }
        }

    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            //printf("%d ", matrica[j][i]);
            fprintf(f, "%d ", matrica[j][i]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
    // do tuka
    printFile();
    return 0;
}