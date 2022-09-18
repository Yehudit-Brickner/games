// #include <string>
// #include <iostream>
// #include <vector>
// #include <time.h> 
// #include <random>c
#include "playGame.hpp"
using namespace std;

int main(){

    int row, col, mines;
    cout <<"Please enter the number of rows, cols and mines you want."<<endl;
    cin >>row;
    cin>> col;
    cin>> mines;

    playGame g2(row, col, mines);
    while (g2.play){
        int r;
        int c;
        cout << "please enter a row and col to dig"<<endl;
        cin>>r;
        cin>>c;
        g2.dig(r,c);
    }
    
   
    return 0;
}