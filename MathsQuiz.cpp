#include "Quiz.h"
#include "MathsQuiz.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

MathsQuiz::MathsQuiz(int input_question_number) {
//work? question_number/input_question_number arrangement??
question_number = input_question_number;
numbers1 = new int[input_question_number];
numbers2 = new int[input_question_number];
operation = "";
CompAnswers = new int[input_question_number];
PlayerAnswers = new int[input_question_number];
incrementer = 0;
player_count = 0;
question_display_count = 0;
mark_counter = 0;
incrementer = 0;
level = 0;
}

int MathsQuiz::get_level() {

   return level;

}

void MathsQuiz::set_level(int input_level) {
    level = input_level;
}

int MathsQuiz::get_incrementer() {

return incrementer;

}

void MathsQuiz::set_incrementer() {

    if (level == 1) {
     incrementer = 10;
    } else if (level == 2) {
    incrementer = 100;
    } else if (level == 3) {
        incrementer = 1000;
    }
}

void MathsQuiz::set_numbers1() {

int number1;
for (int i=0;i<question_number;i++) {
number1 = (rand() % incrementer) + 1;
numbers1[i] = number1;
}
}

int* MathsQuiz::get_numbers1() {
    return numbers1;
}

void MathsQuiz::set_numbers2() {

int number2;
for (int i=0;i<question_number;i++) {
number2 = (rand() % incrementer) + 1;
numbers2[i] = number2;
}
}

int* MathsQuiz::get_numbers2() {
    return numbers2;
}

string MathsQuiz::get_operation() {
return operation;
}


void MathsQuiz::set_operation(string input_operation) {
    if (input_operation == "+") {
    operation = "+";
} else if (input_operation == "-") {
    operation = "-";
} else if (input_operation == "x") {
    operation = "x";
}
}


int* MathsQuiz::addition() {

for (int i=0;i<question_number;i++) {
CompAnswers[i] = numbers1[i] + numbers2[i];
}
return CompAnswers;
}

int* MathsQuiz::subtraction() {

for (int i=0;i<question_number;i++) {
CompAnswers[i] = numbers1[i] - numbers2[i];
}
return CompAnswers;
}

int* MathsQuiz::multiplication() {

for (int i=0;i<question_number;i++) {
CompAnswers[i] = numbers1[i] * numbers2[i];
}
return CompAnswers;
}




//input part

void MathsQuiz::set_PlayerAnswers() {

int temp = 0;

cout << "Enter answer: ";
    cin >> temp;

PlayerAnswers[player_count] = temp;
player_count++;

}



void MathsQuiz::question_display() {

    cout << "What is " << numbers1[question_display_count] << operation << numbers2[question_display_count] << " ?" << endl;
question_display_count++;

}

int MathsQuiz::mark() {

    for(int i=0;i<question_number;i++) {
        if (CompAnswers[i] == PlayerAnswers[i]) {
            mark_counter++;
        }
    }
    return mark_counter;
}

void MathsQuiz::print_results() {

    cout << "You got " << mark_counter << " out of " << question_number << endl;

}

MathsQuiz::~MathsQuiz()
{
}
