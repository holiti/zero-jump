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
    
    window_state cur = window.getState();
    switch (ch){
        case ' ':
            game.jump();
        break;

        case 'q':
            window.setState(window_state::menu);

            if(cur == window_state::play)
                game.stopGame();
            else if(cur == window_state::menu)
                exit(0);
        break;

        case 's':
            if(cur != window_state::play){
                window.setState(window_state::play);
                game.startGame();
            } 
        break;

        case 'l':
            if(cur != window_state::play){
                window.setState(window_state::list);
            }
        break;
    }
}

EventLoop::~EventLoop(){
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}
