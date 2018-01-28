// Battleships in a board
#include<iostream>
#include<vector>
using namespace std;
int countBattleships(vector< vector <char> >& board) {
        int count = 0;
        int size = board.size();
        int inner_size = board[0].size();
        for(int i = 0; i < size; i++){
            for(int j = 0; j < inner_size; j++){
                if(i == size-1 && j == inner_size-1 && board[i][j] == 'X') count++;
                else if(i == size-1 && board[i][j] == 'X'){
                    if(board[i][j+1] == '.') count++;
                }
                else if(j == inner_size-1 && board[i][j] == 'X'){
                    if(board[i+1][j] == '.') count++;
                }
                else if(board[i+1][j] == '.' && board[i][j+1] == '.' && board[i][j] == 'X') count++;
            }
        }
        return count;
}

int main(){

}