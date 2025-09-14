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

#define WINDOW_W        101
#define WINDOW_H        20
#define DELAY_MAX       30
#define DELAY_MIN       10
#define DELAY_DIFF      4
#define DIED_DELAY      500
#define DISTANCE_MAX    80
#define DISTANCE_MIN    20
#define DISTANCE_DIFF   12
#define PERS_X          20
#define PERS_Y          20
#define SCORE_F         5
#define LEVEL_F         1000
#define JUMP            6
#define ATTEMPTS_N      10
#define TIME_BUFF       20

#define OBST_N          7
#define OBST_W          5
#define OBST_H          4

const char* const TIME_FORM = "%y.%m.%d - %H:%M";

const char 
    CHARPERS =      '0',
    CHAROBST =      '#';

//obstacle template
const char obstemp[OBST_N][OBST_H][OBST_W + 1] =
{
    {
        " #   ",
        " #   ",
        " ##  ",
        "# ## "
    },
    {
        "  #  ",
        "###  ",
        "# ## ",
        "# # #"
    },
    {
        "     ",
        "  #  ",
        " ### ",
        " # # "
    },
    {
        "  #  ",
        " ### ",
        " # ##",
        "### #"
    },
    {
        "     ",
        "     ",
        "  #  ",
        " ### "
    },
    {
        "     ",
        " ##  ",
        "# ## ",
        "## ##"
    },
    {
        "     ",
        "     ",
        " ### ",
        "# ###"
    }
};

#endif
