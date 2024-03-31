// 2.1 - 6
// Од стандарден влез се чита природен број N (N <= 100), како и низа од позитивни цели броеви a[ ] со N елементи. 
// Да се напише функција int par(a, n) која ќе го врати најмалиот елемент во низата кој се појавува парен број пати во низата.
// Доколку нема таков елемент, функцијата враќа вредност 0.
// Напишете програма што ќе ја повика функцијата par за внесената низа a[ ] и ќе го испечати најмалиот број којшто
// се појавува парен број пати во низата a[ ].

#include <stdio.h>

int par(int niza[100], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(niza[i] > niza[j]) {
                int temp = niza[i];
                niza[i] = niza[j];
                niza[j] = temp;
            }
        }
    }

    int ct = 0, broj = -1;
    for(int i = 1; i < n; i++) {
        if(niza[i - 1] == niza[i]) {
            ct++;
            continue;
        }

        if((ct + 1) % 2 == 0) {
            broj = niza[i - 1];
            break;
        } else {
            ct = 0;
            broj = -1;
        }
    }

    return broj;
}

int main() {
    int n;
    scanf("%d", &n);

    int niza[100];

    for(int i = 0; i < n; i++) {
        scanf("%d", &niza[i]);
    }

    if(par(niza, n) != -1) printf("Najmaliot element koj se pojavuva paren broj pati e %d", par(niza, n));
    else printf("Nitu eden element ne se pojavuva paren broj pati!");

    return 0;
}
