#include <stdio.h>
struct tag_people {
char nam
e[100];
char job[100];
int old;
};
void show_struct(struct tag_people man);
struct tag_people get_struct();
int main()
{
struct tag_people person;
person = get_struct();
show_struct(person);
return 0;
}
51
void show_struct(struct tag_people man)
{
printf(����: %s\n�,man.name);
printf(����������: %s\n�,man.job);
printf(��������: %d\n�,man.old);
}
struct tag_people get_struct()
{
struct tag_people man;
scanf(�%s�,man.name);
scanf(�%s�,man.job);
scanf(�%d�,man.old);
return
man
;
}
