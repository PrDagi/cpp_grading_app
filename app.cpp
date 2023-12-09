#include<iostream>
#include"include/constants.hpp"
#include"include/style_module.hpp"
#include"include/gpa_module.hpp"
#include"include/helper_module.hpp"
using namespace std;


studentInfo studentInfoForm();
assessment assessmentForm(string studentName);
void studentInfoSec(string name, string id);
void studentGradeSec(string courseGrade[7], float gpa);
void studentResult(studentInfo studentInfoFormData, assessment assessmentFormData);


void gradingApp()
{
    studentInfo studentInfoFormData = studentInfoForm();
    assessment assessmentFormData = assessmentForm(studentInfoFormData.name);
    studentResult(studentInfoFormData,assessmentFormData);
}

int main()
{
    while(true)
    {
        gradingApp();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;

}

studentInfo studentInfoForm()
{
    studentInfo formData;

    // Header
    cout << "\n";
    tableHeadLine("+Fill Out Student Info Form", 100, "", 'd');

    // Full Name input
    bool isNameError = false;
    cout << "║   "<<GREEN<<"Full Name: "<<RESET;
    getline(cin, formData.name);
    do
    {
        if (invalidInput())
        {
            isNameError = true;
            cout << "║    └─"<< RED <<"Invalid Input Type, please enter only alphabet characters" << RESET<<"\n";
        }
        if (isNameError)
        {
            cout << "║   "<<GREEN<<"Full Name: "<<RESET;
            getline(cin, formData.name);
        }
    } while (isNameError);

    // Id input
    bool isIdError = false;
    cout << "║   "<<GREEN<<"Id: "<<RESET;
    cin >> formData.id;
    do
    {
        if (invalidInput())
        {
            isIdError = true;
            cout << "║    └─"<<RED<<"Invalid Input Type, please enter only alphabet characters" << RESET<<"\n";
        }
        else if (to_string(formData.id).length() != 4 && to_string(formData.id).length() != 3)
        {
            isIdError = true;
            cout << "║    └─"<<RED<<"Id must have 3 or 4 characters of int" << RESET<<"\n";
        }
        else
        {
            isIdError = false;
        }
        if (isIdError)
        {
            cout << "║   "<<GREEN<<"Id: "<<RESET;
            cin >> formData.id;
        }
    } while(isIdError);

    // Footer
    tableFooter(100, "", 'd');
    cout << "\n";

    return formData;
}


assessment assessmentForm(string studentName)
{
    bool isTheirFormError = false;
    float result[3];
    assessment formData;

    // header
    cout << "\n";
    tableHeadLine("+Add Assessment Result Of Student "+studentName,100,"",'d');
    cout << "║\n";

    // body
    for (int c = 0; c < 7; c++) {
        cout << "║═══╗\n";
        tableHeadLine("+Add " + courses[c] + " Assessment Result", 94, "║  ", 's');

        for (int a = 0; a < 3; a++) {
            string markRang = " [0-" + to_string(assessmentMaxPoint[a]) + "]";
            string errorMessage[2] = {
                " └─Invalid Input Type, please enter only int/float",
                " └─Why put out of the range, enter again in the range of" + markRang
            };

            cout << "║  │   " << GREEN << assessmentTypes[a] << markRang << ": " << RESET;
            cin >> result[a];

            do {
                if (invalidInput()) {
                    isTheirFormError = true;
                    cout << "║  │   " << RED << errorMessage[0] << RESET<<"\n";
                } else if (result[a] > assessmentMaxPoint[a] || result[a] < 0) {
                    isTheirFormError = true;
                    cout << "║  │   " << RED << errorMessage[1] << RESET<<"\n";
                } else {
                    isTheirFormError = false;
                }

                if(isTheirFormError)
                {
                    cout << "║  │   " << GREEN << assessmentTypes[a] << markRang << ": " << RESET;
                    cin >> result[a];
                }

            } while (isTheirFormError);
        }


        tableFooter(94, "║  ", 's');
        cout << endl;

        formData.results[c] = result[0] + result[1] + result[2];

    }

    cout << "║\n";

    // footer
    tableFooter(100,"",'d');
    cout << "\n";

    return formData;
}


void studentResult(studentInfo studentInfoFormData, assessment assessmentFormData)
{
    string name,id,courseGrade[7];
    float gpa;

    name = studentInfoFormData.name;
    id = to_string(studentInfoFormData.id) + "/15";

    for(int i=0;i<7;i++)
    {
        float total = assessmentFormData.results[i];
        courseGrade[i] = totalToGrade(total);
    }

    gpa = getGpa(assessmentFormData.results);

    // header
    cout << "\n";
    tableHeadLine(repeatStr(" ",25)+"Student Result",100,"",'d');

    // std info section
    cout << "║\n";
    studentInfoSec(name,id);

    // std grade result section
    cout << "\n║\n";
    studentGradeSec(courseGrade,gpa);

    // footer
    cout << "\n║\n";
    tableFooter(100,"",'d');
    cout << endl;
}


void studentInfoSec(string name, string id)
{
    // header
    cout << "║   ┌" << repeatStr("─",54) << "┐\n";

    //std name
    cout << "║   │   ╔===========╗     Name: ";
    cout << name;
    cout << repeatStr(" ",27-name.length()) << "│";

    //std id
    cout << "\n║   |   ║  (◔   ◔)  ║     Id: ";
    cout << id;
    cout << repeatStr(" ",29-id.length()) << "│";

    // head footer
    cout << R"(
║   |   ║     ▲     ║     Department: SWE
║   |   ║    ---    ║    
║   |   ╚===========╝                                       
)";

    // footer
    cout << "║   └" << repeatStr("─",54) << "┘";

}


void studentGradeSec(string courseGrade[7], float gpa)
{
    // header
    cout << "║   ┌";
    cout << repeatStr("─",34);
    cout << "┐   ┌";
    cout << repeatStr("─",16);
    cout << "┐\n";

    // columnsName
    cout << "║   |   Course         |   Grade      |   | GPA  |  ";
    cout << fixed << setprecision(2) << gpa;
    cout << "\n║   └";
    cout << repeatStr("─",34);
    cout << "┘   └";
    cout << repeatStr("─",16);
    cout << "┘";

    // course result
    for(int i=0;i<7;i++)
    {
        cout << "\n║   |   ";
        cout << courses[i];
        cout << repeatStr(" ",16-courses[i].length());
        cout << "|   ";
        cout << courseGrade[i];
        cout << repeatStr(" ",12-courseGrade[i].length()) << "|";
    }

    // footer
    cout << "\n║   └─────────────────────────────────┘";
}
