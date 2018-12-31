// Eight queens
#include <iostream>
#include <vector>
using namespace std;

// Give a chess board, a row, and a column, check if we can put a queen at the
// specified location.
bool check(vector<vector<int> >& board, int row, int col){
    // No need to traverse rows; eightQueens makes sure there's only one queen
    // on the current row
    
    // Check column
    for(int i = 0; i < board[0].size(); i++) if(board[i][col]) return false;
    
    // Check top left to bottom right diagonal
    int r = row, c = col;
    while(r >= 0 && c >= 0){
        if(board[r][c]) return false;
        r--; c--;
    }
    r = row; c = col;
    while(r < board.size() && c < board[0].size()){
        if(board[r][c]) return false;
        r++; c++;
    }

    // Check bottom left to top right diagonal
    r = row; c = col;
    while(r < board.size() && c >= 0){
        if(board[r][c]) return false;
        r++; c--;
    }
    r = row; c = col;
    while(r >= 0 && c < board[0].size()){
        if(board[r][c]) return false;
        r--; c++;
    }

    return true;
}

// Use backtracking and check all possibilites. 
int eightQueens(vector<vector<int> >& board, int row){
    if(row >= board.size()) return 1;
    
    int count = 0;
    for(int col = 0; col < board[0].size(); col++){
        if(check(board, row, col)){
            board[row][col] = 1;
            count += eightQueens(board, row+1);
            board[row][col] = 0;
        }
    }
    return count;
}

int main(){
    vector<vector<int> > board(8, vector<int> (8));
    cout << eightQueens(board, 0) << endl;
}
