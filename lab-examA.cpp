#include <iostream>
#include <fstream>
using namespace std;

void printString(string& str){
    for(int i=0;i<str.size();i++){
        cout << str << endl;
    }
}


struct Student{
    int noOfQuizzes{};
    float *marks{};
    string name,roll_number;

};
void displayStudentInfo(Student& student) {
    cout << "Name: " << student.name << endl;
    cout << "Roll Number: " << student.roll_number << endl;
    cout << "Number of Quizzes: " << student.noOfQuizzes << endl;
    cout << "Quiz Marks: ";
    for (int i = 0; i < student.noOfQuizzes; ++i) {
        cout << student.marks[i] << " ";
    }
    cout << endl;
}

int main(){

    ifstream readFile("marks.txt");
    int lines = 0;
    string line;

    while(getline(readFile,line)){
        lines++;
    }
    cout << lines << endl;

    readFile.close();

    Student *student = new Student[lines];

ifstream readData("marks.txt",ios::in);

    if(readData.fail()){
        cout << "File failed to open....." << endl;
    }

    for(int i=0;i<lines;i++){
        readData >> student[i].noOfQuizzes;
        student[i].marks = new float[student[i].noOfQuizzes];

        for(int j=0; j<student[i].noOfQuizzes; j++)
        {
            readData >> student[i].marks[j];
        }
        readData >> student[i].name;
        readData >> student[i].roll_number;

    }

    for (int i = 0; i < lines; ++i) {
        displayStudentInfo(student[i]);
    }

    return 0;
}