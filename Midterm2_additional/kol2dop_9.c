// 2.1 - 9

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int svrznici(char *str, int indeks, int ct) {
    if(str[indeks] == '\0' || str[indeks] == '\n') return 0;

    if(tolower(str[indeks]) < 'a' || tolower(str[indeks]) > 'z') {
        if(ct >= 1 && ct <= 3) {
            return 1 + svrznici(str, indeks + 1, 0);
        } else {
            return svrznici(str, indeks + 1, 0);
        }
    }

    return svrznici(str, indeks + 1, ct + 1);
}

int main(){
    char str[100], r[100];
    int len = -1;

    while(fgets(str, 100, stdin)) {
        str[strlen(str) - 1] = 0;
        int svrzniciLength = svrznici(str, 0, 0);
        if(svrzniciLength > len) {
            len = svrzniciLength;
            strcpy(r, str);
        }
    }

    printf("%d: %s", len, r);

    return 0;
}
