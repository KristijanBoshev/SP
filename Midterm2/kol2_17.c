// 17. Задача
// Од тастатура се внесуваат димензиите на една матрица (m,n <= 100), а потоа и елементите од матрицата.
// Да се трансформира матрицата така што средниот елемент во секоја редица ќе се замени со разликата
// (по апсолутна вредност) на сумата на елементите во првата половина од редицата и
// сумата на елементите во втората половина на редицата. 
// Ако матрицата има парен број колони, се менува вредноста на средните два елемента.
// Средниот/те елемент/и влегува/ат во сумите (при непарен број на колони,
// средниот елемент влегува во двете суми!).
// Да се испечати на екран променетата матрица.

#include <stdio.h>

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  int matrica[n][m];

  for(int i = 0; i < n; i++) {
    int s1 = 0, s2 = 0;
    for(int j = 0; j < m; j++) {
      scanf("%d", &matrica[i][j]);
      int sr = (m / 2);

      if(j < sr) { s1 += matrica[i][j]; }

      sr = m % 2 == 0 ? (m / 2) - 1 : (m / 2);
      if(j > sr) { s2 += matrica[i][j]; }

      int razlika = s1 - s2 >= 0 ? s1 - s2 : s2 - s1;

      if(m % 2 == 0) { matrica[i][sr] = matrica[i][sr + 1] = razlika; }
      else { matrica[i][sr] = razlika; }
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      printf("%d ", matrica[i][j]);
    }
    printf("\n");
  }

  return 0;
}
