// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    
    bool flag = 0;
    
    void dfs(vector<vector<int>> &grid, int x, int y, int n, int m){
    
    if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0 || flag == 1)
        return;
    
    if(grid[x][y] == 2){
        flag = 1;
        return;
    }
    
    grid[x][y] = 0;
        
    dfs(grid, x + 1, y, n, m);
    dfs(grid, x - 1, y, n, m);
    dfs(grid, x, y + 1, n, m);
    dfs(grid, x, y - 1, n, m);
    
}

bool is_Possible(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int x = 0, y = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1){
                x = i, y = j;
                break;
            }
        }
    }
    
    dfs(grid, x, y, n, m);
    
    return flag;
}
    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends