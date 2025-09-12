/*
    File with all const value of game.
    If you want change game or gameplay you can change this constant.
    But something can break :)))
    p.s IF you find how change template of obstacle or they
    amount, width or height you can change it in file 
    gamessence.h in obstacle segment
    because i faced difficulties when try write they in this
    file.
*/

#ifndef CONSTANT
#define CONSTANT

extern const short 
         WINDOW_W = 100,
         WINDOW_H = 20,
         DELAY_MAX = 30,
         DELAY_MIN = 10,
         DELAY_DIFF = 4,
         DIED_DELAY = 500,
         DISTANCE_MAX = 80,
         DISTANCE_MIN = 20,
         DISTANCE_DIFF = 12, 
         PERS_X = 20,
         PERS_Y = 20,
         SCORE_F = 5,
         LEVEL_F = 1000,
         JUMP = 6,
         ATTEMPTS_N = 10,
         TIME_BUFF = 20;

extern const char* const TIME_FORM = "%y.%m.%d - %H:%M";

extern const char 
    CHARPERS = '0',
    CHAROBST = '#';

#endif
