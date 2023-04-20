#include <iostream>
#include <vector>

#include "Matrices/matrices.h"
#include "Matrices/matrices.cpp"
#include "FunctionTimer/functionTimer.h"

int main()
{
    std::string file = "matrix.in";
    auto mat = matrices::Matrix<long long>::readFromFile(file);
    int N = 20;

    timer::FunctionTimer secondTimer;
    secondTimer.startTimer();

    (mat[0] + mat[0]).displayMatrix();

    std::cout<<'\n';
    secondTimer.stopTimer();
    secondTimer.tellTime();
//
//    std::cout<<'\n';
//    timer::FunctionTimer firstTimer;
//    firstTimer.startTimer();
//
//    for(auto i = 0; i++ < N;){
//        std::cout << mat[0].slowExponentiation(i)(0,0);
//    }
//
//    std::cout<<'\n';
//    firstTimer.stopTimer();
//    firstTimer.tellTime();
//    std::cout<<'\n';
    return 0;
}

/**
* How to use the timer
timer::FunctionTimer firstTimer;
firstTimer.startTimer();
 Call a function
firstTimer.stopTimer();
firstTimer.tellTime();
*/