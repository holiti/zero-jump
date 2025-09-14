#ifndef ATTEMPTS
#define ATTEMPTS

#include "constant.h"

#include <ctime>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

extern const char* const TIME_FORM;

class Attempt{
    tm ctime;
    int score;
public:
    Attempt();
    Attempt(int);

    void swap(Attempt& );
    std::string toString() const;

    bool operator< (const Attempt& ) const;

    ~Attempt();
};

class AttManager{
    short size;
    Attempt atp[ATTEMPTS_N];
public:
    AttManager();
    
    void addAtt(int);
    std::string getAtt(int) const;

    ~AttManager();
};

#endif
