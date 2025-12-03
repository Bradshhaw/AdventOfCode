#include <sstream>
#include <fstream>
#include "StringSplitter.h"
#include <iostream>

using namespace std;

int numDigits(long long number)
{
    int digits = 0;

    while(number != 0)
    {
        number /= 10;
        digits++;
    }

    return digits;
}

int powerOfTen(long long digits)
{
    int power = 10;


    for(int ii = 1; ii < digits; ii++)
    {
        power *= 10;
    }

    return power;
}

bool checkPattern(long long numIn)
{
    string previousSection;
    string thisSection;

    for(int i = 2; i <= numDigits(numIn); i++)
    {
        if(numDigits(numIn) % i == 0)
        {
            string stringNum = to_string(numIn);
            int numSame = 1;

            for(int j = 0; j < i; j++)
            {
                if(j == 0)
                {
                    previousSection = stringNum.substr(0, numDigits(numIn)/i);
                    stringNum.erase(0, numDigits(numIn)/i);
                }
                else 
                {
                    thisSection = stringNum.substr(0, numDigits(numIn)/i);
                    stringNum.erase(0, numDigits(numIn)/i);

                    if(previousSection == thisSection)
                    {
                        numSame++;
                    }
                    
                    previousSection = thisSection;
                }
            }

            if(numSame == i)
            {
                return true;
            }
        }
    }

    return false; 
}

void PartOne()
{
    ifstream t("input\\input.txt");
    stringstream buffer;
    buffer << t.rdbuf();


    vector<string> dataIn = split(buffer.str(), " ,");
    long long total = 0;

    long long firstNum;
    long long secondNum;
    long long firstHalf;
    long long secondHalf;
    long long ii;

    for(int i = 0; i < dataIn.size(); i++)
    {
        vector<string> splitNumbers = split(dataIn[i], "-");

        firstNum = stoll(splitNumbers[0]);
        secondNum = stoll(splitNumbers[1]);


        for(ii = firstNum; ii <= secondNum; ii++)
        {
            if(numDigits(ii) % 2 == 0)
            {
                firstHalf = ii / (powerOfTen(numDigits(ii)/2));
                secondHalf = ii % (powerOfTen(numDigits(ii)/2));

                if(firstHalf == secondHalf)
                {
                    total += ii;
                    //cout << ii << "\n";
                }
            }
        }

    }

    cout << total;
}

void PartTwo()
{
    ifstream t("input\\input.txt");
    stringstream buffer;
    buffer << t.rdbuf();


    vector<string> dataIn = split(buffer.str(), " ,");
    long long total = 0;

    long long firstNum;
    long long secondNum;
    
    long long ii;

    for(int i = 0; i < dataIn.size(); i++)
    {
        vector<string> splitNumbers = split(dataIn[i], "-");

        firstNum = stoll(splitNumbers[0]);
        secondNum = stoll(splitNumbers[1]);

        for(ii = firstNum; ii <= secondNum; ii++)
        {
            if(checkPattern(ii))
            {
                total += ii;
                //cout << ii << "\n";
            }
        }

    }

    cout << total;
}

int main()
{
    //Read in the file and tokenize based on the commas, split each token on the hyphen and then you can increment between the two numbers.
    //Split the number as a string and then check for equality.
    //Increment through and see if the first half of a string equals the second half of a string.
    //If it does then grab the number it is, if not then move to next in the range.
    //If the length of the string is not divisible by 2, then it doesn't have an ID.

    PartTwo();

    return 0;
}