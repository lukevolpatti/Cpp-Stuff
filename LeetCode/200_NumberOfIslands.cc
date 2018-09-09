#include <vector>
using namespace std;

int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == '1') {
                markVisited(i, j, grid);
                count++;
            }
        }
    }
    return count;
}
void markVisited(int i, int j, vector<vector<char>>& grid){
    grid[i][j] = '0';
    if(i > 0 && grid[i - 1][j] == '1') markVisited(i - 1, j, grid);
    if(j > 0 && grid[i][j - 1] == '1') markVisited(i, j - 1, grid);
    if(i < grid.size() - 1 && grid[i + 1][j] == '1') markVisited(i + 1, j, grid);
    if(j < grid[0].size() - 1 && grid[i][j + 1] == '1') markVisited(i, j + 1, grid);
}

int main(){
	
}