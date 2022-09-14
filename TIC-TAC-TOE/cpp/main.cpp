


#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

void printrules(){
    cout<<"the object of the game is to get 3 in a row\n";
    cout<<"how to play:\n";
    cout<< "press the number corresponding to the spot you want to play\n";
    cout<< "for the bottom left corner press 1\n";
    cout<< "for the bottom middle press 2\n";
    cout<< "for the bottom right corner press 3\n";
    cout<< "for the left middle press 4\n";
    cout<< "for the middle midlle press 5\n";
    cout<< "for the right middle press 6\n";
    cout<< "for the top left corner press 7\n";
    cout<< "for the top middle press 8\n";
    cout<< "for the top right corner press 9\n"<<endl;

}

void printboard(const char (&b)[3][3] ){
    cout<<'\n';
    for (int i=0; i<3;i++){
        for (int j=0; j<3;j++){
            cout<<b[i][j];
            if (j<2){
                cout<<'|';
            }
        }
        cout<<'\n';
        if (i<2){
            cout<<"- - -\n";
        }
    }
    cout<<'\n';
}

bool checkboard(const char (&b)[3][3] ){
    // check rows
    for(int i=0; i<3; i++){
        if (b[i][0]==b[i][1] && b[i][0]==b[i][2]){
            if (b[i][0]!=' '){
                return true;
            }
        }
    }
    // check cols
     for(int i=0; i<3; i++){
        if (b[0][i]==b[1][i] && b[0][i]==b[2][i]){
            if (b[0][i]!=' '){
                return true;
            }
        }
    }
    // check diag
    if (b[0][0]==b[1][1]&& b[0][0]==b[2][2]){
        if (b[0][0] !=' '){
            return true;
        }
    }
    if (b[0][2]==b[1][1]&& b[0][2]==b[2][0]){
        if (b[0][2] !=' '){
            return true;
        }
    }
    return false;
}

char check_for_winner(const char(&b)[3][3]){
    // check rows
    for(int i=0; i<3; i++){
        if (b[i][0]==b[i][1] && b[i][0]==b[i][2]){
            if (b[i][0]!=' '){
                return b[i][0];
            }
        }
    }
    // check cols
     for(int i=0; i<3; i++){
        if (b[0][i]==b[1][i] && b[0][i]==b[2][i]){
            if (b[0][i]!=' '){
                return b[i][0];
            }
        }
    }
    // check diag
    if (b[0][0]==b[1][1]&& b[0][0]==b[2][2]){
        if (b[0][0] !=' '){
            return b[0][0];
        }
    }
    if (b[0][2]==b[1][1]&& b[0][2]==b[2][0]){
        if (b[0][2] !=' '){
            return b[0][2];
        }
    }
    return '0';
}

void options_to_play(const char (&b)[3][3]){
    cout << "press the number of spot you want to play\n";
    if (b[2][0]==' '){
        cout<< "for the bottom left corner press 1\n";
    }
    if (b[2][1]==' '){
        cout<< "for the bottom middle press 2\n";
    }
    if (b[2][2]==' '){
        cout<< "for the bottom right corner press 3\n";
    }
    if (b[1][0]==' '){
        cout<< "for the left middle press 4\n";
    }
    if (b[1][1]==' '){
        cout<< "for the middle midlle press 5\n";
    }
    if (b[1][2]==' '){
        cout<< "for the right middle press 6\n";
    }
    if (b[0][0]==' '){
        cout<< "for the top left corner press 7\n";
    }
    if (b[0][1]==' '){
        cout<< "for the top middle press 8\n";
    }
    if (b[0][2]==' '){
        cout<< "for the top right corner press 9\n";
    }
   cout<<endl;
   
}

bool check_spot(const int spot,const char (&b)[3][3]){
    // cout<<spot<<endl;
    if (spot==1){
        if (b[2][0]==' '){
            return true;
        }
    }
    else if (spot==2){
        if (b[2][1]==' '){
            return true;
        }
    }
    else if (spot==3){
        if (b[2][2]==' '){
            return true;
        }
    }
    else if (spot==4){
        if (b[1][0]==' '){
            return true;
        }
    }
    else if (spot==5){
        if (b[1][1]==' '){
            return true;
        }
    }
    else if (spot==6){
        if (b[1][2]==' '){
            return true;
        }
    }
    else if (spot==7){
        if (b[0][0]==' '){
            return true;
        }
    }
    else if (spot==8){
        if (b[0][1]==' '){
            return true;
        }
    }
    else if (spot==9){
        if (b[0][2]==' '){
            return true;
        }
    }
    // either spot is taken or didnt give a number betwwen 1-9
    return false;

}

void update_board(const int spot, char (&b)[3][3], char c){
    if (spot==1){
        b[2][0]=c; 
    }
    else if (spot==2){
        b[2][1]=c; 
    }
    else if (spot==3){
        b[2][2]=c;  
    }
    else if (spot==4){
        b[1][0]=c;  
    }
    else if (spot==5){
        b[1][1]=c; 
    }
    else if (spot==6){
        b[1][2]=c;
    }
    
    else if (spot==7){
        b[0][0]=c;
    }
    else if (spot==8){
        b[0][1]=c;
    }
    else if (spot==9){
        b[0][2]=c;
    }
   
}


int main(){
    std::cout<<"lets play tic-tac-toe\n"<<std::endl;
    printrules();
    char board[3][3];
    for (int i=0; i<3;i++){
        for (int j=0; j<3;j++){
            board[i][j]=' ';
        }
    }
    
    printboard(board);
    bool play=true;
    int count=0;
    char player='x';
    while(play){
        // options_to_play(board);
        bool check = false;
        int spot;
        do {
            cin>>spot;
            check=check_spot(spot, board);
            if(!check){
                cout<<"this spot is taken please choose another spot"<<endl;
            }
        }
        while (!check);
        update_board(spot,board,player);
        count++;
        printboard(board);
        
        bool ans=checkboard(board);
        if (ans){
            char winner = check_for_winner(board);
            cout << "the winner of the game is player "<<winner<<endl;
            play=false;
        }
        // change player
        if (player=='x'){
            player='o';
        }
        else{
            player='x';
        }
        
        if (count == 9 && play){
            play = false;
            cout<< "the game ended in a tie"<<endl;
        }  
    }
    
    
    
    



    return 0;

}