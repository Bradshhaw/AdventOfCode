#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


int main()
{
    string line;
    ifstream file("input\\input.txt");

    int dialNum = 50;
    int previousNum = 50;
    int zeroCounter = 0;

    int increment = 0;

    while(getline(file, line))
    {
        previousNum = dialNum;
        char direction = line[0];
        int magnitude = stoi(line.substr(1));

        if(direction == 'L')
        {
            increment = -1;
        }
        else
        {
            increment = 1;
        }

        for(int i = 0; i < magnitude; i++)
        {
            dialNum += increment;

            if(dialNum > 99)
            {
                dialNum = 0;
            }
            else if(dialNum < 0)
            {
                dialNum = 99;
            }
        }

        if(dialNum == 0)
        {
            zeroCounter++;
        }

    }

    file.close();

    cout << zeroCounter;

    return 0;
}


