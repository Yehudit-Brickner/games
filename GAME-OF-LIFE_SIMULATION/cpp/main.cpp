#include "life.hpp"

using namespace std;

int main(){
    cout<<"hi"<<endl;
    int row=5;
    int col=5;
    life l(5,5);
    l.printBoard();
    l.updateBoard();
    l.printBoard();
    
    return 0;
}

