#include "playGame.hpp"


using namespace std;

playGame::playGame(int row, int col, int mines){
    if (row<=0){
        throw std::invalid_argument( "row is smaller or eqaual to zero" ); 
    }
    this->row=row;
    if (col<=0){
        throw std::invalid_argument( "col is smaller or eqaual to zero" );
    }
    this->col=col;
    if (mines<=0){
        throw std::invalid_argument( "mines is smaller or eqaual to zero" );
    }
    this->mines=mines;
    this->play=true;
    this->numflags=0;

    for(int i=0; i<row;i++){
        vector<int>temp1;
        vector<char>temp2;
        for (int j=0; j<col;j++){
            temp1.push_back(0);
            temp2.push_back(' ');
        }
        this->notSeenBoard.push_back(temp1);
        this->seenBoard.push_back(temp2);
        temp1.clear();
        temp2.clear();
    }
    createMines();
    numberEverything();
    cout<<"Let the game begin"<<endl;
    printboard2(this->seenBoard);
}

void playGame::createMines(){
    int min=0;
    int max=this->notSeenBoard[0].size()*this->notSeenBoard.size()-1;
    int range = max - min + 1;
    int minecount=0;
    srand (time(NULL));
    while (minecount<this->mines){
        int num = rand() % range + min;
        // int r= num/this->notSeenBoard[0].size();
        int r= num/this->col;
        // int c=num%notSeenBoard[0].size();
        int c=num%this->col;
        if (this->notSeenBoard[r][c]==0){
            this->notSeenBoard[r][c]=-1; 
            minecount++;   
        }
    }
}

void playGame::numberEverything(){
    for (int i=0;i<this->notSeenBoard.size();i++){
        for (int j=0; j<this->notSeenBoard[0].size();j++){
            if (notSeenBoard[i][j]!=-1){
                countNeighbors(i,j);
            }
        }
    }
}

void playGame::countNeighbors( int r,int c){
    int count=0;
    for (int i=r-1;i<r+2;i++){
        for (int j=c-1;j<c+2;j++){
            if (i>=0 && j>=0 && i<this->notSeenBoard.size() && j<this->notSeenBoard[0].size()){
                if (i==r && j==c){
                    continue;
                }
                else{
                    if (this->notSeenBoard[i][j]==-1){
                        count++;
                    }
                }
            }
        }
    }
    this->notSeenBoard[r][c]=count;
}

void playGame::printboard1(const vector<vector<int>> & board){
    for (int i=0; i<board.size();i++){
        for (int j=0; j<board[0].size();j++){
            if (board[i][j] ==-1){
                cout<<"*|";
            }
            else{
                cout<<board[i][j]<<"|";
            } 
        }
        cout<<endl;
    }
    cout<<"\n\n"<<endl;
}


void playGame::printboard2(const vector<vector<char>> & board){
    for (int i=0; i<board.size();i++){
        for (int j=0; j<board[0].size();j++){
            cout<<board[i][j]<<"|"; 
        }
        cout<<"  row "<< i<<endl;
    }
    cout<<endl;
    char l[4] ={'c','o','l',' '};
    for(int j=0;j<4;j++){
        for(int i=0; i<this->col;i++){
            if (j<3){
                cout<<l[j]<<" ";
            }
            else{
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
    cout<<"\n"<<endl;
}



void playGame::dig(int r, int c){
    if (r >=0 && r<this->row && c>=0 && c<this->col){
        if (this->notSeenBoard[r][c]==-1 && this->seenBoard[r][c]!='f'){
            cout<<"GAME OVER\nNICE TRY!"<<endl;
            this->play=false;
            printboard1(this->notSeenBoard);
        }
        
        else if (this->notSeenBoard[r][c]==0){
            this->seenBoard[r][c]='0';
            digNeighbors(r,c);
            printboard2(this->seenBoard);
            int num=countSeenBoard();
            if (num==(this->col*this->row) - this->mines){
                play=false;
                cout <<"CONGRAGULATION!!!\n   YOU WON!!!"<<endl;
            }
            
            if (play){
                int mark=1;
                while(mark==1){
                    if (this->numflags>0){
                        cout<< "You have marked "<< this->numflags<< "flags."<<endl;
                    }
                    cout<<"Do you want to mark a flag?\n    1=yes, 0=no"<<endl;
                    cin>>mark;
                    if (mark==1){
                        cin>>r;
                        cin>>c;
                        markFlag(r,c);
                        if (!play){
                            mark=0;
                        }
                    }
                }  
            } 
        }
        else{
            this->seenBoard[r][c]=char(this->notSeenBoard[r][c]+48); 
            printboard2(this->seenBoard);
            int num=countSeenBoard();
            if (num==(this->col*this->row) - this->mines){
                play=false;
                cout <<"CONGRAGULATION!!!\n   YOU WON!!!"<<endl;
            }
            
            if (play){
                int mark=1;
                while(mark==1){
                    if (this->numflags>0){
                        cout<< "You have marked "<< this->numflags<< "flags."<<endl;
                    }
                    cout<<"Do you want to mark a flag?\n     1=yes, 0=no"<<endl;
                    cin>>mark;
                    if (mark==1){
                        cin>>r;
                        cin>>c;
                        markFlag(r,c);
                        if (!play){
                            mark=0;
                        }
                    }
                }
            
            }
        }
    }

}


void playGame::digNeighbors(int r, int c){
    for (int i=r-1;i<r+2;i++){
        for (int j=c-1;j<c+2;j++){
            if (i>=0 && j>=0 && i<this->row && j<this->col){
                if (i==r && j==c){
                    continue;
                }
                else{
                    if (seenBoard[i][j]==' '){
                        if (this->notSeenBoard[i][j]==0){
                            this->seenBoard[i][j]='0'; 
                            digNeighbors(i,j);

                        }
                        else if (this->notSeenBoard[i][j]==-1){
                            continue;
                        }
                        else{
                        this->seenBoard[i][j]=char(this->notSeenBoard[i][j]+48);  
                        }
                    }
                }
            }
        }
    }
    
}


int playGame::countSeenBoard(){
    int count=0;
     for(int i=0; i<this->row;i++){
        for (int j=0; j<this->col;j++){
            if (this->seenBoard[i][j]!=' ' && this->seenBoard[i][j]!='f'){
                count++;
            }
        }
    }
    return count;
}


void playGame::markFlag(int r, int c){
    if (this->numflags<this->mines){
        if (r>=0 && r<this->row && c>=0 && c<this->col){
            if (this->seenBoard[r][c]==' '){
                this->seenBoard[r][c]='f';
                this->numflags++;
            }
            printboard2(this->seenBoard);
            if (this->numflags==this->mines){
                checkFlags();
            }
        }
    }
    else{
        cout<< "Before you can add a flag you have to get rid of a flag or flags."<<endl;
        cout<< "You can only have "<<this->mines<<" flags.";
        int rid=1;
         do{
            if (this->numflags>0){
                cout<< "You have marked "<< this->numflags<< "flags."<<endl;
            }
            cout<<"Do you want to get rid of a flag?\n 1=yes, 0=no"<<endl;
            cin>>rid;
            if (rid==1){
                cin>>r;
                cin>>c;
                unmarkFlag(r,c);
            }
        }
        while(rid==1);

    }
}

void playGame::unmarkFlag(int r, int c){
    if (this->numflags>0){
         if (r>=0 && r<this->row && c>=0 && c<this->col){
            if (this->seenBoard[r][c]=='f'){
                this->seenBoard[r][c]=' ';
                this->numflags--;
            }
            printboard2(this->seenBoard);
        }
    }
}


void playGame::checkFlags(){
    int count=0;
    for (int i=0; i<this->row;i++){
        for (int j=0; j<this->col;j++){
            if (this->notSeenBoard[i][j]==-1 && this->seenBoard[i][j]=='f'){
                count++;
            }
        }
    }
    if (count==this->mines){
        this->play=false;
        cout <<"CONGRAGULATION!!!\n   YOU WON!!!"<<endl;
    }
}


