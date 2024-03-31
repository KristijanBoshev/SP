// 11. Задача
// Да се напише програма во која од дадена датотека со име "input.txt" за секој ред ќе се отпечати бројот на цифри во тој ред,
// знакот :, па самите цифри подредени според ASCII кодот во растечки редослед. Редовите во датотеката не се подолги од 100 знаци.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void wtf() {
    FILE *f = fopen("input.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
    wtf();
    
    FILE *f;
    
    if(!(f = fopen("input.txt", "r"))) return -1;
    
    char c[100], ascii[100];
    
    while(!feof(f)) {
        fscanf(f, "%s", c);
        
        if(feof(f)) break;
        
        int n = 0, ct = 0;
        for(int i = 0; i < strlen(c); i++) {
            if(c[i] >= '0' && c[i] <= '9') {
                ascii[ct] = c[i];
                n++;
                ct++;
            }
        }
        
        for(int i = 0; i < ct - 1; i++) {
            for(int j = 0; j < n - 1; j++) {
                if(ascii[j] > ascii[j + 1]) {
                    char temp = ascii[j];
                    ascii[j] = ascii[j + 1];
                    ascii[j + 1] = temp;
                }
            }
        }
        
        printf("%d:", n);
        for(int i = 0; i < ct; i++) {
            printf("%c", ascii[i]);
        }
        printf("\n");
    }
    
    return 0;
}
