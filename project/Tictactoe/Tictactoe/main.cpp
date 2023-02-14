//
//  main.cpp
//  Tictactoe
//
//  Created by Benita Alexander on 2/14/23.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

char board[3][3]={{'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}};

int choice;
int row,column;
char turn = 'X';
bool draw = false;
string winner="";

void display_board(){
    //cout<<"\t\t  |   |   \n";
    cout<<"\t\t"<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<"\n";
    cout<<"\t\t__|___|__\n";
    cout<<"\t\t  |   |   \n";
    cout<<"\t\t"<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<"\n";
    cout<<"\t\t__|___|__\n";
    cout<<"\t\t  |   |   \n";
    cout<<"\t\t"<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<"\n\n";
}

void players_turn(){
    if(turn =='X'){
        cout<<"\n\t Player 1 [X] turn: ";
    }else if(turn =='O'){
        cout<<"\n\t Player 2 [O] turn: ";
    }
    cin >> choice;
    
    switch (choice) {
        case 1: row=0; column =0; break;
        case 2: row=0; column =1; break;
        case 3: row=0; column =2; break;
        case 4: row=1; column =0; break;
        case 5: row=1; column =1; break;
        case 6: row=1; column =2; break;
        case 7: row=2; column =0; break;
        case 8: row=2; column =1; break;
        case 9: row=2; column =2; break;
            
        default:
            cout<<"\n Invalid Move";
            break;
    }
    
    if(turn =='X' && board[row][column] != 'X' && board[row][column]!='O'){
        board[row][column]='X';
        turn = 'O';
    }else if(turn =='O' && board[row][column] !='O' && board[row][column]!='X'){
        board[row][column]='O';
        turn ='X';
    }else{
        cout<<"Please Choose another Field \n";
        players_turn();
    }
   // display_board();
}

bool WinLoss(){
    for(int j=0;j<3;j++){
        if((board[0][j]==board[1][j] & board[1][j]==board[2][j]) ||
           (board[j][0]==board[j][1] & board[j][1]==board[j][2])){
            if((board[0][j]==board[1][j] & board[1][j]==board[2][j]) ){
                winner = board[0][j];
            }else{
                winner = board[j][0];
            }
            return false;
        }
    }
    if((board[0][0]==board[1][1] & board[1][1]==board[2][2]) ||
       (board[0][2]==board[1][1] & board[1][1]==board[2][0])){
        if((board[0][0]==board[1][1] & board[1][1]==board[2][2]) ){
            winner = board[0][0];
        }else{
            winner = board[0][2];
        }
        return false;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] !='X' && board[i][j]!='O'){
                return true;
            }
        }
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<"\t\t\tTic -- TAC -- TOE";
    cout<<"\n\t\t\t For Two Players\n\n";
    while(WinLoss()){
        display_board();
        players_turn();
        WinLoss();
    }
    cout<<"\n Winner is "<<winner<<"\n\n";
    
    
    return 0;
}
