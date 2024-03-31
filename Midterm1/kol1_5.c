// 5. Задача
// Од тастатура се читаат 2 позитивни цели броеви.
// Доколку се внесе барем еден негативен број или 0 треба да се печати „Invalid input“.
// Треба да се определи дали помалиот број “е парен еквивалент” од поголемиот број.
// Еден број “е парен еквивалент” на друг број, ако и само ако неговите цифри
// се наоѓаат на парните позиции од другиот број, во истиот редослед.
// Соодветно да се испечатат пораки „PAREN“ и „NE“.
// Позициите треба да се сметаат оддесно-налево (најмалку значајната цифра е на позиција 1)

#include <stdio.h>

int parenEkvivalent(int n, int m) {
  int pos = 1;
  int b = 1;

  while(n > 0) {
    if(pos % 2 != 0) {
      n /= 10;
      pos++;
      continue;
    }

    if(n % 10 != m % 10) {
      b = 0;
      break;
    } else if(n % 10 == m % 10) {
      m /= 10;
    }

    n /= 10;
    pos++;
  }

  return b;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  if(n <= 0 || m <= 0) {
    printf("Invalid input");
    return 0;
  }

  int pe;

  if(n >= m) {
    pe = parenEkvivalent(n, m);
  } else {
    pe = parenEkvivalent(m, n);
  }

  if(pe) {
    printf("PAREN");
  } else {
    printf("NE");
  }

  return 0;
}
