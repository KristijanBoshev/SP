// 2.1 - 3
// Од стандарден влез се чита цел број N (N<100) и потоа N низи од знаци. Низите знаци содржат букви, цифри и специјални знаци, а секоја од нив не е поголема од 50 знаци.
// Да се напише програма што ќе ги отпечати на екран сите низи од знаци во кои се содржи поднизата А1c  најмалку 2 пати
// (пр. A1c01АA1c92, 12A1cwwA1cxy, аA1cwA1cA1ccA1cxab) според редоследот како што се прочитани од влезот. При печатење на зборовите, сите алфабетски знаци треба да се испечатат со мали букви.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int checkSubstring(char *str1, char *str2) {
    int flag, ct = 0, len1 = strlen(str1), len2 = strlen(str2);

    for(int i = 0; i < len1; i++) {
        flag = 1;
        for(int j = 0; j < len2; j++) {
            if(tolower(str1[i + j]) != tolower(str2[j])) {
                flag = 0;
                break;
            }
        }

        if(flag) { ct++; }
    }

    return ct;
}

void printLower(char *str) {
    for(int i = 0; i < strlen(str); i++) {
        printf("%c", tolower(str[i]));
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    if(n >= 100) { return 0; }

    char tekst[100];
    char sub[4] = "A1c";

    for(int i = 0; i < n; i++) {
        scanf("%s", tekst);

        if(checkSubstring(tekst, sub) > 1) {
            printLower(tekst);
        }
    }

    return 0;
}

