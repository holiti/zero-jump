#ifndef WINDOWMANAGER
#define WINDOWMANAGER

//#define DEBUG

#include "constant.h"

#include "game.h"
#include "attempts.h"
#include <iostream>

extern AttManager atm;
class Game;
extern Game game;

enum window_state {play, menu, list};

class WindowManager{
    window_state winstate;
    void drawLine(int); //drawing line
public:
    WindowManager();
    window_state getState() const;
    void setState(window_state); //set winstate
    void RanderGame();
    void RanderList();
    void Rander();      //rander window
};

#endif
