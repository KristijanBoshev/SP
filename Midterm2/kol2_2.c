// 2. Задача
// Во дадена датотека “broevi.txt” се запишани повеќе редови со броеви така што секој ред започнува со еден цел број (N>=1)
// што означува колку броеви следуваат по него во тој ред. Да се напише програма која на СИ за секој ред ќе го испечати бројот
// со најголема најзначајна цифра. Читањето на броеви завршува кога ќе се прочита 0.

#include <stdio.h>
#include <string.h>
#define MAX 100

int countDigits(int n) {
    int ct = 0;
    
    while(n) {
        ct++;
        n /= 10;
    }
    
    return ct;
}

int stepen(int n) {
    int ct = 1;
    for(int i = 0; i < n; i++) ct *= 10;
    return ct;
}

//ne menuvaj!
void wtf() {
    FILE *f = fopen("broevi.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
    wtf();
    
    // vashiot kod ovde
	FILE *f;
	if(!(f = fopen("broevi.txt", "r"))) return -1;
	
	int n;
	
	while(!feof(f)) {
	    fscanf(f, "%d", &n);
	    
	    if(n == 0) break;
	    
	    int a, b, indeks = 0, maxd = 0, broj = 0;
	    
	    for(int i = 0; i < n; i++) {
	        fscanf(f, "%d", &a);
	        
	        b = a;
	        b /= stepen(countDigits(a) - 1);
	        
	        if(b > maxd) {
	            broj = a;
	            maxd = b;
	            indeks = i;
	        }
	    }
	    
	    printf("%d\n", broj);
	}
	
	return 0;
}
