#ifndef GAME
#define GAME

//#define DEBUG
#ifdef DEBUG
    #include<iostream>
#endif

#include <random>
#include <deque>
#include <thread>
#include <chrono>
#include "gamessence.h"

extern const short
    DELAY_MAX,
    DELAY_MIN,
    DELAY_DIFF,
    DISTANCE_MAX,
    DISTANCE_MIN,
    DISTANCE_DIFF,
    SCORE_F,
    LEVEL_F,
    DIED_DELAY,
    PERS_Y,
    OBST_H,
    OBST_W,
    WINDOW_W;

extern const char
    CHARPERS,
    CHAROBST;

    
class Game{
    enum state {start, stop};
    state game_state;
   
    //for random distance
    static std::random_device rd;
    static std::mt19937 gen;
    std::uniform_int_distribution<short> rand;

    void nextLevel(); //go to next level of difficulty

    short 
        distance,
        time,
        level_frame,
        score,
        lastpos,
        score_frame;

    std::deque<Obstacle> path; //queue with obstacle in game
    Person pers; //person essence
public:
    Game();
    void startGame();   //generate new path and set variables (start new game)
    bool isPlay();      //1 if game_state == state::start
    void ahead();       //push path to one position(one frame)
    void jump();        //emulate jump 
    void stopGame();    //stop game 
    short getScore();   //return game score
    char whatis(short, short); //return what characher in (x,y)
    short getDelay(); //return delay between frame
};

#endif
