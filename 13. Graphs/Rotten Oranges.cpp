// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int count = -1;
        queue<pair<int, int>> q;
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    grid[i][j] = 3;
                }
            }
        }
        
        while(!q.empty())
        {   
            int size = q.size();
            
            for (int i=0; i<size; i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                
                // instead of these repetetions in condititon and directions use a function and loop for respective cases.

                if(x>=0 && x<n && y+1>=0 && y+1<m &&grid[x][y+1]==1)
                {
                    q.push({x, y+1});
                    grid[x][y+1] = 3;
                }
                
                if(x>=0 && x<n && y-1>=0 && y-1<m &&grid[x][y-1]==1)
                {
                    q.push({x, y-1});
                    grid[x][y-1] = 3;
                }
                
                if(x+1>=0 && x+1<n && y>=0 && y<m &&grid[x+1][y]==1)
                {
                    q.push({x+1,y});
                    grid[x+1][y] = 3;
                }
                
                if(x-1>=0 && x-1<n && y>=0 && y<m &&grid[x-1][y]==1)
                {
                    q.push({x-1, y});
                    grid[x-1][y] = 3;
                }
                
                q.pop();
            }
            count++;
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        
        return count;
    }
};

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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
} 