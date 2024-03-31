// 15. Задача
// Од тастатура се внесува колку студенти полагале колоквиум и потоа се внесуваат поените на сите кои полагале.
// Програмата треба да отпечати средна вредност на поените на сите студенти кои имале помалку од 50 поени,
// како и список на студентите со повеќе од 50 поени.
// Исто така програмата да отпечати средна вредност на поените на сите кои положиле со
// најмалку 50 поени инивните освоени поени 
// (редоследот на печатење во двата случаеви треба да биде ист како и редоследот на внесување)
// Максималниот број на студенти што може да се внесат е 1000.

#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int studenti[n], bodovi;
  float padnati, padnatiCounter, polozheni, polozheniCounter;
  padnati = padnatiCounter = polozheni = polozheniCounter = 0;

  for(int i = 0; i < n; i++) {
    scanf("%d", &bodovi);
    studenti[i] = bodovi;

    if(bodovi < 50) {
      padnati += bodovi;
      padnatiCounter++;
    } else if(bodovi >= 50) {
      polozheni += bodovi;
      polozheniCounter++;
    }
  }

  printf("Sredna vrednost na padnati %.2f\n", padnati / padnatiCounter);
  for(int i = 0; i < n; i++) {
    if(studenti[i] < 50) {
      printf("%d ", studenti[i]);
    }
  }

  printf("\nSredna vrednost na polozeni %.2f\n", polozheni / polozheniCounter);
  for(int i = 0; i < n; i++) {
    if(studenti[i] >= 50) {
      printf("%d ", studenti[i]);
    }
  }
}
