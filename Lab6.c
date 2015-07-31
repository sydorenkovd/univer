#include <stdio.h>
#include <string.h>
int main (void)
{
    char fio [15];  /* Фамилия */
    char dline [] = {"-------------------------------------"};
    long plata;     /* Заработная плата */
    int godr;       /* Год рождения */
    int swin;       /* Индикатор конца файла */
    FILE *fpin,*fpout;  /* Указатели на дескрипторы файлов */
    fpin = fopen ("фамилии.txt", "r"); /* Открытие  файла 1 */
    fpout = fopen ("днюхи.txt", "w");/* Открытие файла 2 */
    for (;;)        /* Чтение данных из файла 1 */
    {
        swin = fscanf (fpin, "%s %ld", fio, &plata);
        if (swin == EOF)     /* Выход из цикла */
           break;            /* по концу файла */
        printf ("\nLast name: %s. Enter birth year: ",fio);
        scanf ("%d",&godr); /* Чтение года рождения */
        fprintf(fpout,"%s %ld %d\n",fio,plata,godr);/* Вывод в файл 2 */
    }
    printf ("\nThe list of staff is ended");
    fclose(fpin);  /* Закрытие файла 1 */
    fclose(fpout); /* Закрытие файла 2 */
    fpin = fopen ("днюхи.txt", "r"); /* Открытие файла 2 для чтения */
    printf ("\n\n\n    Last name       Salary Birth year\n%s",dline);
    for (;;)    /* Вывод на дисплей данных из файла 2 */
    {
        swin = fscanf (fpin, "%s %ld %d", fio, &plata, &godr);
        if (swin == EOF)   /* Выход из цикла */
            break;         /* по концу файла */
        printf("\n%-15s%10ld%8d",fio,plata,godr);
    }
    printf ("\n%s",dline);
    fclose (fpin);    /* Закрытие файла 1 */
    getchar();        /* Ввод символа */
    getchar();        /* Ввод символа */
 	 return 0;         /* Выход из программы */
}





