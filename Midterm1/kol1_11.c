// 11. Задача
// Цик-цак е број за кој важи дека за секој пар соседни цифри
// во бројот важи дека едната е помала од 5, а другата е поголема или еднаква на 5.
//
// На пример, ако бројот x е составен од цифрите a, b, c и d, тогаш за нив важи:
// a<5, b>=5, c<5, d>=5 или a>=5, b<5, c>=5, d<5
// Пр.  508294, 2638, 81
//
// Од тастатура се читаат непознат број цели броеви поголеми од или еднакви на 10 (броевите помали од 10 се игнорираат).
// Читањето завршува во моментот кога ќе се прочита знак што не е цифра. Да се испечатат сите цик-цак броеви.

#include <stdio.h>

int main() {
  int broj;

  while(1) {
    if(!scanf("%d", &broj)) {
      break;
    }

    if(broj <= 10) {
      continue;
    }

    int n = broj;
    int cikcak = 1;

    while(n > 10) {
      int a = n % 10;
      int b = (n / 10) % 10;

      if( (a < 5 && b < 5) || (a >= 5 && b >= 5) ) {
          cikcak = 0;
          break;
      }

      n /= 10;
    }

    if(cikcak) {
      printf("%d\n", broj);
    }
  }
  return 0;
}
