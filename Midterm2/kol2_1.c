// 1. Задача
// Дадена е текстуална датотека text.txt.
//Да се избројат и испечатат сите последнователни појавувања на соседни самогласки во датотеката.
//Појавата на големи и мали букви да се игнорира. Пронајдените парови самогласки да се испечатат на екран,
//секој во нов ред со мали букви. Потоа во нов ред се печати бројот на појавувања на паровите самогласки.
//
//Пример: за датотеката:
//IO is short for Input Output
//medioio medIo song
//излез:
//io
//ou
//io
//oi
//io
//io
//6

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void writeToFile() {
  FILE *f = fopen("text.txt", "w");
  char c;
  while((c = getchar()) != '#') {
    fputc(c, f);
  }
  fclose(f);
}

int main() {
  writeToFile();

  // Vasiot kod zapocnuva od tuka
  FILE *f;

  if(!(f = fopen("text.txt", "r"))) return -1;

  char a = fgetc(f), b;
  int ct = 0;

  while((b = fgetc(f)) != EOF) {
      a = tolower(a);
      b = tolower(b);
      if(isVowel(a) && isVowel(b)) {
          printf("%c%c\n", a, b);
          ct++;
      }

      a = b;
  }

  printf("%d", ct);

  return 0;
}
