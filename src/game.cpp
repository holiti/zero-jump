#include "game.h"

std::random_device Game::rd; std::mt19937 Game::gen(rd());

Game::Game(){
    stopGame(); //clear valuer
}

void Game::startGame(){
#ifdef DEBUG
    std::cout << "Start game\n";
#endif
    game_state = state::start;
    score = 0;
}

bool Game::isPlay(){
    return game_state == state::start;
}

void Game::stopGame(){
    game_state = state::stop;
    distance = DISTANCE_MAX;
    time = DELAY_MAX;
    level_frame = 0;
    score_frame = 0;
    lastpos = PERS_Y;
    
    pers.clear();
    path.clear();

    rand = std::uniform_int_distribution<short>(
            distance - DISTANCE_DIFF, distance
    );
    lastpos += rand(gen);
    path.push_back(Obstacle(lastpos));
    lastpos += OBST_W - 1;
}

void Game::nextLevel(){
    if(distance == DISTANCE_MIN || time == DELAY_MIN)
        return;
    distance -= DISTANCE_DIFF;
    time -= DELAY_DIFF;
    rand = std::uniform_int_distribution<short>(
           distance - DISTANCE_DIFF, distance
    ); 
}

void Game::ahead(){
#ifdef DEBUG
    std::cout << "Move path ahead\n";
#endif
    ++score_frame;
    ++level_frame;

    //increase score
    if(score_frame == SCORE_F){
        ++score;
        score_frame = 0;
    }

    //next level of dificulty
    if(level_frame == LEVEL_F){
        nextLevel();
        level_frame = 0;
    }

    //move obstacle
    for(Obstacle &e:path){
        e.move();
    }

    //if first obstacle out of screen
    if(path.front().outScreen()){
        path.pop_front();
    }

    //generate next obstacle
    --lastpos;
    if(lastpos <= WINDOW_W){
        lastpos += rand(gen);
        path.push_back(Obstacle(lastpos));
        lastpos += OBST_W;
    }

    //move pers
    pers.move();

    if(whatis(pers.cordX(), PERS_Y) != CHARPERS){
        std::this_thread::sleep_for(std::chrono::milliseconds(DIED_DELAY));
        this->stopGame();
    }
}

void Game::jump(){
    pers.jump();
}

char Game::whatis(short x, short y){
    for(Obstacle &e:path)
        if(e.check(x, y))
            return CHAROBST; 

    if(y == PERS_Y && pers.cordX() == x){
       return CHARPERS;
    } 

    return ' ';
}

short Game::getScore(){
    return score;
}

short Game::getDelay(){
    return time;
}
