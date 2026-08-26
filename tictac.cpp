#include<iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime> 

using namespace std;


char board[3][3];

void startBoard() {

    int num = 1;

    for(int i=0; i<3; i++) {

        for(int j=0; j<3; j++) {

            board[i][j] = num + '0';
            num++;
        }
    }
}

void drawboard() {

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

/*bool isEmpty(int pos){

    switch(pos){
        case 1:
            return board[0][0] != 'X' && board[0][0] != 'O';
        case 2:
            return board[0][1] != 'X' && board[0][1] != 'O';
        case 3:
            return board[0][2] != 'X' && board[0][2] != 'O';
        case 4:
            return board[1][0] != 'X' && board[1][0] != 'O';
        case 5:
            return board[1][1] != 'X' && board[1][1] != 'O';
        case 6:
            return board[1][2] != 'X' && board[1][2] != 'O';
        case 7:
            return board[2][0] != 'X' && board[2][0] != 'O';
        case 8:
            return board[2][1] != 'X' && board[2][1] != 'O';
        case 9:
            return board[2][2] != 'X' && board[2][2] != 'O';
    }

    return false;
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

void takeIPo(int pos){

    switch(pos){

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
}*/

//optimise isempty, inputx, inputo

bool isEmpty(int pos){
    int row= (pos-1)/3;
    int col= (pos-1)%3;

    return board[row][col]!= 'X' && board[row][col]!= 'O';
}

bool isBoardFull(){
    for(int i=0; i< 3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j]!= 'X' && board[i][j]!='O'){
                return false;
            }
        }
    }
    return true;
}

void makeMove(int pos, char player){
    int row= (pos-1)/3;
    int col= (pos-1)%3;

    board[row][col]= player;
}

char winner(char board[3][3]){

    for(int i=0; i<3; i++){

        if(board[i][0] == board[i][1] &&
           board[i][1] == board[i][2] &&
           (board[i][0] == 'X' || board[i][0] == 'O')){

            return board[i][0];
        }
    }

    
    for(int j=0; j<3; j++){

        if(board[0][j] == board[1][j] &&
           board[1][j] == board[2][j] &&
           (board[0][j] == 'X' || board[0][j] == 'O')){

            return board[0][j];
        }
    }

    if(board[0][0] == board[1][1] &&
       board[1][1] == board[2][2] &&
       (board[0][0] == 'X' || board[0][0] == 'O')){

        return board[0][0];
    }

    if(board[0][2] == board[1][1] &&
       board[1][1] == board[2][0] &&
       (board[0][2] == 'X' || board[0][2] == 'O')){

        return board[0][2];
    }

    return 0;
}



//minimax

int minimax(bool isMaximizing) {

    char result = winner(board);

    // AI wins
    if(result == 'O') {
        return 10;
    }

    // Player wins
    if(result == 'X') {
        return -10;
    }

    // Draw
    if(isBoardFull()) {
        return 0;
    }

    // AI's turn - maximize score
    if(isMaximizing) {

        int bestScore = -1000;

        for(int pos = 1; pos <= 9; pos++) {

            if(isEmpty(pos)) {

                makeMove(pos, 'O');

                int score = minimax(false);

                // Restore empty position
                makeMove(pos, '0' + pos);

                bestScore = max(bestScore, score);
            }
        }

        return bestScore;
    }

    // Player's turn - minimize score
    else {

        int bestScore = 1000;

        for(int pos = 1; pos <= 9; pos++) {

            if(isEmpty(pos)) {

                makeMove(pos, 'X');

                int score = minimax(true);

                // Restore empty position
                makeMove(pos, '0' + pos);

                bestScore = min(bestScore, score);
            }
        }

        return bestScore;
    }
}

int bestMove() {

    int bestScore = -1000;
    int move = -1;

    for(int pos = 1; pos <= 9; pos++) {

        if(isEmpty(pos)) {

            makeMove(pos, 'O');

            int score = minimax(false);

            makeMove(pos, '0' + pos);

            if(score > bestScore) {
                bestScore = score;
                move = pos;
            }
        }
    }

    return move;
}
//now including  AI moves

void aiMove() {

    int pos = bestMove();

    cout << "Computer's turn: " << pos << endl;

    makeMove(pos, 'O');
}

int main() {
    srand(time(0)); 

    int mode; 
    cout<< "Choose game ode: " << endl;
    cout<< "1. Player vs Player " << endl;
    cout<< "2. Player vs Computer " << endl;
    cout<< "Enter choice (1/2): " << endl;
    cin >> mode;

    startBoard();

    drawboard();

    for(int turn=0; turn<9; turn++) {
        int pos;
        if(turn % 2 == 0) {
            cout << "Player X enter position: ";
            cin >> pos;
            if(isEmpty(pos)){
                makeMove(pos, 'X');

                if(winner(board)!=0){
                    drawboard();
                    cout << "The winner is: "
                         << winner(board) << endl;
                    break;
                }
            }

            else{
                cout << "Position already occupied." << endl;
                turn--;
            }
        }

        else {
            if (mode==1){

                cout << "Player O enter position: ";
                cin >> pos;

                if(isEmpty(pos)){
                makeMove(pos, 'O');
                    if(winner(board)!=0){
                        drawboard();
                        cout << "The winner is: "
                        << winner(board) << endl;
                    break;
                }
            }

            else{

                cout << "Position already occupied." << endl;
                turn--;
            }
        }

        else if(mode==2){
                aiMove();

                if (winner(board)!=0){
                    drawboard();
                    cout<< "The winner is: "
                    << winner(board) << endl;
                    break;
                }
        }
        }
        

        drawboard();
    }

    return 0;
}