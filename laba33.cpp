#include<iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
 
int main()
{
    string input = "String String String objects objects are are var a special special type type of of container,";
    string temp, output;// для слова из строки
    vector<string> vec;// список слов из строки
    stringstream ss;// поток для строк
    ss<<input;// помещаем строку в поток
    while (ss>>temp)// извлекаем строку по слову из потока
        vec.push_back(temp);// помещаем слова в список
    int i = 0;
    for (; i<vec.size() - 1; i++)// выводим слова из списка
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
