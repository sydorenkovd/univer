#include <iostream> 
#include <string>
using namespace std; 
int main() 
{ 
    string str = "Real Madrid Champions of Spain of"; // исходная строка
    string asd = "of";  // что удаляем
    int size = 2;       // количество
    int n;              // позиция удаляемого
    for ( int i = 0; i < size; i++) 
    {
       n = str.find(asd);   // ищем
       str.erase(n, asd.size());  // удаляем
    } 
 cout << str << endl;
}
