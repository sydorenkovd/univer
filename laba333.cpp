#include <stdio.h>
#include <string.h>
 
int main()
{
   char str[80];
   char word[] = "Kon";
   int i, j, l;
 
   printf("Vvedite stroku: ");
   fgets(str, 80, stdin);
   if (strstr(str, word))
   {
      l = strstr(str, word) - str;
      for (j = 0; j <= strlen(word); j ++)
         for (i = l; i < strlen(str); i++)
         {
            str[i] = str[i+1];
         }
      printf("%s\n", str);
   }
   else
       printf("Строка не содержит нужного слова\n");
}
