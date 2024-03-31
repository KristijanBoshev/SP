// 2.1 - 1
// Од стандарден влез се чита цел број N (N<=100) и потоа N низи од знаци. Низите знаци содржат букви, цифри и специјални знаци (без знаци за празно место), а секоја од нив не е подолга од 80 знаци.
// Да се напише програма со која што на стандарден излез ќе се отпечати најдолгата низа, којашто е палиндром (се чита исто од од лево на десно и од десно на лево) и што содржи барем еден специјален знак.
// Ако нема такви низи, се печати "Nema!". Ако има две или повеќе низи што го задоволуваат овој услов, се печати првата низа којашто го задоволува условот.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char niza[100]) {
    int pos = 0;
    char r[100];

    for(int i = strlen(niza) - 1; i >= 0; i--) {
        r[pos++] = niza[i];
    }

    for(int i = 0; i < strlen(niza); i++) {
        if(niza[i] != r[i]) return 0;
    }

    return 1;
}

int specijalenZnak(char niza[100]) {
    for(int i = 0; i < strlen(niza); i++) {
        if(!isalnum(niza[i]) && !isspace(niza[i])) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int n, znamence = 0, len = -1;
    scanf("%d", &n);

    char niza[100], najgolem[100];

    for(int i = 0; i < n; i++) {
        scanf("%s", niza);

        if(isPalindrome(niza) && specijalenZnak(niza) && (int)strlen(niza) > len) {
            len = strlen(niza);
            strcpy(najgolem, niza);
        }
    }

    printf("%s", len != -1 ? najgolem : "Nema!");

    return 0;
}
