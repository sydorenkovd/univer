#include <iostream> 
#include <string>
using namespace std; 
int main() 
{ 
    string str = "Real Madrid Champions of Spain of"; // �������� ������
    string asd = "of";  // ��� �������
    int size = 2;       // ����������
    int n;              // ������� ����������
    for ( int i = 0; i < size; i++) 
    {
       n = str.find(asd);   // ����
       str.erase(n, asd.size());  // �������
    } 
 cout << str << endl;
}
