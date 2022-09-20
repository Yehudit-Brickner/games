#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
// #include <string>
#include <random>
#include <time.h> 
using namespace std;


class life {
    public:
        int row;
        int col;
        std:: vector<vector<int>> board;
        life(int r, int c);
        ~life(){};
        void createBoard();
        void updateBoard();
        void updateBoardInfinite();
        void countNeighbors(int r, int c);
        void countNeighborsInfinite(int r, int c);
        int sumBoard();
        void printBoard();

};
