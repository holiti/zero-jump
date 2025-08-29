#include "eventloop.h"

EventLoop::EventLoop(){
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);
    newt.c_cc[VMIN] = 0;
    newt.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void EventLoop::getchar_and_clear(){
    ch = 0;
    read(STDIN_FILENO, &ch, 1);
    tcflush(STDIN_FILENO, TCIFLUSH);
}

void EventLoop::process(){
    getchar_and_clear();
    if(ch == 0)
        return; //buffer clear
    
    if(ch == ' ')
        game.jump();
    else if(ch == 'q' || ch == 's')
        window.click(ch);
}

EventLoop::~EventLoop(){
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}
