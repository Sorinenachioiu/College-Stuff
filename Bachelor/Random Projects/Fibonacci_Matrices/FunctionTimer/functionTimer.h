//
// Created by sorin on 3/25/2023.
//
#ifndef FUNCTIONTIMER_H
#define FUNCTIONTIMER_H

#include <chrono>
#include <iostream>
#include <functional>

namespace timer{
    class FunctionTimer {
    public:
        std::chrono::high_resolution_clock::time_point start;
        std::chrono::high_resolution_clock::time_point end;

        void startTimer(){
             start = std::chrono::high_resolution_clock::now();
        }
        void stopTimer(){
            end = std::chrono::high_resolution_clock ::now();
        }
        void tellTime(){
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns";
        }
    };
}

#endif // FUNCTIONTIMER_H