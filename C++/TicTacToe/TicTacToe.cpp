#include "iostream"
#include<string>
#include<algorithm>
#include <cmath>
using namespace std;

// Creates a TicTacToe Class that has all of the controllers for the game
class TicTacToe {
    char board[9];
    int turn_count = 0;
    char turn = 'X';
public:
    // Displays the game board to the terminal. 
    void print_board() {
        string output = "";
        for(int i=0; i<9;i++) {
            if(i%3==0) output = "";
            if(i%3==2 || i%3==1) output += "|  ";
            output += board[i]==' ' ? ' ' : board[i];
            if(i%3==0 || i%3==1) output += "  |";
            if(i%3==2) {
                cout << output << "\n";
                cout << "----------------" << "\n";
            }
        }
    };
    void clear_board() {
        for(int i=0;i<9;i++) board[i] = ' ';
    };
    void prompt_move() {
        cout << "It's your turn, " << turn << ". Enter a number 0-9 to move.\n";
    };
    bool player_move(int selected_move) {
        if(board[selected_move]==' ') { 
            board[selected_move] = turn; 
            turn_count++;
            return true;
        }
        else {
            cout << "Oops! " << ((turn=='X') ? 'O' : 'X') << " has already moved there." << "\n";
            return false;
        }
    };
    void switch_turn() {
        turn = turn=='X' ? 'O' : 'X';
    };
    void announce_move(int selected_move) {
        cout << turn << " moved to position " << selected_move << "\n\n";
    };
    void congratulate_winner() {
        cout << "Congratulations, " << turn << "! You won! Play again? (1-Yes / 0-No) \n";

    };
    // This win-checker functions by looping through the rows, columns, and diagonals
    bool has_winner() {
        int row;
        int column;
        int diagonalL;
        int diagonalR;
        if(turn_count<5) return false;
        for(int i=0;i<3;i++) {
            row = 0;
            column = 0;
            diagonalL = 0;
            diagonalR = 0;
            for(int j=0;j<3;j++) {
                row += (board[i*3+j]=='X') ? 1 : (board[i*3+j]=='O') ? -1 : 0;
                column += (board[i+j*3]=='X') ? 1 : (board[i+j*3]=='O') ? -1 : 0;
                if(i==0) diagonalL += (board[j*4]=='X') ? 1 : (board[j*4]=='O') ? -1 : 0;
                if(i==0) diagonalR += (board[2+2*j]=='X') ? 1 : (board[2+2*j]=='O') ? -1 : 0;
            }
            if(abs(row)==3) return true;
            if(abs(column)==3) return true;
            if(abs(diagonalL)==3) return true;
            if(abs(diagonalR)==3) return true;
        }
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
    bool is_playing = true;
    game.clear_board();
    while(is_playing) {
        game.print_board();
        game.prompt_move();
        selected_move = game.get_input();
        game.announce_move(selected_move);
        was_valid = game.player_move(selected_move);
        if(game.has_winner()) {
            game.print_board();
            game.congratulate_winner();
            selected_move = game.get_input();
            if(selected_move==0) is_playing = false; 
            game.clear_board();
        }
        if(was_valid) game.switch_turn();
    }
    cout << "GG!";
    
    return 0;
}
