// 8. Задача
// Од стандарден влез се внесуваат два цели броја N и Х.
// Да се најде најблискот број помал од N коj е тотално различен од бројот Х.
// Еден број е тотално различен од друг ако и само ако во него
// не се појавува ниту една од цифрите на другиот број.
// Задачата да се реши без употреба на низи и матрици.

#include <stdio.h>

int checkDigit(int a, int b) {
  int check = 1;

  while(a > 0) {
    if(a % 10 == b) { check = 0; }
    a /= 10;
  }

  return check;
}

int main() {
  int n, x;
  scanf("%d %d", &n, &x);

  for(int i = n - 1; i >= 0; i--) {
    int br = i, b = 1;
    
    while(br > 0) {
      if(!checkDigit(x, br % 10)) {
        b = 0;
      }

      br /= 10;
    }

    if(b) {
      printf("%d", i);
      break;
    }
  }

  return 0;
}
