#ifndef GPA_MODULE_H
#define GPA_MODULE_H

#include<iostream>
#include<string>
#include"constants.hpp"
using namespace std;


string totalToGrade(float total)
{
    string grade;

    if(total >= 90)
        grade = "A+";
    else if(total <= 89.99 && total >= 85)
        grade = "A";
    else if(total <= 84.99 && total >= 80)
        grade = "A-";
    else if(total <= 79.99 && total >= 75)
        grade = "B+";
    else if(total <= 74.99 && total >= 70)
        grade = "B";
    else if(total <= 69.99 && total >= 65)
        grade = "B-";
    else if(total <= 64.99 && total >= 60)
        grade = "C+";
    else if(total <= 59.99 && total >= 55)
        grade = "C";
    else if(total <= 54.99 && total >= 50)
        grade = "C-";
    else if(total <= 49.99 && total >= 45)
        grade = "D";
    else if(total <= 44.99 && total >= 40)
        grade = "D";
    else
        grade = "F";

    return grade;
}


float gradeToPt(string grade)
{
    float Pt;

    if(grade == "A+" || grade == "A")
        Pt = 4;
    else if (grade == "B+")
        Pt = 3.75;
    else if (grade == "B+")
        Pt = 3.5;
    else if (grade == "B")
        Pt = 3;
    else if (grade == "B-")
        Pt = 2.75;
    else if (grade == "C+")
        Pt = 2.5;
    else if (grade == "C")
        Pt = 2;
    else if (grade == "C-")
        Pt = 1.75;
    else if (grade == "D")
        Pt = 1;
    else if (grade == "F")
        Pt = 0;

    return Pt;
}


float getGpa(float courseTotalResults[7])
{
    float totalQPt,gpa;
    int totalCrHrs = 19;

    for(int i=0;i<7;i++)
    {
        string grade = totalToGrade(courseTotalResults[i]);
        int crHr = courseCrHr[i];
        float pt = gradeToPt(grade);
        
        totalQPt += (pt*crHr);
    }

    gpa = totalQPt/totalCrHrs;

    return gpa;
}


#endif