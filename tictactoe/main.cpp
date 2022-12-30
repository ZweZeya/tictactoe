//
//  main.cpp
//  tictactoe
//
//  Created by Zwe Zeya on 29/12/22.
//

#include <iostream>
#include <vector>
using namespace std;


class Tictactoe {
    
private:
    vector<vector<char>> moves;
    int checkRow();
    int checkCol();
    int checkLeftDiagonal();
    int checkRightDiagonal();
    
public:
    
    Tictactoe();
    void displayGrid();
    bool validMove(int row, int col);
    void addMoves(int row, int col, int player);
    bool checkFilled();
    int getWinner();
    bool announceResult();
    
};

// Constructor
Tictactoe::Tictactoe(){
    vector<char> row;
    for (int i = 0; i < 3; i++) {
        row.push_back(' ');
    };
    for (int i = 0; i < 3; i++) {
        moves.push_back(row);
    };
};

// Display the game board
void Tictactoe::displayGrid() {
    cout << endl;
    cout << "     |     |    " << endl;
    cout << "  " << moves[0][0] << "  |  " << moves[0][1] << "  |  "
         << moves[0][2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |    " << endl;
    cout << "  " << moves[1][0] << "  |  " << moves[1][1] << "  |  "
         << moves[1][2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |    " << endl;
    cout << "  " << moves[2][0] << "  |  " << moves[2][1] << "  |  "
         << moves[2][2] << "  " << endl;
    cout << "     |     |    " << endl <<endl;
};

// Check if a given move is a valid move
bool Tictactoe::validMove(int row, int col) {
    if (row > 2 || col > 2) {
        return false;
    } else if (row < 0 || col < 0) {
        return false;
    } else if (moves[row][col] == ' ') {
        return true;
    }
    return false;
};

// Records the players moves
void Tictactoe::addMoves(int row, int col, int player) {
    if (player == 1) {
        moves[row][col] = 'X';
    } else if (player == 2) {
        moves[row][col] = 'O';
    }
};

// Check each row for a win
int Tictactoe::checkRow() {
    int row, col;
    for (row = 0; row < 3; row++) {
        int sum1 = 0;
        int sum2 = 0;
        for (col = 0; col < 3; col++) {
            if (moves[row][col] == 'X') {
                sum1++;
            } else if (moves[row][col] == 'O') {
                sum2++;
            }
        };
        if (sum1 == 3) {
            return 1;
        } else if (sum2 == 3) {
            return 2;
        }
    };
    return 0;
};

// Check each column for a win
int Tictactoe::checkCol() {
    int row, col;
    for (col = 0; col < 3; col++) {
        int sum1 = 0;
        int sum2 = 0;
        for (row = 0; row < 3; row++) {
            if (moves[row][col] == 'X') {
                sum1++;
            } else if (moves[row][col] == 'O') {
                sum2++;
            }
        };
        if (sum1 == 3) {
            return 1;
        } else if (sum2 == 3) {
            return 2;
        }
    };
    return 0;
};

// Check left diagonal for a win
int Tictactoe::checkLeftDiagonal() {
    int i;
    int sum1 = 0;
    int sum2 = 0;
    for (i = 0; i < 3; i++) {
        if (moves[i][i] == 'X') {
            sum1++;
        } else if (moves[i][i] == 'O') {
            sum2++;
        }
    };
    if (sum1 == 3) {
        return 1;
    } else if (sum2 == 3) {
        return 2;
    }
    return 0;
};
// Check right diagonal for a win
int Tictactoe::checkRightDiagonal() {
    if (moves[0][2] == 'X' && moves[1][1] == 'X' && moves[2][0] == 'X') {
        return 1;
    } else if (moves[0][2] == 'O' && moves[1][1] == 'O' && moves[2][0] == 'O') {
        return 2;
    }
    return 0;
};

// Check if the grid is fully filled
bool Tictactoe::checkFilled() {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (moves[i][j] == ' ') {
                sum++;
            }
        }
    }
    if (sum == 0) {
        return true;
    };
    return false;
}

// Return the winner of the game
int Tictactoe::getWinner() {
    if (checkCol() == 1 || checkRow() == 1 || checkLeftDiagonal() == 1 || checkRightDiagonal() == 1) {
        return 1;
    } else if (checkCol() == 2 || checkRow() == 2 || checkLeftDiagonal() == 2 || checkRightDiagonal() == 2) {
        return 2;
    } else if (checkFilled() == true) {
        return 3;
    }
    return 0;
};

// Display the results
bool Tictactoe::announceResult() {
    if (getWinner() == 1) {
        cout<< "Player 1 wins" <<endl;
        return true;
    } else if (getWinner() == 2) {
        cout<< "Player 2 wins" <<endl;
        return true;
    } else if (getWinner() == 3) {
        cout<< "Draw" <<endl;
        return true;
    };
    return false;
};

int main() {
    // Create a new game
    Tictactoe game;
    while(game.getWinner() == 0) {
        
        game.displayGrid();
        
        int c1, c2, r1, r2;
        
        // Player 1
        cout<< "Player 1's turn" <<endl <<"Enter move: ";
        cin>> r1 >>c1;
        while(game.validMove(r1, c1) == false) {
            cout<< "Invalid move"<<endl <<"Enter move: ";
            cin>> r1 >>c1;
        };
        game.addMoves(r1, c1, 1);
        game.displayGrid();
        if (game.announceResult() == true) {
            break;
        }
        
        // Player 2
        cout<< "Player 2's turn" <<endl <<"Enter move: ";
        cin>> r2 >>c2;
        while(game.validMove(r2, c2) == false) {
            cout<< "Invalid move"<<endl <<"Enter move: ";
            cin>> r2 >>c2;
        };
        game.addMoves(r2, c2, 2);
        if (game.announceResult() == true) {
            game.displayGrid();
            break;
        }
    };
    return 0;
}
