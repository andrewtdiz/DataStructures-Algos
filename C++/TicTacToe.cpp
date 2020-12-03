#include "iostream"
#include<string>
#include<algorithm>
using namespace std;


class TicTacToe {
    char board[9];
    int turn_count = 0;
public:
    char turn = 'X';
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
    void congratulate() {
        cout << "Congratulations, " << turn << "! You won! Play again? (1-Yes / 0-No) \n";

    };
    bool has_winner() {
        string row = "";
        string column = "";
        string diagonalL = "";
        string diagonalR = "";
        if(turn_count<5) return false;
        for(int i=0;i<3;i++) {
            row = "";
            column = "";
            diagonalL = "";
            diagonalR = "";
            for(int j=0;j<3;j++) {
                row += board[i*3+j];
                column += board[i+j*3];
                if(i==0) diagonalL += board[j*4];
                if(i==0) diagonalR += board[2+2*j];
            }
            if(row=="XXX" || row=="OOO") return true;
            if(column=="XXX" || column=="OOO") return true;
            if(diagonalL=="XXX" || diagonalL=="OOO") return true;
            if(diagonalR=="XXX" || diagonalR=="OOO") return true;
        }
        
        return false;
    };
    bool has_winner_display() {
        string row = "";
        string column = "";
        string diagonalL = "";
        string diagonalR = "";
        for(int i=0;i<3;i++) {
            row = "";
            column = "";
            diagonalL = "";
            diagonalR = "";
            for(int j=0;j<3;j++) {
                row += board[i*3+j];
                column += board[i+j*3];
                if(i==0) diagonalL += board[j*4];
                if(i==0) diagonalR += board[2+2*j];
            }
            if(row=="XXX") return true;
        }
        return false;
    };
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
            game.congratulate();
            selected_move = game.get_input();
            if(selected_move==0) is_playing = false; 
            game.clear_board();
        }
        if(was_valid) game.switch_turn();
    }
    cout << "GG!";
    
    return 0;
}
