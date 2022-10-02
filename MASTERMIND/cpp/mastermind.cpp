#include "mastermind.hpp"

mastermind::mastermind(){
    createCode();
}

void mastermind::createCode(){
    srand (time(NULL));
    int min=0;
    int max=9;
    int range = max - min + 1;
    for (int i =0; i<4;i++){
        int num = rand() % range + min;
        this->code.push_back(this->color[num]);
    }
}

void mastermind::printCode(){
    for (int i =0; i<4;i++){
        cout<<code[i]<<"  ";
    }    
    cout<<endl;
}

void mastermind::guess(int a,int b,int c,int d){
    this->count++;
    vector<string>guess;
    guess.push_back(this->color[a]);
    guess.push_back(this->color[b]);
    guess.push_back(this->color[c]);
    guess.push_back(this->color[d]);
    check(guess);
    printBoard();
    checkGameOver();
    if (this->gameover==true && this->win==true){
        cout<<"you win!!!"<<endl;
    }
    else if (this->gameover==true && this->win==false){
        cout<<"game over"<<endl;
    }
}

void mastermind::check(vector<string> & guess){
   
    for (int i=0; i<4;i++){
        if (guess[i]==this->code[i]){
            guess.push_back("r");
        }
        else{
            string ch = "_";
            for (int j =0;j<4;j++){
                if (i!=j){
                    if (guess[i]==this->code[j]){
                        ch="y";
                    }
                }
            }
            guess.push_back(ch);
        }
    }
    this->board.push_back(guess);
}

void mastermind::printBoard(){
for (int i =0; i<this->board.size();i++){
    for (int j=0;j<this->board[i].size();j++){
            cout<<board[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void mastermind::checkGameOver(){
    int row=this->board.size();
    row=row-1;
    int col=this->board[row].size();
    // cout<<"row: "<<row<<"  col: "<<endl;
    int count=0;
    for (int i=4;i<col;i++){
        // cout<<i<<endl;
        if (this->board[row][i]=="r"){
            count++;
        }
    }
    if (count==4){
        this->gameover=true;
        this->win=true;
       
    }
    else if(this->count==10){
        this->gameover=true;
        
    }

}




