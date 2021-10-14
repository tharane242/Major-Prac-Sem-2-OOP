#ifndef MATHSQUIZ_H
#define MATHSQUIZ_H
#include "Quiz.h"
#include <string>
using namespace std;

class MathsQuiz:public Quiz {

private:
        int* PlayerAnswers;
        int* CompAnswers;
        int* numbers1;
        int* numbers2;
        int level;
        int mark_counter;
        int question_number;
        string operation;
        int incrementer;
        int player_count;
        int question_display_count;

public:
  MathsQuiz(int input_question_number);

  string get_operation();
  void set_operation(string input_operation);
  int* addition();
  int* subtraction();
  int* multiplication();
  int* get_numbers1();
  int* get_numbers2();
  void set_numbers1();
  void set_numbers2();
  int get_incrementer();
  void set_incrementer();
  int get_level();
  void set_level(int input_level);
  void question_display();
  void set_PlayerAnswers();


virtual int mark();
virtual void print_results();


~MathsQuiz();

};
#endif
