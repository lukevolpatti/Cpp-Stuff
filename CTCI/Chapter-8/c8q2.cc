// Robot in a grid
#include <iostream>
#include <vector>
using namespace std;

// Brute force. Recurse down, adding to the solution path at every new iteration. 
// If the location at a certain iteration is invalid, remove the addition to the 
// path and return 0 to indicate no path possible. 
int find_path(vector<vector<int> >& m, vector<pair<int, int> >& path, int x, int y){
	pair<int, int> p(x, y);
	path.push_back(p);

	if(m[x][y] == 0){ // can't be here!
		path.pop_back();
		return 0;
	}

	if(x == m.size() - 1 && y == m[0].size() - 1) // at the end
		return 1;

	if(x < m.size() - 1 && find_path(m, path, x + 1, y)) // found a path by increasing x
		return 1;

	if(y < m[0].size() - 1 && find_path(m, path, x, y + 1)) // found a path by increasing y
		return 1;

	// If we're here, we couldn't find any paths. Remove what we added to the
	// path and return 0.

	path.pop_back();
	return 0;
}

vector<pair<int, int> > path(vector<vector<int> >& m){
	vector<pair<int, int> > path;
	find_path(m, path, 0, 0);
	return path;
}


// Memoized version. We take notes of which locations we have already visited
// unsuccessfully. 
int find_path_memo(vector<vector<int> >& m, vector<pair<int, int> >& path, int x, int y){
	pair<int, int> p(x, y);
	path.push_back(p);

	if(m[x][y] == 0){ // can't be here!
		path.pop_back();
		return 0;
	}

	if(x == m.size() - 1 && y == m[0].size() - 1) // at the end
		return 1;

	if(x < m.size() - 1 && m[x + 1][y] == 1)
		if(find_path(m, path, x + 1, y)) return 1;
		m[x + 1][y] = 0;

	if(y < m[0].size() - 1 && m[x][y + 1] == 1)
		if(find_path(m, path, x, y + 1)) return 1; // found a path by increasing y
		m[x][y + 1] = 0;

	// If we're here, we couldn't find any paths. Remove what we added to the
	// path and return 0.

	path.pop_back();
	return 0;
}

vector<pair<int, int> > path_memo(vector<vector<int> >& m){
	vector<pair<int, int> > path;
	find_path(m, path, 0, 0);
	return path;
}

int main(){
    vector<vector<int> > grid(3, vector<int>(4, 1));
    grid[2][0] = 0;
    grid[1][1] = 0;
    grid[0][3] = 0;
    grid[2][2] = 0;
    vector<pair<int, int> > v = path(grid);
    for(int i = 0; i < v.size(); i++) 
        cout << v[i].first << " " << v[i].second << endl;
    cout << endl;
    vector<pair<int, int> > v2 = path_memo(grid);
    for(int i = 0; i < v2.size(); i++) 
        cout << v2[i].first << " " << v2[i].second << endl;
}