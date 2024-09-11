#!/bin/bash

set -xe

gcc game.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o game
