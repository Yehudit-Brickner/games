#include "life.hpp"

using namespace std;

life::life(int r, int c){
    this->row=r;
    this->col=c;
    createBoard(); 
    printBoard();
    int count =0;
    int num=1;
    while (count<10 && num!=0){
        updateBoardInfinite();
        printBoard();
        num=sumBoard();
        count++;
    } 
}


void life::createBoard(){
    srand (time(NULL));
    for(int i=0; i<this->row;i++){
        vector<int>temp;
        for (int j=0; j<this->col;j++){
            float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            if (r>0.7){
                temp.push_back(1); 
            }
            else{
               temp.push_back(0);  
            }
        }
        this->board.push_back(temp);
        temp.clear();
    }
}

void life::updateBoard(){
    for (int i=0; i<this->row;i++){
        for (int j=0; j<this->col;j++){
            countNeighbors(i,j);
        }
    }
    for (int i=0; i<this->row;i++){
        for (int j=0; j<this->col;j++){
            if (this->board[i][j]==-2){
                this->board[i][j]=0;
            }
            else if(this->board[i][j]==-1){
                this->board[i][j]=1;
            }
        }
    }
    
}

void life::countNeighbors(int r, int c){
    int count=0;
    for (int i=r-1; i<r+2; i++){
        for (int j=c-1;j<c+2;j++){
            if (i>=0 && j>=0 && i<this->row && j<this->col){
                if (i==r && j==c){
                    continue;
                }
                else if (this->board[i][j]==1 || this->board[i][j]==-2){
                    count++;
                }
            }
        }
    }
    // alive -> dead = -2
    // alive -> alive = 1
    // dead -> alive = -1
    // dead -> dead = 0
    // cout<< r<<" "<<c<<" "<<count<<endl;
    if(this->board[r][c]==1){
        // alive -> dead = -2
        if (count<2){
            this->board[r][c]=-2;
        }
        // alive -> alive = 1
        else if (count==2 || count==3){
            this->board[r][c]=1;
        }
        // alive -> dead
        else if (count>3){
           this->board[r][c]=-2; 
        }
    }
    else if (this->board[r][c]==0){
        // dead -> alive
        if (count==3){
            this->board[r][c]=-1;
        }
    }
}


void life::updateBoardInfinite(){
   for (int i=0; i<this->row;i++){
        for (int j=0; j<this->col;j++){
            countNeighborsInfinite(i,j);
        }
    }
    for (int i=0; i<this->row;i++){
        for (int j=0; j<this->col;j++){
            if (this->board[i][j]==-2){
                this->board[i][j]=0;
            }
            else if(this->board[i][j]==-1){
                this->board[i][j]=1;
            }
        }
    } 
}

void life::countNeighborsInfinite(int r, int c){
   int count=0;
    for (int i=r-1; i<r+2; i++){
        for (int j=c-1;j<c+2;j++){
            int a=i%this->row;
            int b=j%this->col;
            if (a==r && b==c){
                continue;
            }
            else if (this->board[a][b]==1 || this->board[a][a]==-2){
                count++;
            }
        }
    }
    
    // alive -> dead = -2
    // alive -> alive = 1
    // dead -> alive = -1
    // dead -> dead = 0
    // cout<< r<<" "<<c<<" "<<count<<endl;
    if(this->board[r][c]==1){
        // alive -> dead = -2
        if (count<2){
            this->board[r][c]=-2;
        }
        // alive -> alive = 1
        else if (count==2 || count==3){
            this->board[r][c]=1;
        }
        // alive -> dead
        else if (count>3){
           this->board[r][c]=-2; 
        }
    }
    else if (this->board[r][c]==0){
        // dead -> alive
        if (count==3){
            this->board[r][c]=-1;
        }
    } 
}

int life::sumBoard(){
    int count=0;
    for (int i=0; i<this->row;i++){
        for (int j=0; j<this->col;j++){
            count+=this->board[i][j];
        }
    }
    return count;
}

void life::printBoard(){
    for (int i =0; i<this->row;i++){
        for (int j=0; j<this->col;j++){
            cout<<this->board[i][j];
            cout<<" ";
        }
        cout<<endl;
    }
    cout<<"\n"<<endl;
}