#include "windowmanager.h"

WindowManager::WindowManager()
    :winstate(window_state::menu){
}

void WindowManager::drawLine(int size){
    std::cout << ' ';
    for(int x = 0;x < size;++x)
        std::cout << '-';
    std::cout << " \n";
}

void WindowManager::setState(window_state c){
    winstate = c;
}

window_state WindowManager::getState() const {
    return winstate;
}

void WindowManager::RanderGame(){
    drawLine(WINDOW_W);

    for(int x = 1;x <= WINDOW_H - JUMP;++x){
        std::cout << '|';
        for(int y = 0;y < WINDOW_W;++y)
            std::cout << ' ';
        std::cout << "|\n";
    }

    for(int x = WINDOW_H - JUMP + 1;x <= WINDOW_H;++x){
        std::cout << '|';
        for(int y = 1;y <= WINDOW_W;++y)
            std::cout << game.whatis(x,y);
        std::cout << "|\n";
    }

    drawLine(WINDOW_W);
}

void WindowManager::RanderList(){
    drawLine(30 + ATTEMPTS_DIST);

    for(int x = 0 ; x < ATTEMPTS_N; ++x){
        std::cout << '|' << atm.getAtt(x) << "|\n";
    }

    drawLine(30 + ATTEMPTS_DIST);
}

void WindowManager::Rander(){
#ifdef DEBUG
    std::cout << "Start randering\n";
#endif
    std::system("clear");

    if(winstate != window_state::list)
        RanderGame();
    else
        RanderList();

    int sz;
    if(winstate != window_state::menu){
        sz = 8;
        std::cout << "q - quet";
    }else{
        sz = 14;
        std::cout << "s - start game";
    }

    if(winstate != window_state::list){
        for(int x = 0;x < WINDOW_W - sz - 6;++x)
            std::cout << ' ';

        for(int x = 1e6, cur = game.getScore();x > 0;x /= 10){
            std::cout << cur / x;
            cur %= x;
        }
    }
    std::cout << '\n';

    if(winstate == window_state::menu){
        std::cout << "l - list of attempt\n" << "q - quit game\n";
    }

    std::cout.flush();
}

    
