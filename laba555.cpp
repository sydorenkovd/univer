#include <stdio.h>
#include <stdlib.h>

void delete_equal (int *n0, int *a) {
 //Удаляет из массива повторяющиеся элементы и вычисляет новую размерность n0
 int n=*n0;
 int i=0;
 while (i<n) {
  int j=i+1;
  while (j<n) {
   if (a[i]==a[j]) {
    for (int k=j; k<n-1; k++) a[k]=a[k+1];
    n--;
   }
   else j++;
  }
  i++;
 }
 *n0=n;
}

int find_item(int na,int *a,int b) {
 //Ищет элемент b в массиве a[na] и возвращает его индекс или -1 (не найдено)
 for (int i=0; i<na; i++) if (a[i]==b) return i;
 return -1;
}

int *copy_array (int n, int *a, int *c) {
 //Копирует массив a в новый массив c и возвращает указатель на него
 c=(int *)calloc (n,sizeof(int));
 if (c==NULL) return NULL;
 for (int i=0; i<n; i++) c[i]=a[i];
 return &c[0];
}

int *union_array (int na, int *a, int nb, int *b, int *nc) {
 //Объединение массивов a и b с размерностями na и nb
 //в новый динамический массив (в массив войдут уникальные элементы,
 //присутствующие хотя бы в одном из массивов a,b)
 int *c,i,j;
 if (na<1) {
  if (nb<1) return NULL;
  else {
   delete_equal (&nb,b);
   return copy_array (nb,b,c);
  }
 }
 else if (nb<1) {
  delete_equal (&na,a);
  return copy_array (na,a,c);
 }
 delete_equal(&na,a);
 delete_equal(&nb,b);
 //Вычисляем количество разных элементов в 2 массивах
 int kc=0;
 for (i=0; i<na; i++) if (find_item(nb,b,a[i])!=-1) kc++;
 *nc=na+nb-kc;
 c=(int *)calloc (*nc,sizeof(int));
 if (c==NULL) return NULL;
 //Формируем массив c
 int k=0;
 for (i=0; i<na; i++) c[k++]=a[i];
 for (j=0; j<nb; j++) if (find_item(na,a,b[j])==-1) c[k++]=b[j];
 return c;
}

int *cross_array (int na, int *a, int nb, int *b, int *nc) {
 //Пересечение массивов a и b с размерностями na и nb
 //в новый динамический массив (в массив войдут уникальные элементы,
 //присутствующие в каждом из массивов a,b)
 int *c,i,j;
 if (na<1 || nb<1) return NULL;
 delete_equal(&na,a);
 delete_equal(&nb,b);
 //Вычисляем количество одинаковых элементов в 2 массивах
 *nc=0;
 for (i=0; i<na; i++) if (find_item(nb,b,a[i])!=-1) (*nc)++;
 c=(int *)calloc (*nc,sizeof(int));
 if (c==NULL) return NULL;
 //Формируем массив c
 int k=0;
 for (i=0; i<na; i++) if (find_item(nb,b,a[i])!=-1 && find_item(k,c,a[i])==-1) c[k++]=a[i];
 for (j=0; j<nb; j++) if (find_item(na,a,b[j])!=-1 && find_item(k,c,b[j])==-1) c[k++]=b[j];
 return c;
}

int *diff_array (int na, int *a, int nb, int *b, int *nc) {
 //Разность массивов a и b с размерностями na и nb
 //в новый динамический массив (в массив войдут уникальные элементы,
 //присутствующие в массиве a, но отсутствующие в b)
 int *c,i,j;
 if (na<1) return NULL;
 delete_equal(&na,a);
 if (nb<1) return copy_array (na,a,c);
 delete_equal(&nb,b);
 //Вычисляем количество элементов в массиве a, отсутствующих в b
 *nc=0;
 for (i=0; i<na; i++) {
  int kc=0;
  if (find_item(nb,b,a[i])!=-1) kc++;
  if (kc==0) (*nc)++;
 }
 c=(int *)calloc (*nc,sizeof(int));
 if (c==NULL) return NULL;
 //Формируем массив c
 int k=0;
 for (i=0; i<na; i++) if (find_item(nb,b,a[i])==-1) c[k++]=a[i];
 return c;
}

void print_array (int n,int *a) { //Выводит массив на экран
 printf ("\n");
 for (int i=0; i<n; i++) printf ("%5d ",a[i]);
}

void wait() { //Ждет нажатия клавиши
 printf ("\nPress a key to continue...");
 fflush (stdin); getchar();
}

const int na=6, nb=5; //Размерности массивов a,b
int a[na] = { 4, 4, 2, 5, 3, -1 },
    b[nb] = { 2, 3, 4, 4, 1};
    //Описали множества как массивы

void main () {
 int nc;
 printf ("\na=");
 print_array (na,a);
 printf ("\nb=");
 print_array (nb,b);
 printf ("\nUnion (a,b)=");
 int *c=union_array (na,a,nb,b,&nc);
 print_array (nc,c);
 int nd;
 printf ("\nCross (a,b)=");
 int *d=cross_array (na,a,nb,b,&nd);
 print_array (nd,d);
 int ne;
 printf ("\nDifference (a,b)=");
 int *e=diff_array (na,a,nb,b,&ne);
 print_array (ne,e);
 wait();
}
