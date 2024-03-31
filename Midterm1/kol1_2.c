// 2. Задача
// Eден природен e „интересен“ ако неговиот обратен број е делив со неговиот број на цифри.
// Обратен број е бројот составен од истите цифри, но во обратен редослед
// (на пример, 653 е обратен број на бројот 356).
// Од тастатура се внесува природен број n ( n > 9).
// Да се најде и отпечати најголемиот природен број помал од n кој што е „интересен“.
// Ако внесениот број не е валиден, да се отпечати соодветна порака (Brojot ne e validen).

#include <stdio.h>

int reverseNumber(int n) {
  int remainder = 0, reverse;

  while (n != 0) {
    remainder = n % 10;
    reverse = reverse * 10 + remainder;
    n /= 10;
  }

  return reverse;
}

int digits(int n) {
  int ct = 0;

  while(n > 0) {
    ct++;
    n /= 10;
  }

  return ct;
}

int main() {
  int n;
  scanf("%d", &n);

  if(n < 10) {
    printf("Brojot ne e validen");
    return 0;
  }

  for(int i = n - 1; i >= 0; i--) {
    if(reverseNumber(i) % digits(i) == 0) {
      printf("%d", i);
      break;
    }
  }

  return 0;
}
