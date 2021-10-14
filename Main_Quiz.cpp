#include "Quiz.h"
#include "MathsQuiz.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

srand(time(0));

int no_questions;

cout << "Enter number of questions: ";
cin >> no_questions;
cout << endl;

MathsQuiz one(no_questions);

int level;

cout << "Enter level of difficulty from 1 to 3: ";
cin >> level;
cout << endl;


one.set_level(level);
one.set_incrementer();

one.set_numbers1();
one.set_numbers2();

string operation;

cout << "Enter quiz mode from: +, - or x: ";
cin >> operation;
cout << endl;

one.set_operation(operation);

if (operation == "+") {
    one.addition();
} else if (operation == "-") {
   one.subtraction();
} else if (operation == "x") {
    one.multiplication();
}


for (int i=0; i<no_questions; i++) {

    one.question_display();
    one.set_PlayerAnswers();

}

one.mark();
one.print_results();




    return 0;
}
