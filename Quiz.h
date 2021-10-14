#ifndef QUIZ_H
#define QUIZ_H
#include <string>
using namespace std;

class Quiz {

    public:

        virtual int mark()=0;
        virtual void print_results()=0;

};
#endif
