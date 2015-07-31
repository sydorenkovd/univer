#include <stdio.h>
#include <string.h>
 
int main ()
{
  char szKey[] = "apple\n";
  char szInput[80];
  do {
     printf ("Guess my favorite fruit? ");
     fgets (szInput,80,stdin);
  } while (strcmp (szKey,szInput) != 0);
  puts ("Correct answer!");
  return 0;
}
