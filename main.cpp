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

studentData datas(){

    studentData newStudent;
    cout << "Enter Name, Surname and SchoolName" << endl;
    cin >> newStudent.name >> newStudent.surname >> newStudent.schoolName;
    return newStudent;
}


string getMarks(){



    int i;
    int english, mathematics, lo, cLiteracy, history, geography;

    cout << "Enter your marks. DOnt enter marks less than 0 or greater than 100";

    cout << "\n Enter English marks" << endl;
    cin >> english;
    if(english > 100 || english < 0){
        cout << "Please enter a valid mark score, re enter marks";
        getMarks();
    }

    cout << "\n Enter Mathematics marks" << endl;
    cin >> mathematics;
    if(mathematics > 100 || mathematics < 0){
        cout << "Please enter a valid mark score, re enter marks";
        getMarks();
    }

    cout << "\n Enter Life orientation marks" << endl;
    cin >> lo;
    if(lo > 100 || lo < 0){
        cout << "Please enter a valid mark score, re enter marks";
        getMarks();
    }

    cout << "\n Enter history marks" << endl;
    cin >> history;
    if(history > 100 || history < 0){
        cout << "Please enter a valid mark score, re enter marks";
        getMarks();
    }

    cout << "\n Enter computer Literacy marks" << endl;
    cin >> cLiteracy;
    if(cLiteracy > 100 || cLiteracy < 0){
        cout << "Please enter a valid mark score, re enter marks";
        getMarks();
    }

    cout << "\n Enter geography marks" << endl;
    cin >> geography;
    if(geography > 100 || geography < 0){
        cout << "Please enter a valid mark score, re enter marks";
        getMarks();
    }




}


/* new function :*/

float calcAvarageYearMark(int english, int geography, int mathematics, int history, int lo, int cliteracy){
        float avarage = english + geography + mathematics + history + lo + cliteracy;

    return avarage;
}





int main()
{
    studentData sam;
    sam = datas();

    cout << sam.surname << endl;
    //instatiate my pair:
    /*pair<float, float> p = getData();

    float BMI = calcBMI(p.first, p.second);

    displayFitnessResult(BMI);*/



    return 0;
}
