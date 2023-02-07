// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid, int &ans, int &maxi)
    {
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0)
        {
            maxi = max(ans, maxi);
            return;
        }
            
        grid[i][j] = 0;
        ans++;
        
        dfs(i-1, j, n, m, grid, ans, maxi);
        dfs(i+1, j, n, m, grid, ans, maxi);
        dfs(i, j-1, n, m, grid, ans, maxi);
        dfs(i, j+1, n, m, grid, ans, maxi);
        
        dfs(i-1, j+1, n, m, grid, ans, maxi);
        dfs(i-1, j-1, n, m, grid, ans, maxi);
        dfs(i+1, j+1, n, m, grid, ans, maxi);
        dfs(i+1, j-1, n, m, grid, ans, maxi);
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        int maxi = 0;
        
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {   
                if(grid[i][j]==1)
                {
                    dfs(i, j, n, m, grid ,ans, maxi);
                    ans = 0;
                }
            }
        }
        
        return maxi;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends