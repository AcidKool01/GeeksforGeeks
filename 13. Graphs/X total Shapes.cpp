#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    
    void dfs(int i, int j, int n, int m, vector<vector<char>> &grid)
    {
        if (i>=n || j>=m || i<0 || j<0 || grid[i][j] != 'X')
            return;
        
        grid[i][j] = '0';
        dfs(i - 1, j, n, m, grid);
        dfs(i, j - 1, n, m, grid);
        dfs(i, j + 1, n, m, grid);
        dfs(i + 1, j, n, m, grid);
    }
    
    int xShape(vector<vector<char>>& grid) 
    {   
        int count = 0;
        int row = grid.size();
        int col = grid[0].size();
        
        for(int i=0; i<grid.size(); i++)
        {
            for (int j=0; j<grid[i].size(); j++)
            {
                if(grid[i][j]=='X')
                {
                    dfs(i, j, row, col, grid);
                    count++;
                }
            }
        }
        
        return count;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends