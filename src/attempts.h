#ifndef ATTEMPTS
#define ATTEMPTS

#include "constant.h"
#include <ctime>
#include <fstream>

extern const short ATTEMPTS_N, TIME_BUFF;
extern const char* const TIME_FORM;

class Attempt{
    tm* ctime;
    int score;
public:
    Attempt();
    Attempt(int);

    void swap(Attempt& );
    char* toString() const;

    bool operator< (const Attempt& ) const;

    ~Attempt();
};

class AttManager{
    char* filename;
    short size;
    Attempt atp[ATTEMPTS_N];
public:
    AttManager();
    
    void addAtt(int);
    char* getAtt(int) const;

    ~AttManager();
};

#endif
