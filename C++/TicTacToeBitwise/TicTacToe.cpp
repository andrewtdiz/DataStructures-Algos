#include "iostream"
#include<string>
#include<algorithm>
#include <cmath>
using namespace std;

// Note: This version uses bit manipulation. 
// Think of the board as a 18-bit integer where ever 2 bits is a cell of the board
//
// Example:
//    00         00       00       00 00 00         00          00             00
// top-left top-middle top-right     ...        bottom-left bottom-middle bottom-right
// Key:
// 00 = empty    10 = X     01 = O
class TicTacToe {
    int board = 0;
    int turn_count = 0;
public:
    bool is_over = false;
    char turn = 'X';
    void prompt_move() {
        cout << "It's your turn, " << turn << ". Enter a number 0-9 to move.\n";
    };
    bool player_move(int selected_move) {
        if(!cell_contains(selected_move) && !is_over) {
            board += (turn=='X') ? (1 << (selected_move)*2) : (2 << (selected_move)*2);
            turn_count++;
            is_over = has_winner();
            return true;
        }
        else {
            cout << "Oops! You can't move there." << "\n";
            return false;
        }
    };
    void switch_turn() {
        turn = turn=='X' ? 'O' : 'X';
    };
    void set_turn(char player) {
        turn = player;
    };
    void announce_move(int selected_move) {
        cout << turn << " moved to position " << selected_move << "\n\n";
    };
    void congratulate_winner() {
        cout << "Congratulations, " << turn << "! You won! Play again? (1-Yes / 0-No) \n";
    };
    void print_board() {
        string output;
        bool bit_manip;
        for(int i=0; i<3;++i) {
            for(int j=0;j<3;j++) {
                // Left side styling
                if(j%3==2) cout << "|  ";
                if(j%3==1) cout << "  ";
                // Fill with value (if applicable)
                if(cell_contains(i*3+j,'X')) {
                    cout << 'X';
                } else if(cell_contains(i*3+j,'O')) {
                    cout << 'O';
                } else {
                    cout << ' ';
                }
                // Right side styling
                if(j%3==0) cout << "  |";
                if(j%3==1) cout << "  ";
            }
            cout << "\n";
            if(i<2) cout << "-------------" << "\n";
        }
    };
    bool cell_contains(int i, char val = ' ') {
        if(val=='X') {
            return ((board & (1 << i*2))!=0);
        } else if(val=='O') {
            return ((board & (2 << i*2))!=0);
        } else {
            return ((board & (3 << i*2))!=0);
        }
        return false;
    }
    // This win-checker functions by looping through the rows, columns, and diagonals
    bool has_winner() {
        if(turn_count<5) return false;
        int row;
        int column;
        int diagonalL = 0;
        int diagonalR = 0;
        for(int i=0; i<3; i++) {
            row = 0;
            column = 0;
            for(int j=0;j<3;j++) {
                row += cell_contains(i*3+j,'X') ? 1 : cell_contains(i*3+j,'O') ? -1 : 0;
                column += cell_contains(i+j*3,'X') ? 1 : cell_contains(i+j*3,'O') ? -1 : 0;
            }
            diagonalL += cell_contains(i*4,'X') ? 1 : cell_contains(i*4,'O') ? -1 : 0;
            diagonalR += cell_contains(2+2*i,'X') ? 1 : cell_contains(2+2*i,'O') ? -1 : 0;
            if(abs(row)==3) return true;
            if(abs(column)==3) return true;
        }
        if(abs(diagonalL)==3) return true;
        if(abs(diagonalR)==3) return true;
        return false;
    };
    // Gets player input. Could be improved with more error-checking.
    int get_input() {
        int inp;
        cin >> inp;
        return inp;
    };
};

int main() {
    TicTacToe game;
    int selected_move;
    bool was_valid;
    char previous_winner;
    while(!game.is_over) {
        game.print_board();
        game.prompt_move();
        selected_move = game.get_input();
        game.announce_move(selected_move);
        was_valid = game.player_move(selected_move);
        if(game.is_over) {
            previous_winner = game.turn;
            game.print_board();
            game.congratulate_winner();
            selected_move = game.get_input();
            game = TicTacToe();
            game.set_turn(previous_winner=='X' ? 'O' : 'X');
        } else if(was_valid) game.switch_turn();
    }
    cout << "GG!";
    
    return 0;
}
