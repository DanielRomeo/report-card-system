#include <iostream>
#include <utility>
#include <cmath>
#include <string.h>
#include <vector>
using namespace std;



 struct studentData{
        string name, surname, schoolName;
    };

studentData studentDetails(){

    studentData newStudent;
    cout << "Enter Name, Surname and SchoolName" << endl;
    cin >> newStudent.name;
    cout << "Enter Surname"<< endl;
    cin >> newStudent.surname;
    cout << "Enter School Name" << endl;
    cin.ignore();
    getline(cin, newStudent.schoolName, '\n');


    return newStudent;
}

struct marksData{
    int english, mathematics, lo, history, cLiteracy, geography;
    int englishCode, mathematicsCode, loCode, historyCode, cLiteracyCode, geographyCode;
    string englishSymbol, mathematicsSymbol, loSymbol, historySymbol, cLiteracySymbol, geographySymbol;
};


int getCode(int mark){
    if(mark >= 80){
        return 7;
    }else if(mark >= 70 && mark< 80){
        return 6;
    }else if(mark >= 60 && mark< 70){
        return 5;
    }else if(mark >= 50 && mark< 60){
        return 4;
    }else if(mark >= 40 && mark< 50){
        return 3;
    }else if(mark >= 30 && mark< 40){
        return 2;
    }else if(mark >= 0 && mark< 30){
        return 1;
    }
}


// this will be used to get the code: :: wait what?
string getSymbol(int code){
    switch(code){
        case 7:
            return "A";
        case 6:
            return "B";
        case 5:
            return "C";
        case 4:
            return "D";
        case 3:
            return "E";
        case 2:
            return "F";
        case 1 :
            return "FF";
    }
}

std::pair<int, int> minMax(int english, int geography, int mathematics, int history, int cLiteracy, int lo){

    int highest, lowest;
    int i;

    // add all datas in array :
    int myArray[6] = {english, geography, mathematics, history, cLiteracy, lo};


    // loop through all the data:
    lowest = myArray[0];
    highest = myArray[0];

    for(i = 0; i < 6; i++){
        if(lowest > myArray[i]){
            lowest = myArray[i];
        }

        if(highest < myArray[i]){
            highest = myArray[i];
        }
    }

    return std::make_pair(highest, lowest);
}




marksData getMarks(){

    marksData newMarks;
    cout << "Enter your marks. Don't enter marks less than 0 or greater than 100";

    // english
    cout << "\n Enter English marks" << endl;
    cin >> newMarks.english;
    if(newMarks.english > 100 || newMarks.english < 0){
        cout << "Please enter a valid mark score, re enter marks";
        getMarks();
    }
    newMarks.englishCode = getCode(newMarks.english);
    newMarks.englishSymbol = getSymbol(newMarks.englishCode);

    // mathemnatics
    cout << "\n Enter Mathematics marks" << endl;
    cin >> newMarks.mathematics;
    if(newMarks.mathematics > 100 || newMarks.mathematics < 0){
        cout << "Please enter a valid mark score, re enter marks";
        getMarks();
    }
    newMarks.mathematicsCode = getCode(newMarks.mathematics);
    newMarks.mathematicsSymbol = getSymbol(newMarks.mathematicsCode);

    // lo
    cout << "\n Enter Life orientation marks" << endl;
    cin >> newMarks.lo;
    if(newMarks.lo > 100 || newMarks.lo < 0){
        cout << "Please enter a valid mark score, re enter marks";
        getMarks();
    }
    newMarks.loCode = getCode(newMarks.lo);
    newMarks.loSymbol = getSymbol(newMarks.loCode);

    // history marks
    cout << "\n Enter history marks" << endl;
    cin >> newMarks.history;
    if(newMarks.history > 100 || newMarks.history < 0){
        cout << "Please enter a valid mark score, re enter marks";
        getMarks();
    }
    newMarks.historyCode = getCode(newMarks.history);
    newMarks.historySymbol = getSymbol(newMarks.historyCode);

    // computer lieracy marks
    cout << "\n Enter computer Literacy marks" << endl;
    cin >> newMarks.cLiteracy;
    if(newMarks.cLiteracy > 100 || newMarks.cLiteracy < 0){
        cout << "Please enter a valid mark score, re enter marks";
        getMarks();
    }
    newMarks.cLiteracyCode = getCode(newMarks.cLiteracy);
    newMarks.cLiteracySymbol = getSymbol(newMarks.cLiteracyCode);

    // geography marks
    cout << "\n Enter geography marks" << endl;
    cin >> newMarks.geography;
    if(newMarks.geography > 100 || newMarks.geography < 0){
        cout << "Please enter a valid mark score, re enter marks";
        getMarks();
    }
    newMarks.geographyCode = getCode(newMarks.geography);
    newMarks.geographySymbol = getSymbol(newMarks.geographyCode);

    return newMarks;
}



/* new function :*/
float avarageYearMark(int english, int geography, int mathematics, int history, int lo, int cLiteracy){
    float avarage = english + geography + mathematics + history + lo + cLiteracy;
    avarage = avarage / 6;

    //first round it off
    avarage = round(avarage);

    return avarage;
}

bool passOrFail(int english, int geography, int mathematics, int history, int lo, int cLiteracy){
    // learner has to pass atleast 4 inc english:
    int i;
    int subjects[6] = {english, geography, mathematics, history, cLiteracy, lo};

    vector<int> passedSubjects;

    // check if student passed english:
    if(english < 50){
        return false;
    }

    // loop through remaining subjects to check if student passed:
    for(i = 0; i < 5; i++){
        // first loop through them and add passed subjects to array:
        if(subjects[i] >= 50){
            passedSubjects.push_back(subjects[i]);
        }
    }

    // count how man items are in passedSubjects:
    if(passedSubjects.size() >= 4){
        return true;
    }else{
        return false;
    }
}


int main()
{
    float student1Avarage;


    // get student details:
    studentData student1Details;
    student1Details = studentDetails();

    // get student marks
    marksData student1Marks;
    student1Marks = getMarks();


    int english, geography, mathematics, history, lo, cLiteracy;

    english = student1Marks.english;
    geography = student1Marks.geography;
    mathematics = student1Marks.mathematics;
    history = student1Marks.history;
    cLiteracy = student1Marks.cLiteracy;
    lo = student1Marks.lo;

    // calculates students avarage mark:
    student1Avarage = avarageYearMark(english, geography, mathematics, history, cLiteracy, lo);

    // call minmax to get lowest and highest values
    int biggest ;
    int smallest ;
    bool passed ;
    string resultOutcome;
    int student1AvarageInt, student1AvarageCode;
    string student1AvarageSymbol;
    //smallest
    pair <int, int> p = minMax(english, geography, mathematics, history, cLiteracy, lo);
    biggest = p.first;
    smallest = p.second;

    passed = passOrFail(english, geography, mathematics, history, cLiteracy, lo); // returns 0 or 1:
    if(passed == 0){
        resultOutcome = "Failed";
    }else{
        resultOutcome = "Passed";
    }

    // get the avarage symbol and avarage code:
    /* convert it to integer so that i can reUse the getCode() and getSymbol() functions */
    student1AvarageInt = (int)student1Avarage;
    student1AvarageCode = getCode(student1AvarageInt);
    student1AvarageSymbol = getSymbol(student1AvarageCode);

    cout << "*********************************************************" << endl;

    cout << "              STUDENT ACADEMIC RECORD*******************" << endl;

    cout << "This program inputs the learners marks of matric and prints the students' final report." << endl;

    cout << "********************************************************" << endl;


    cout << "Name: " << student1Details.name << "                  " << "School: "<< student1Details.schoolName << endl;
    cout << " \n" << endl;

    cout << "Subject           " << "          " << "Mark     " << "Symbol  " << "Code " << endl;
    cout << "English           " << "          " << english            << "%         " <<  student1Marks.englishSymbol << "     " << student1Marks.englishCode << endl;
    cout << "Mathematics       " << "          " << mathematics        << "%         " <<  student1Marks.mathematicsSymbol << "     " << student1Marks.mathematicsCode << endl;
    cout << "Life Orientation  " << "          " << lo                 << "%         " <<  student1Marks.loSymbol << "     " << student1Marks.loCode << endl;
    cout << "History           " << "          " << history            << "%         " <<  student1Marks.historySymbol << "     " << student1Marks.historyCode << endl;
    cout << "Computer Literacy " << "          " << cLiteracy          << "%         " <<  student1Marks.cLiteracySymbol << "     " << student1Marks.cLiteracyCode << endl;
    cout << "Geography         " << "          " << geography          << "%         " <<  student1Marks.geographySymbol << "     " << student1Marks.geographyCode << endl;

    cout << " \n" << endl;
    cout << "Avarage Year Mark: " << student1AvarageInt << " with Symbol "<< student1AvarageSymbol << " and a code " << student1AvarageCode << endl;
    cout << "Outcome " << resultOutcome << endl;

    cout << "The higest mark was " <<  biggest << "%." << " The lowest mark was " << smallest << "%" << endl;

    cout << "********************************************************" << endl;



    return 0;
}
