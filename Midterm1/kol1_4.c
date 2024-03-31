// 4. Задача
// Од стандарден влез се читаат знаци се додека не се прочита извичник.
// Во вака внесениот текст се скриени цели броеви (помали од 100).
// Да се напише програма што ќе ги прочита сите знаци и на излез
// ќе го испечати збирот на сите броеви скриени во текстот.

#include <stdio.h>
#include <string.h>

int main() {
  char c[128];
  int s = 0;

  while(1) {
    scanf("%s", c);

    int broj = 0;

    for(int i = 0; i < strlen(c); i++) {
      int val = (int)(c[i] - '0');

      if(val >= 0 && val <= 9) {
            broj = (broj * 10) + val;
      } else if((val < 0 || val > 9) && broj > 0 ) {
        s += broj;
        broj = 0;
      }
    }

    s += broj;
    broj = 0;

    if(c[strlen(c) - 1] == '!') { break; }
  }

  printf("%d", s);

  return 0;
}