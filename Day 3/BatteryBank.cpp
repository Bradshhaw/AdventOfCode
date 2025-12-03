#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


int toDigit(char charIn)
{
    return (int)(charIn - '0');
}


int main()
{
    string line;
    ifstream file("input\\input.txt");

    int total = 0;
    int highestNum = 0;
    int highestPos = 0;
    int secondHighest = 0;
    int secondPos = 0;
    int digit = 0;
    int position = 0;


    while(getline(file, line))
    {
        for(char i : line)
        {
            digit = toDigit(i);
            if(digit > highestNum)
            {
                secondHighest = highestNum;
                secondPos = highestPos;

                highestNum = digit;
                highestPos = position;
            }
            else if(digit > secondHighest)
            {
                secondHighest = digit;
                secondPos = position;
            }
            position++;
        }

        if(highestPos == position - 1)
        {
            highestPos = secondPos;
            highestNum = secondHighest;

            secondHighest = 0;

            for(int i = secondPos; i < position; i++)
            {
                digit = toDigit(line[i]);
                if(digit > secondHighest)
                {
                    secondHighest = digit;
                }
            }
        }
        else
        {
            secondHighest = 0;
            for(int i = highestPos + 1; i < position; i++)
            {
                digit = toDigit(line[i]);
                if(digit > secondHighest)
                {
                    secondHighest = digit;
                }
            }
        }

        

        cout << highestNum << secondHighest << endl;

        total += ((10*highestNum) + secondHighest);

        highestNum = 0;
        secondHighest = 0;
        highestPos = 0;
        secondPos = 0;
        position = 0;
    }

    file.close();
    cout << total << endl;

    return 0;
}
