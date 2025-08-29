#ifndef WINDOWMANAGER
#define WINDOWMANAGER

//#define DEBUG

#include "game.h"
#include <iostream>

extern const short
    WINDOW_H,
    WINDOW_W,
    JUMP;

extern Game game;

class WindowManager{
    void drawLine(); //drawing line
public:
    WindowManager();
    void click(char);   //emulate click
    void Rander();      //rander game 
};

#endif
