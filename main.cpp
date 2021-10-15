#include "Quiz.h"
#include "MathsQuiz.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
//initialises count of correct answers to zero
int count=0;

//initialising seed number for randomly generated numbers
srand(time(0));

//initialising counts for the number of questions
int no_questions;
int no_questions_check=0;

//asking player for number of questions to answer
while (no_questions_check == 0) {
cout << "Enter number of questions: ";
cin >> no_questions;

//ensuring player enters valid number of questions
if (no_questions > 0) {
    no_questions_check++;
} else {
    cout << "ERROR - Re-enter" << endl;
}
}
cout << endl;

//creating a MathsQuiz object
MathsQuiz one(no_questions);

//intialising level counts
int level;
int level_check=0;

//asking player to choose a starting level
while (level_check == 0) {
cout << "Enter starting level of difficulty from 1 to 3: ";
cin >> level;

//ensuring only valid level numbers inputted
if (level >= 1 && level <= 3) {
   level_check++;
} else {
    cout << "ERROR - Re-enter" << endl;
}
}

cout << endl;

//initialising operation counts
string operation;
int operation_check=0;

//asking user which quiz mode to play
while (operation_check == 0) {
cout << "Enter Maths Quiz mode from: +, -, x or /: ";
cin >> operation;

//ensuring valid input only
if (operation == "+" || operation == "-" || operation == "x" || operation == "/") {
    operation_check++;
} else {
    cout << "ERROR - Re-enter" << endl;
}
}

cout << endl;

one.set_operation(operation);

//while loop to send player to next level if achieve all correct answers to previous level
while (level <4) {

cout << "Level " << level << ":" << endl;
one.set_level(level);
one.set_incrementer();

one.set_numbers1();
one.set_numbers2();

//determining which operation player chose to calculate computer's array of answers
if (operation == "+") {
    one.addition();
} else if (operation == "-") {
   one.subtraction();
} else if (operation == "x") {
    one.multiplication();
} else if (operation == "/") {
    one.division();
}

//asking the player the questions
for (int i=0; i<no_questions; i++) {

    one.question_display(count);
    one.set_PlayerAnswers(count);

}

//marking the quiz
one.mark();

int mark;

mark=one.get_mark();

//determining if player can proceed to next level, if not, re-do current level
if (mark == no_questions) {
level++;

}

//prints the number of correct answers player got out of number of questions asked for current level
one.print_results();
cout << endl;
count=0; //sending mark back to zero

}

 return 0;

}
