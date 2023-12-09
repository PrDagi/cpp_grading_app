#ifndef HELPER_MODULE_H
#define HELPER_MODULE_H

#include<iostream>
#include<iomanip>
#include<string>
#include<limits>

using namespace std;


string repeatStr(string repeatableStr, int repeatCount)
{
    string repeatedStr;
    for(int i=1;i<repeatCount;i++)
    {
        repeatedStr += repeatableStr;
    }

    return repeatedStr;
}

//d=double_round_border,s=single
void tableHeadLine(string headLineText,int width ,string precedingChar,char style)
{
    string rightCloseTag,LeftCloseTag,verticalArrow,horizontalArrow;

    switch (style)
    {
        case 'd':
            rightCloseTag = "╔";
            LeftCloseTag = "╗";
            verticalArrow = "║";
            horizontalArrow = "═";
            break;
        case 's':
            rightCloseTag = "┌";
            LeftCloseTag = "┐";
            horizontalArrow = "─";
            verticalArrow = "│";
            break;
    }

    cout << precedingChar << rightCloseTag << repeatStr(horizontalArrow,width) << LeftCloseTag << "\n";
    cout << precedingChar << verticalArrow << "  " << YELLOW << headLineText << RESET << setw(width - headLineText.length()) << verticalArrow <<"\n";
    cout << precedingChar << verticalArrow << repeatStr("─",width) << verticalArrow << "\n";
}


void tableFooter(int width, string precedingChar,char style)
{
    string rightCloseTag,LeftCloseTag,horizontalArrow;

    switch (style)
    {
        case 'd':
            rightCloseTag = "╚";
            LeftCloseTag = "╝";
            horizontalArrow = "═";
            break;
        case 's':
            rightCloseTag = "└";
            LeftCloseTag = "┘";
            horizontalArrow = "─";
            break;
    }
    cout << precedingChar << rightCloseTag << repeatStr(horizontalArrow,width) << LeftCloseTag;
}

bool invalidInput()
{
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        return true;
    }

    return false;
}

#endif