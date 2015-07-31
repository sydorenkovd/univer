#include<iostream>
#include <string>
 #include <stdlib.h>
using namespace std;
 
struct Spisok
{
    int x;
    Spisok *Next;
    Spisok *prev;
};
 
Spisok *PLast[10],*PFirst[10];
int kol=0;
bool proverka(int x,Spisok *First)
{
    bool b=true;
    Spisok *p;
    p=First;
    while (p!=NULL)
    {
        if (p->x==x)
        {
            b=false;
            break;
        }
        p=p->prev;
    }
    return b;
}
void dobav(int x, Spisok **Last, Spisok **First)
{
    if (proverka(x,*First)==true)
    {
    Spisok *p;
    p=new Spisok;
    p->x=x;
    p->Next=NULL;
    p->prev=NULL;
    if (*Last==NULL)
    {
        *Last=p;
        *First=p;
    }
    else 
    {
        (*Last)->prev=p;
        p->Next=*Last;
        *Last=p;
    }
    }
}
 
void dob(Spisok **Last, Spisok **First)
{
    int n,k;
    cout<<"Введите кол-во чисел  ";
    cin>>n;
    cout<<endl;
    cout<<"Добавьте числa во множество "<<endl;
    for (int i=0; i<n; ++i)
    {
        cin>>k;
        dobav(k,Last,First);
    }
}
void dob1()
{
    kol++;
    PLast[kol-1]=NULL;
    PFirst[kol-1]=NULL;
    dob(&PLast[kol-1], &PFirst[kol-1]);
    cout<<"Добавлено! "<<endl;
}
 
void Print(Spisok *First)
{
    Spisok *p;
    p=First;
    if (p==NULL)
    {
        cout<<"Нет множества! "<<endl;
    }
    else
        while (p!=NULL)
        {
            
                cout<<p->x<<endl;
                p=p->prev;
            
        }
}
void Print1()
{
    int k=0;
    cout<<"Введите номер множества ";
    cin>>k;
    cout<<endl;
    if (k<=kol)
    {
        Print(PFirst[k-1]);
    }
    else
        cout<<"Множества не существует! ";
}
 
 
void obMn1(Spisok *Mn1, Spisok *Mn2)
{
    Spisok *p;
    p=new Spisok;
    kol++;
    PLast[kol-1]=NULL;
    PFirst[kol-1]=NULL;
    p=Mn1;
    while (p!=NULL)
        {
            dobav(p->x, &PLast[kol-1],&PFirst[kol-1]);
            p=p->prev;
        }
    p=Mn2;
    while (p!=NULL)
        {
            dobav(p->x, &PLast[kol-1],&PFirst[kol-1]);
            p=p->prev;
        }
    
}
void obMn()
{
    int k1=0,k2=0;
    cout<<"№ первого множества ";
    cin>>k1;
    cout<<"№ второго множества ";
    cin>>k2;
    cout<<endl;
    if (k1<=kol && k2<=kol)
    {
        obMn1(PFirst[k1-1],PFirst[k2-1]);
        cout<<"Объединение выполнено! № множества "<<kol<<endl;
    }
}
bool proverka2(int x,Spisok *First)
{
    bool b=false;
    Spisok *p;
    p=First;
    while (p!=NULL)
    {
        if (p->x==x)
        {
            b=true;
            break;
        }
        p=p->prev;
    }
    return b;
}
void prMn1(Spisok *Mn1, Spisok *Mn2)
{
    int x;
    Spisok *p;
    kol++;
    PLast[kol-1]=NULL;
    PFirst[kol-1]=NULL;
    p=Mn1;
    while (p!=NULL)
        {
            if (proverka2((p->x),Mn2)==true)
            {
                dobav(p->x, &PLast[kol-1],&PFirst[kol-1]);
                
            }
            p=p->prev;
        }
}
void prMn()
{
    int k1=0,k2=0;
    cout<<"№ первого множества ";
    cin>>k1;
    cout<<"№ второго множества ";
    cin>>k2;
    cout<<endl;
    if (k1<=kol && k2<=kol)
    {
        prMn1(PFirst[k1-1],PFirst[k2-1]);
        cout<<"Пересечение выполнено! № множества "<<kol<<endl;
    }
}
int main()
{
    setlocale(LC_ALL,"Russian");
    typedef void(*pzad)();
    pzad mas[4];
    cout<<"Меню: "<<endl;
    cout<<"1.Создание множества"<<endl;
    cout<<"2.Печать множества"<<endl;
    cout<<"3.Объединение множеств"<<endl;
    cout<<"4.Пересечение множеств"<<endl;
    mas[0]=dob1;
    mas[1]=Print1;
    mas[2]=obMn;
    mas[3]=prMn;
    int m=0;
    while (m<5) 
    {
        cout<<endl<<endl<<"Введите номер: ";
        cin>>m;
        if (m<5) {mas[m-1]();};
    }
    system("pause");
    return 0;
}
