#include <iostream>
#include <vector>
 
int main()
{
    std::string str;
    std::cout << "Type some text: ";
    getline(std::cin, str);
    
    char* chStr = new char[str.size() + 1];
    std::strcpy(chStr, str.c_str());
    char* p = std::strtok(chStr, " ");
    std::vector<std::string> arr;
    while(p != NULL)
    {
        arr.push_back(p);
        p = strtok(NULL, " ");
    }
    
    std::cout << std::endl;
    int counter = 0;
    
    for(int i = 0; i < arr.size(); i++)
    {
        std::string temp = arr[i];
        for(int j = 0; j < arr.size(); j++)
        {
            if(arr[j] == temp)
            {
                counter++;
                if(counter > 1)
                {
                    arr.erase(arr.begin() + j);
                    j--;
                }
            }
        }
        std::cout << temp << " repeats " << counter << " times\n";
        counter = 0;
    }
    
    std::cout << std::endl;
    for(int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    
    std::cout << "\n\n";
    
    system("pause");
    return 0;
}
