#!/bin/bash

set -xe

g++ game.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o game

./game
