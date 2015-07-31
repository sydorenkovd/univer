#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
 
#ifndef NULL
#define NULL  0
#endif
 
typedef const char*  cchar;
 
 
 struct account  {
   //   int visual;
   //   int number;
     char name[9];
     char surname[12];
  //   char nickname[9];
  //   char hometown[11];
  //   char residence[12];
     int  birthday;
     int  month;
     int  year;
     struct account *nextPtr;
 };
 
 // эту функцию - добавления в список данных  можешь удалить у тебя наверное свои есть
 void  add(struct account** plist, cchar iname, cchar surname, int day, int mon, int year) {
      if(! plist) {
          (*plist) = (struct account*) malloc(sizeof(struct account));
 
          strcpy((*plist)->name, iname);
          strcpy((*plist)->surname, surname);
          (*plist)->birthday = day;
          (*plist)->month    = mon;
          (*plist)->year     = year;
 
          (*plist)->nextPtr  = NULL;
      } else {
          struct account*  ptr = (struct account*) malloc(sizeof(struct account));
 
          strcpy(ptr->name, iname);
          strcpy(ptr->surname, surname);
          ptr->birthday = day;
          ptr->month    = mon;
          ptr->year     = year;
 
          ptr->nextPtr = *plist;
          *plist = ptr;
      }
 
 }
 
 
 
 long  timestamp(struct account* obj) {
        return (obj->month * 30) + (obj->year * 12 * 30) + obj->birthday;
 }
 
 
 typedef enum enum_sort{
    sort_family = 0, sort_date = 1
 };
 
 // сортировка по-фамилиям и по-дате
 void  sort_list(struct account*  plist, enum enum_sort type) {
        struct account*  first;
        struct account*  last;
        int    id, tmp;
        char   surname[12];
        char   name[9];
        while(1) {
               id = 0;
               first = plist;
               last  = plist->nextPtr;
               for( ; last != NULL ; last = last->nextPtr, first = first->nextPtr) {
 
                   if( (tolower(first->surname[0]) > tolower(last->surname[0]) && type == sort_family) ||
                        (timestamp(first) > timestamp(last) && type == sort_date) ) {
 
                          strcpy(surname, first->surname);
                          strcpy(first->surname, last->surname);
                          strcpy(last->surname, surname);
 
                          strcpy(name, first->name);
                          strcpy(first->name, last->name);
                          strcpy(last->name, name);
 
                          tmp               = first->birthday;
                          first->birthday = last->birthday;
                          last->birthday = tmp;
 
                          tmp          = first->month;
                          first->month = last->month;
                          last->month  = tmp;
 
                          tmp          = first->year;
                          first->year = last->year;
                          last->year  = tmp;
 
                          // по-такой аналогии отсортируй оставшиеся поля в структуре
 
                          id |= 1;
                   }
               }
               if(! id)
                   break;
 
        };
 }
 
 
 
 
int main(void)
{
     struct account* iter = NULL;
     struct account* list = NULL;
 
     // добавляем в список людей
     add(&list, "Sara", "Cobra", 1, 1, 2000);
     add(&list, "Bob", "Viking", 12, 2, 1999);
     add(&list, "Make", "Zero", 22, 1, 1991);
     add(&list, "Alex", "Zorro", 1, 2, 1990);
     add(&list, "Tom", "Alien", 1, 8, 1998);
     add(&list, "Jerry", "Based", 2, 7, 1989);
     add(&list, "Vasy", "Ultra", 3, 3, 1992);
     add(&list, "Warrior", "SWAT", 12, 4, 1993);
     add(&list, "Ninja", "Apache", 28, 11, 1994);
     add(&list, "Oscar", "York", 1, 1, 1982);
 
 
 
     // сортируем список по-фамилиям
     sort_list(list, sort_family);
 
 
     // выводим отсортированный список
     iter = list;
     while(iter != NULL) {
          printf("person: %s   %s\t date: %d.%d.%d\n", iter->name, iter->surname,
          iter->birthday, iter->month, iter->year);
         iter = iter->nextPtr;
     }
 
 
     // теперь сортируем по-дате
     sort_list(list, sort_date);
 
     puts("\n");
 
     // смотрим как отсортировалась по-дате
     iter = list;
     while(iter != NULL) {
          printf("person: %s   %s\t date: %d.%d.%d\n", iter->name, iter->surname,
          iter->birthday, iter->month, iter->year);
         iter = iter->nextPtr;
     }
 
 
 
     // чистим список
     while(list != NULL) {
          iter = list;
          list = list->nextPtr;
          free(iter);
          iter = NULL;
     }
     list = NULL;
 
   getchar();
   return 0;
}
