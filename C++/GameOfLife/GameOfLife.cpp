#include "iostream"
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <windows.h>
using namespace std;


class GameOfLife {
    char board[400];
    vector< pair<int,int> > nodes;
    vector< pair<int,int> > search_nodes;
public: 
    void clear_board() {
        for(int i=0;i<400;i++) {
            board[i] = '_';
        }
    };
    void display_board(){
        for(int i=0;i<400;i++) {
            cout << board[i] << " ";
            if((i+1)%20==0 && i!=0) cout << "\n";
        }
    };
    void update_board() {
        int count;
        for (unsigned int i = 0; i < nodes.size(); i++) {
            assess_nodes(i);
        }
    };
    int assess_nodes(int i) {
        int count = 0;
        auto node = nodes[i];
        if(node.first % 20 != 0) {
            if(node.second!=20) {
                assess_single_node(node.first-1, node.second*20+1);
                count++;
            } 
            assess_single_node(node.first-1, node.second*20);
            count++;
            if(node.second!=0) {
                assess_single_node(node.first-1, node.second*20-1);
                count++;
            } 
        }
        if((node.first+1) % 20 != 0) {
            if(node.second!=20) {
                assess_single_node(node.first+1, node.second*20+1);
                count++;
            } 
            assess_single_node(node.first-1, node.second*20);
            count++;
            if(node.second!=0) {
                assess_single_node(node.first+1, node.second*20-1);
                count++;
            } 
        }
        if(node.second!=20) {
            assess_single_node(node.first, node.second*20+1);
            count++;
        }
        if(node.second!=0) {
            assess_single_node(node.first, node.second*20-1);
            count++;
        }
        return count;
    };
    void assess_single_node(int i,int j) {
        if(board[i+j]== 'X') insert_into_search_nodes(pair<int,int> (i,j));
    };
    void insert_into_search_nodes(pair<int,int> node){
        if(search_nodes.size()==0) search_nodes.push_back(node);
        for(pair<int,int>& x : search_nodes)  {
            
        }
    };
};

int main() {
    GameOfLife game;
    game.clear_board();
    game.display_board();
    game.update_board();
    return 0;
}