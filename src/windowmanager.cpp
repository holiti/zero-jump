#include "windowmanager.h"

WindowManager::WindowManager(){
}
void WindowManager::drawLine(){
    std::cout << ' ';
    for(int x = 0;x < WINDOW_W;++x)
        std::cout << '-';
    std::cout << " \n";
}

void WindowManager::click(char button){
    if(button == 'q'){
        if(game.isPlay())
            game.stopGame();
        else
            exit(0);
    }

    if(button == 's' && !game.isPlay())
        game.startGame();
}

void WindowManager::Rander(){
#ifdef DEBUG
    std::cout << "Start randering\n";
#endif
    std::system("clear");

    drawLine();
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

    drawLine();

    int len;
    if(game.isPlay()){
        std::cout << "q - Quit";
        len = 8;
    }else{
        std::cout << "s - Start";
        len = 9;
    }

    for(int y = len;y <= WINDOW_W - 6;++y)
        std::cout << ' ';

    char score[] = "000000";
    int i = 5,current = game.getScore();
    while(i >= 0 && current){
        score[i] = (current % 10) + '0';
        current /= 10;
        --i;
    }
    std::cout << score << '\n';

    if(!game.isPlay())
        std::cout << "q - Quit game\n";

    std::cout.flush(); 
}

    
