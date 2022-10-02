#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <random>
#include <time.h> 
using namespace std;




class mastermind {
    public:
    string color[10] = {"pink=0", "red=1", "orange=2", "yellow=3", "green=4", "blue=5", "purple=6", "brown=7", "white=8", "black=9"};
    std::vector<vector<string>> board;
    std::vector<string> code;
    bool gameover=false;
    bool win=false;
    int count=0;

    mastermind();
    ~mastermind(){};

    void createCode();
    void printCode();
    void guess(int a,int b,int c,int d);
    void check(vector<string> & guess);
    void checkGameOver();
    void printBoard();


};