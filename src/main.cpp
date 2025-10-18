#include "gamessence.h"
#include "game.h"
#include "windowmanager.h"
#include "eventloop.h"
#include "attempts.h"
#include <thread>
#include <chrono>

Game game;
WindowManager window;
EventLoop event;
AttManager atm;

int32_t main(){
    while(1){
        event.process();
        window.Rander();
        if(game.isPlay())
            game.ahead();
        std::this_thread::sleep_for(std::chrono::milliseconds(game.getDelay()));
    }
}
