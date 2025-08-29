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
         DELAY_DIFF = 5,
         DIED_DELAY = 500,
         DISTANCE_MAX = 125,
         DISTANCE_MIN = 25,
         DISTANCE_DIFF = 25, 
         PERS_X = 20,
         PERS_Y = 20,
         SCORE_F = 20,
         LEVEL_F = 5000,
         JUMP = 6;

extern const char 
    CHARPERS = '0',
    CHAROBST = '#';

#endif
