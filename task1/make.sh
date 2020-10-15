#!/bin/bash

CMD=g++ # Компилятор
CMD="$CMD -O3" # Максимальная оптимизация
CMD="$CMD -lpthread" # Линкуем библиотеку
CMD="$CMD main.cpp" # Файл с кодом
CMD="$CMD -o ./prog.out" # Избавляемся от символов

echo "Executing $CMD && strip ./prog.out"
$CMD && strip ./prog.out

