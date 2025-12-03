#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

struct joltElement{
    int position;
    int digit;
};

int powerOfTen(long long digits)
{
    int power = 10;


    for(int ii = 1; ii < digits; ii++)
    {
        power *= 10;
    }

    return power;
}


int toDigit(char charIn)
{
    return (int)(charIn - '0');
}

bool compareByDigit(const joltElement &a, const joltElement &b)
{
    if(a.digit == b.digit)
    {
        return a.position < b.position;
    }
    else
    {
        return a.digit > b.digit;
    }
}

void RemoveJoltElement(vector<joltElement> &joltHolder, int position)
{
    joltHolder.erase(remove_if(joltHolder.begin(), joltHolder.end(), [&](joltElement const & jolt) {
        return jolt.position == position;
    }), joltHolder.end());
}


int main()
{
    string line;
    ifstream file("input\\input.txt");

    long long total = 0;
    int highestNum = 0;
    int highestPos = 0;
    int secondHighest = 0;
    int secondPos = 0;
    int digit = 0;
    int position = 0;
    bool stop = false;

    //Go through list and fill a map which has position and value
    //Then sort by value
    //Then go through by value and check if the value has enough numbers after it, if it does then choose that number and then check for next value

    while(getline(file, line))
    {
        vector<joltElement> lineContainer;
        vector<int> joltContainer;

        for(char i : line)
        {
            lineContainer.push_back(joltElement());
            lineContainer[position].digit = toDigit(i);
            lineContainer[position].position = position;
            position++;
        }

        sort(lineContainer.begin(), lineContainer.end(), compareByDigit);

        position = 0;
        int size = lineContainer.size();
        int lastPos = -1;

        for(int ii = 12; ii > 0; ii--)
        {
            for(int jj = 0; jj < size; jj++)
            {
                if(lineContainer[jj].position < size + 1 - ii)
                {
                    if(lineContainer[jj].position > lastPos)
                    {
                        joltContainer.push_back(lineContainer[jj].digit);
                        lastPos = lineContainer[jj].position;
                        RemoveJoltElement(lineContainer, lineContainer[jj].position);
                        break;
                    }
                    
                }
            }
        }

        stringstream result;
        copy(joltContainer.begin(), joltContainer.end(), ostream_iterator<int>(result, ""));
        
        long long resultNum = stoll(result.str());

        total += resultNum;

        
        position = 0;
        
    }

    file.close();
    cout << total << endl;

    return 0;
}
