#include <stdio.h>
#include <string.h>
int main (void)
{
    char fio [15];  /* ������� */
    char dline [] = {"-------------------------------------"};
    long plata;     /* ���������� ����� */
    int godr;       /* ��� �������� */
    int swin;       /* ��������� ����� ����� */
    FILE *fpin,*fpout;  /* ��������� �� ����������� ������ */
    fpin = fopen ("�������.txt", "r"); /* ��������  ����� 1 */
    fpout = fopen ("�����.txt", "w");/* �������� ����� 2 */
    for (;;)        /* ������ ������ �� ����� 1 */
    {
        swin = fscanf (fpin, "%s %ld", fio, &plata);
        if (swin == EOF)     /* ����� �� ����� */
           break;            /* �� ����� ����� */
        printf ("\nLast name: %s. Enter birth year: ",fio);
        scanf ("%d",&godr); /* ������ ���� �������� */
        fprintf(fpout,"%s %ld %d\n",fio,plata,godr);/* ����� � ���� 2 */
    }
    printf ("\nThe list of staff is ended");
    fclose(fpin);  /* �������� ����� 1 */
    fclose(fpout); /* �������� ����� 2 */
    fpin = fopen ("�����.txt", "r"); /* �������� ����� 2 ��� ������ */
    printf ("\n\n\n    Last name       Salary Birth year\n%s",dline);
    for (;;)    /* ����� �� ������� ������ �� ����� 2 */
    {
        swin = fscanf (fpin, "%s %ld %d", fio, &plata, &godr);
        if (swin == EOF)   /* ����� �� ����� */
            break;         /* �� ����� ����� */
        printf("\n%-15s%10ld%8d",fio,plata,godr);
    }
    printf ("\n%s",dline);
    fclose (fpin);    /* �������� ����� 1 */
    getchar();        /* ���� ������� */
    getchar();        /* ���� ������� */
 	 return 0;         /* ����� �� ��������� */
}





