#ifndef EVENTLOOP
#define EVENTLOOP

//#define DEBUG

#include "game.h"
#include "windowmanager.h"
#include <termios.h>
#include <unistd.h>

extern Game game;
extern WindowManager window;

class EventLoop{
    char ch;
    termios oldt, newt;

    void getchar_and_clear();
public:
    EventLoop();
    void process();
    ~EventLoop();
};

#endif

