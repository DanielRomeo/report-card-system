#include <iostream>
#include <utility>
#include <cmath>
#include <string.h>

using namespace std;



// making a pair so that i can return 2 values:
/*
std::pair<float, float> getData(){

    float weight, height;
    cout << "What is your weight (in kgs) and height(in meteres)?" << endl;
    cin >> weight >> height;
    return std::make_pair(weight, height);
}

float calcBMI(float weight, float height){
    float BMI;

    BMI = weight / pow(height, 2);
    return BMI;
}

string displayFitnessResult(float BMI){
    string weightStatus;

    if(BMI < 18.5){
        weightStatus = "Underweight";
    }else if((BMI <= 24.9 ) || (BMI <= 18.5 )) {
        weightStatus = "Healthy";
    }else if((BMI <= 29.9 ) || (BMI <= 24.5 )){
        weightStatus = "Overweight";
    }else if(BMI > 30.0 ){
        weightStatus = "Obese";
    }

    cout <<  "Your BMI is: " << BMI << " and weight Status is : " << weightStatus<< endl;
}*/
 struct studentData{
        string name, surname, schoolName;
    };

studentData getStudentDetails(){

    studentData newStudent;
    cout << "Enter Name, Surname and SchoolName" << endl;
    cin >> newStudent.name >> newStudent.surname >> newStudent.schoolName;
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
    newMarks.mathematicsSymbol = getSymbol(newMarks.mathematicsSymbol);

    // lo
    cout << "\n Enter Life orientation marks" << endl;
    cin >> newMarks.lo;
    if(newMarks.lo > 100 || newMarks.lo < 0){
        cout << "Please enter a valid mark score, re enter marks";
        getMarks();
    }
    newMarks.loCode = getCode(newMarks.lo);
    newMarks.loSymbol = getSymbol(newMarks.loSymbol);

    // history marks
    cout << "\n Enter history marks" << endl;
    cin >> newMarks.history;
    if(newMarks.history > 100 || newMarks.history < 0){
        cout << "Please enter a valid mark score, re enter marks";
        getMarks();
    }
    newMarks.historyCode = getCode(newMarks.history);
    newMarks.historySymbol = getSymbol(newMarks.historySymbol);

    // computer lieracy marks
    cout << "\n Enter computer Literacy marks" << endl;
    cin >> newMarks.cLiteracy;
    if(newMarks.cLiteracy > 100 || newMarks.cLiteracy < 0){
        cout << "Please enter a valid mark score, re enter marks";
        getMarks();
    }
    newMarks.cLiteracyCode = getCode(newMarks.cLiteracy);
    newMarks.cLiteracySymbol = getSymbol(newMarks.cLiteracySymbol);

    // geography marks
    cout << "\n Enter geography marks" << endl;
    cin >> newMarks.geography;
    if(newMarks.geography > 100 || newMarks.geography < 0){
        cout << "Please enter a valid mark score, re enter marks";
        getMarks();
    }
    newMarks.geographyCode = getCode(newMarks.geography);
    newMarks.geographySymbol = getSymbol(newMarks.geographySymbol);

    return newMarks;
}



/* new function :*/
float calcAvarageYearMark(int english, int geography, int mathematics, int history, int lo, int cliteracy){
    float avarage = english + geography + mathematics + history + lo + cliteracy;
    avarage = avarage / 6;
    return avarage;
}


int main()
{
    float student1Avarage;


    // get student details:
    studentData student1Details;
    student1Details = getStudentDetails();

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
    student1Avarage = calcAvarageYearMark(english, geography, mathematics, history, cLiteracy, lo);

    // display codes:
    cout << "english code "<< student1Marks.englishCode << endl;
    cout << "english symbol "<< student1Marks.englishSymbol << endl;

    cout << student1Avarage << endl;

    // call minmax to get lowest and highest values
    int biggest ;
    int smallest ;

    //smallest
    pair <int, int> p = minMax(english, geography, mathematics, history, cLiteracy, lo);
    biggest = p.first;
    smallest = p.second;


    cout << biggest << endl;
    cout << smallest << endl;



    //cout << product1 << endl;
    //cout << katlego.mathematics << endl;
    //instatiate my pair:
    /*pair<float, float> p = getData();

    float BMI = calcBMI(p.first, p.second);

    displayFitnessResult(BMI);*/



    return 0;
}
