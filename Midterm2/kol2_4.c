// 4. Задача
// Еден елемент од матрица ја дели матрицата на 4 квадранти (прикажани на сликата).
// Притоа самиот елемент кој ја дели матрицата припаѓа во четвртиот квадрант.
// Од стандарден влез се внесува матрица со димензии NxM (1 <= N, M < 100).
// Потоа се внесуваат два броеви кои претставуваат индекси на еден елемент од матрицата.
//
// Да се најдат сумите на секој од квадрантите и да се испечатат на стандарен излез.
// Притоа се печати сумата за првиот квадрант, па за вториот, па третиот и на крај за четвртиот.
// Доколку не може да се креира квадрант, тогаш за сумата на тој квадрант треба да се испечати 0.

#include <stdio.h>

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  int matrica[n][m];

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      scanf("%d", &matrica[i][j]);
    }
  }

  int x, y;
  scanf("%d %d", &x, &y);

  int prv, vtor, tret, chetvrt;
  prv = vtor = tret = chetvrt = 0;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      // prv kvadrant
      if(i < x && j >= y) { prv += matrica[i][j]; }

      // vtor kvadrant
      if(i < x && j < y) { vtor += matrica[i][j]; }

      // tret kvadrant
      if(i >= x && j < y) { tret += matrica[i][j]; }

      // chetvrt kvadrant
      if(i >= x && j >= y) { chetvrt += matrica[i][j]; }
    }
  }

  printf("%d %d %d %d", prv, vtor, tret, chetvrt);

  return 0;
}