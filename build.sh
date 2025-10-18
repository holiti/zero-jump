#!/bin/bash

cd src

g++ -c constant.cpp -o tmpconstant.o
g++ -c gamessence.cpp -o tmpgamessence.o
g++ -c game.cpp -o tmpgame.o
g++ -c windowmanager.cpp -o tmpwindowmanager.o
g++ -c main.cpp -o tmpmain.o
g++ -c eventloop.cpp -o tmpeventloop.o
g++ -c attempts.cpp -o tmpattempts.o

g++ -no-pie \
    tmpconstant.o \
    tmpgamessence.o \
    tmpgame.o \
    tmpwindowmanager.o \
    tmpmain.o \
    tmpeventloop.o \
    tmpattempts.o \
-o ../tmpmain 

rm *.o
cd ../


