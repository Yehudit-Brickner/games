#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
// #include <string>
#include <random>
#include <time.h> 
using namespace std;

class playGame{
    public:
    int row, col, mines, numflags;
    bool play;
    std:: vector<vector<int>> notSeenBoard;
    std:: vector<vector<char>> seenBoard;

    playGame(int row,int col,int mines);
    ~playGame(){};

    void createMines();

    void numberEverything();

    void countNeighbors(int r,int c);
    
    void printboard1(const vector<vector<int>> & board);
    
    void printboard2(const vector<vector<char>> & board);
    
    void dig(int r, int c);

    void digNeighbors(int r, int c);

    int countSeenBoard();

    void markFlag(int r, int c);

    void unmarkFlag(int r, int c);

    void checkFlags();
};