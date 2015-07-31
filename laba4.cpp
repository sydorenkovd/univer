#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
/////////////////////////////////////////////////////////////////////////////////////
typedef std::string         T_str;
typedef std::vector<T_str>  T_strings;
/////////////////////////////////////////////////////////////////////////////////////
void  print_unique_words(const T_str&  s)
{
    std::istringstream  ssin(s);      
    std::istream_iterator<std::string>  ssin_beg(ssin), ssin_end;
    T_strings  words;       
    std::copy(ssin_beg, ssin_end, std::back_inserter(words));
 
    for(T_strings::iterator  word_it = words.begin(); word_it != words.end(); )        
    {
        T_strings::iterator  find_word_it 
            = std::find(word_it + 1, words.end(), *word_it);
        if(find_word_it != words.end())        
        {
            words.erase(find_word_it);    
        }
        else
        {
            ++word_it;
        }
    }
    
    std::copy(words.begin(), words.end(), 
              std::ostream_iterator<std::string>(std::cout, " "));    
}
/////////////////////////////////////////////////////////////////////////////////////
int main()
{
    std::locale::global(std::locale(""));   
    std::cout << "Введите предложение с повторяющимися словами: " 
              << std::endl;
    T_str  s;
    std::getline(std::cin, s);
    std::cout << "Предложение с удаленными дублями слов:"
              << std::endl;
    print_unique_words(s);
    std::cout << std::endl;
}
