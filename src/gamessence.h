#ifndef GAMESSENCE
#define GAMESSENCE

//PERSON SEGMENT
extern const short
        JUMP,
        PERS_X;

class Person{
    short x;
    enum motion {run, up, down};
    motion motion_state;  
public:
    Person();
    int cordX();
    void move();    //moves person by 1 frame
    void jump();    //emulate click of space
    void clear();   //return person to start postion and start state
};



//OBSTACLE SEGMENT
#include<random>
extern const short 
    WINDOW_H;

const short
         OBST_N = 7,
         OBST_W = 5,
         OBST_H = 4;



class Obstacle{
    //for random template
    static std::random_device rd;
    static std::mt19937 gen;
    static std::uniform_int_distribution<short> distr;

    short index;
    short y;
public:
    Obstacle(int);
    void move();    //move obstacle by 1 frame
    bool check(short, short);   //check if in pos (x,y) obstacle
    bool outScreen();   //check if obstacle out of screen
};

//obstacle template
const char obstemp[OBST_N][OBST_H][OBST_W + 1] = 
{
    {
        " #   ",
        " #   ",
        " ##  ",
        "# ## "
    },
    {
        "  #  ",
        "###  ",
        "# ## ",
        "# # #"
    },
    {
        "     ",
        "  #  ",
        " ### ",
        " # # "
    },
    {
        "  #  ",
        " ### ",
        " # ##",
        "### #"
    },
    {
        "     ",
        "     ",
        "  #  ",
        " ### "
    },
    {
        "     ",
        " ##  ",
        "# ## ",
        "## ##"
    },
    {
        "     ",
        "     ",
        " ### ",
        "# ###"
    }
};

#endif
