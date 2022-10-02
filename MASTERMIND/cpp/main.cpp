#include "mastermind.hpp"
using namespace std;

int main(){
    
    mastermind m;
    // m.printCode();
    while(m.gameover==false){
        cout<< "please enter 4 colors(numbers)"<<endl;
        int a=-1;
        int b=-1;
        int c=1;
        int d=-1;
        cin>> a;
        cin>> b;
        cin>> c;
        cin>> d;
        if (0<=a && a<=9 && 0<=b && b<=9  && 0<=c && c<=9  && 0<=d && d<=9 ){
            m.guess(a,b,c,d);
        }
      
    }
    
    return 0;
    
}