#include "gamessence.h"

//Person segment
Person::Person(): 
    x(PERS_X), motion_state(motion::run){

} 

int Person::cordX(){
    return x;
}
void Person::move(){ 
    if(x == PERS_X - JUMP) //if in peak
        motion_state = motion::down;
    else if(x == PERS_X && motion_state == motion::down) //if is land
        motion_state = motion::run;

    if(motion_state == motion::up)
        --x;
    else if(motion_state == motion::down)
        ++x;
} void Person::jump(){
    if(motion_state == motion::run)
        motion_state = motion::up;
}

void Person::clear(){
    motion_state = motion::run;
    x = PERS_X;
}


//Obstacle segment
//static random device init
std::random_device Obstacle::rd;
std::mt19937 Obstacle::gen(rd());
std::uniform_int_distribution<short> Obstacle::distr(0, OBST_N - 1);

Obstacle::Obstacle(int position):
    y(position){
    index = distr(gen);
}

void Obstacle::move(){
    --y; 
}

bool Obstacle::check(short px, short py){
    if(py < y || py - y >= OBST_W)
        return 0;
    py -= y;
    px = OBST_H - (WINDOW_H - px) - 1;

    if(px < 0)return 0;

    return obstemp[index][px][py] == '#';
}

bool Obstacle::outScreen(){
    return y <= -OBST_W;
}


