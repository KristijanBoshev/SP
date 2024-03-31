// 19. Задача
// Од стаднарден влез се читаат N низи од знаци (стрингови) не подолги од 80 знаци.
//
// На почетокот на програмата се читаат два цели броеви:
// N - бројот на низи од знаци кои ќе се читаат и
// X - поместување.
//
// Секоја од вчитаните низи од знаци треба да се трансформира на тој начин што секоја од малите и
// големите букви (a-z, A-Z) се заменува со истата буква поместена X места понапред во азбуката (a-z).
// Ако се надмине опсегот на буквите во азбуката, се продолжува циклично од почетокот на азбуката.
// Трансформираната низа да се отпечати на СИ.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char pomestuvanje(char bukva, int x) {
    if(toupper(++bukva) > 'Z') {
        if(bukva > 'z') {
            bukva = 'a';
        } else if(bukva > 'Z') {
            bukva = 'A';
        }
    }

    if(x > 1) return pomestuvanje(bukva, x - 1);

    return bukva;
}

int main() {
    int n, x;
    scanf("%d %d", &n, &x);

    for(int i = 0; i <= n; i++) {
        char rechenica[100];
        fgets(rechenica, 100, stdin);
        
        if(strlen(rechenica) <= 1) continue;

        for(int j = 0; j < strlen(rechenica); j++) {
            if(tolower(rechenica[j]) < 'a' || tolower(rechenica[j]) > 'z') continue;

            rechenica[j] = pomestuvanje(rechenica[j], x);
        }

        printf("%s", rechenica);
    }

    return 0;
}

