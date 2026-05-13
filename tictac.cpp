#include<iostream>
using namespace std;

char board[3][3];

void startBoard() {

    int num = 1;

    for (int i=0; i<3; i++) {

        for(int j=0; j<3; j++) {

            board[i][j] = num + '0';
            num++;
        }
    }
}

void drawboard(){

    cout << board[0][0] << "|" ;
    cout << board[0][1] << "|" ;
    cout << board[0][2] << endl;

    cout << "_________" << endl;

    cout << board[1][0] << "|" ;
    cout << board[1][1] << "|" ;
    cout << board[1][2] << endl;

    cout << "_________" << endl;

    cout << board[2][0] << "|" ;
    cout << board[2][1] << "|" ;
    cout << board[2][2] << endl;

    cout << endl;
}

void takeIPx(int pos){

    switch(pos){

        case 1:
            board[0][0]= 'X';
            break;

        case 2:
            board[0][1]= 'X';
            break;

        case 3:
            board[0][2]= 'X';
            break;

        case 4:
            board[1][0]= 'X';
            break;

        case 5:
            board[1][1]= 'X';
            break;

        case 6:
            board[1][2]= 'X';
            break;

        case 7:
            board[2][0]= 'X';
            break;

        case 8:
            board[2][1]= 'X';
            break;

        case 9:
            board[2][2]= 'X';
            break;
    }
}

void takeIPo(int pos1){

    switch(pos1){

        case 1:
            board[0][0]= 'O';
            break;

        case 2:
            board[0][1]= 'O';
            break;

        case 3:
            board[0][2]= 'O';
            break;

        case 4:
            board[1][0]= 'O';
            break;

        case 5:
            board[1][1]= 'O';
            break;

        case 6:
            board[1][2]= 'O';
            break;

        case 7:
            board[2][0]= 'O';
            break;

        case 8:
            board[2][1]= 'O';
            break;

        case 9:
            board[2][2]= 'O';
            break;
    }
}

char winner(char board[3][3]){
    for (int i=0; i<3; i++){
        for (int j=0; j< 3; j++){
            if (board[i][j]== board[i][j+1] && board[i][j+1]== board[i][j+2]){
                return board[i][j];
            }
            else if (board[i][j]== board[i+1][j] && board[i+1][j] == board[i+2][j]){
                return board[i][j];
            }
            else if( board[i][i]==board[i+1][i+1]&& board[i+1][i+1]== board[i+2][i+2]){
                return board[i][i];
            }
            else if(board[0][2]==board[1][1]&& board[1][1] == board[2][0]){
                return board[0][2];
            }
        }
        
    }
    return 0;
}

int main() {

    startBoard();

    drawboard();

    for(int turn=0; turn<9; turn++) {

        int pos;

        if(turn % 2 == 0) {

            cout << "Player X enter position: ";
            cin >> pos;

            takeIPx(pos);
            drawboard();
            if(winner(board)!=0){
                cout<< "The winner is: "<< winner(board)<< endl;
                break;

            }
            
            
        }

        else {

            cout << "Player O enter position: ";
            cin >> pos;

            takeIPo(pos);
            drawboard();
            if(winner(board)!=0){
                cout<< "The winner is: "<< winner(board)<< endl;
                break;

            }
            
        }

        
        

        

    }

    //cout<< "Winner is: "<< winner(board)<< endl;

    return 0;
}