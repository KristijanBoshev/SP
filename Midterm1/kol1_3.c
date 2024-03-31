// 3. Задача
// Од стандарден влез се чита еден природен број n. Меѓу природните броеви 
// помали од n да се најде оној чиј што збир на делителите е најголем.
// Во пресметувањето на збирот на делителите на даден број,
// да не се зема предвид самиот број.

#include <stdio.h>

int zbirDeliteli(int n) {
  int s = 0;

  for(int i = 1; i < n; i++) {
    if(n % i == 0) {
      s += i;
    }
  }

  return s;
}

int main() {
  int n;
  scanf("%d", &n);

  int broj = 0, del = 0;

  for(int i = 1; i < n; i++) {
    int zbir = zbirDeliteli(i);

    if(zbir > del) {
      del = zbir;
      broj = i;
    }
  }

  printf("%d", broj);

  return 0;
}
