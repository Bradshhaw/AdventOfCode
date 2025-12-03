#include "StringSplitter.h"

bool is_delimiter(char value, const std::string& delims)
{
    bool delimiter = false;
    for(auto d : delims)
    {
        if(d == value)
        {
            delimiter = true;
        }
    }
    return delimiter;
}

std::vector<std::string> split(std::string str, std::string delims)
{
    std::vector<std::string> output;

    while(str.size() > 0)
    {
        if(is_delimiter(str[0], delims))
        {
            output.push_back("");
            str = str.substr(1);
        }
        else
        {
            int i = 1;
            while(i < str.size() && !is_delimiter(str[i], delims))
            {
                i++;
            }
            output.emplace_back(str.begin(), str.begin() + i);
            if(i + 1 < str.size())
            {
                str = str.substr(i + 1);
            }
            else
            {
                str = "";
            }
        }
    }
    
    return output;
}