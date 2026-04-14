#!/bin/sh

CC=cc
SRC=./source/scb/scb.c
OUT=./build/scb

CFLAGS="-Wall -Wextra -Werror -Wpedantic -O0 -g -Wno-unused-function"

mkdir -p ./build

$CC $CFLAGS "$SRC" -o "$OUT"
