// 2.1 - 5
// Еден елемент се заматува ако се најде аритметичка средина на елементот и сите негови соседи.
// Сосед на еден елемент се сите елементи кои припаѓаат на матрицата и се  околу истиот елемент (хоризонтално, вертикално и дијагонално). 
// Во датотеката input.txt е сместена матрица од реални броеви (3 < n,m < 50).
// Во првиот ред се дефинирани бројот на редици и колони на матрицата и во секој преостанат ред е внесен еден ред од матрицата.
// По читањето на матрицата, од стандарден влез се внесуваат и 2 пара координати на матрицата (ред и колона)
// кои го репрезентираат горниот-лев и долниот-десен елемент од регионот.
// Потребно е да генеирате нова матрица во која ќе ги заматите сите елементи кои припаѓаат на регионот. 
// Новодобиената матрица, во истиот формат, треба да се запише во датотеката output.txt.

#include <stdio.h>
#include <math.h>

#define MAX 50

void printFile() {

    FILE *f=fopen("output.txt","r");
    char line[1000];
    while(!feof(f)){
        fgets(line,1000,f);
        if (feof(f))
            break;
        printf("%s",line);
    }
    fclose(f);
}

void wtf(){
    FILE *f=fopen("input.txt","w");

    int row,column,i,j;
    float el;
    scanf("%d %d", &row, &column);

    fprintf(f,"%d %d\n",row, column);

    for (i=0; i<row; ++i){
        for (j=0; j<column; ++j){
            scanf("%f", &el);
            fprintf(f, "%.2f ", el);
        }
        fputc('\n',f);
    }
    fclose(f);

    return;
}

double funkcija(float mat[MAX][MAX], int x, int y, int n, int m) {
    double s = 0;
    int ct = 0;

    for(int i = x - 1; i <= x + 1; i++) {
        for(int j = y - 1; j <= y + 1; j++) {
            if(i < 0 || j < 0 || i >= n || j >= m) continue;
            ct++;
            s += mat[i][j];
        }
    }
    
    return s / ct;
}

int main(){
    wtf();
    // Your code starts here!
    int n, m, x1, y1, x2, y2;
    float matrica[MAX][MAX];
    float kopija[MAX][MAX];

    FILE *fi = fopen("input.txt", "r");

    fscanf(fi, "%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            fscanf(fi, "%f", &matrica[i][j]);
            kopija[i][j] = matrica[i][j];
        }
    }

    fclose(fi);

    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    for(int i = x1; i <= x2; i++) {
        for(int j = y1; j <= y2; j++) {
            kopija[i][j] = funkcija(matrica, i, j, n, m);
        }
    }

    FILE *fo = fopen("output.txt", "w");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            fprintf(fo, "%.2f ", kopija[i][j]);
        }
        fprintf(fo, "\n");
    }

    fclose(fo);

    // Your code ends here!
    printFile();

    return 0;
}