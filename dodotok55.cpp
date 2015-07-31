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
printf(У»м€: %s\nФ,man.name);
printf(Уѕрофесси€: %s\nФ,man.job);
printf(У¬озраст: %d\nФ,man.old);
}
struct tag_people get_struct()
{
struct tag_people man;
scanf(У%sФ,man.name);
scanf(У%sФ,man.job);
scanf(У%dФ,man.old);
return
man
;
}
