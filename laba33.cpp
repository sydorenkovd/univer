#include<iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
 
int main()
{
    string input = "String String String objects objects are are var a special special type type of of container,";
    string temp, output;// ��� ����� �� ������
    vector<string> vec;// ������ ���� �� ������
    stringstream ss;// ����� ��� �����
    ss<<input;// �������� ������ � �����
    while (ss>>temp)// ��������� ������ �� ����� �� ������
        vec.push_back(temp);// �������� ����� � ������
    int i = 0;
    for (; i<vec.size() - 1; i++)// ������� ����� �� ������
    {
        if (vec[i] != vec[i+1])
            output += vec[i] + " ";
    }
    output += vec[i];
    cout<<"INPUT:  "<<input<<endl;
    cout<<"\n============================\n\n";
    cout<<"OUTPUT:  "<<output<<endl<<endl;;
    
    return 0;
}
