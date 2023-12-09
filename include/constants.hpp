#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
using namespace std;

struct studentInfo
{
    string name;
    int id;
    int batch;
};

struct assessment
{
    float results[7];
};

const string courses[7] = {
    "Anthropology", "C++", "Civics", "Emerging", "English", "Entrepreneur",
    "Maths"
};
const int courseCrHr[7] = {2,3,2,3,3,3,3};
const std::string assessmentTypes[3] = {"Mid", "Assignment", "Final"};
const int assessmentMaxPoint[3] = {30, 20, 50};

#endif
