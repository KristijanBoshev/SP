// 13. Задача
// Од тастатура се внесува број на студенти кои ќе полагаат колоквиум,
// а потоа и индексите (цели броеви) на сите студенти кои ќе полагаат колоквиум.
// Програмата треба да ги подели студентите во три групи:
// - студенти со индекси кои завршуваат на цифрата 0, 1 и 2;
// - студенти со индекси кои завршуваат на цифрата 3, 4, 5;
// - студенти со индекси кои завршуваат на цифрата 6, 7, 8, 9.
//
// Програмата треба да ги испечати индексите за секоја група, во истиот редослед како што биле внесени.
// Максималниот број на студенти што може да се внесат е 1000.

#include <stdio.h>

int lastDigit(int n, int d) {
  return (n % 10) == d;
}

int main() {
  int n;
  scanf("%d", &n);

  int studenti[n];
  for(int i = 0; i < n; i++) {
    scanf("%d", &studenti[i]);
  }

  printf("Grupa 1\n");
  for(int i = 0; i < n; i++) {
    if(lastDigit(studenti[i], 0) || lastDigit(studenti[i], 1) || lastDigit(studenti[i], 2)) {
      printf("%d ", studenti[i]);
    }
  }

  printf("\nGrupa 2\n");
  for(int i = 0; i < n; i++) {
    if(lastDigit(studenti[i], 3) || lastDigit(studenti[i], 4) || lastDigit(studenti[i], 5)) {
      printf("%d ", studenti[i]);
    }
  }

  printf("\nGrupa 3\n");
  for(int i = 0; i < n; i++) {
    if(lastDigit(studenti[i], 6) || lastDigit(studenti[i], 7) || lastDigit(studenti[i], 8) || lastDigit(studenti[i], 9)) {
      printf("%d ", studenti[i]);
    }
  }

  return 0;
}
