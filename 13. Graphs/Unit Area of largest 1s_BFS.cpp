// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find unit area of the largest region of 1s.

    int bfs(int i, int j, int n, int m, int g[SIZE][SIZE], bool vis[SIZE][SIZE])
    {
        int x_path[] = {1, 1, 0, -1, -1, -1, 0, 1};
        int y_path[] = {0, 1, 1, 1, 0, -1, -1, -1};

        int cnt = 1;

        queue<pair<int, int>> Q;
        Q.push(make_pair(i, j));
        vis[i][j] = true;

        while (!Q.empty())
        {
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();

            for (int i = 0; i < 8; i++)
            {
                int xx = x + x_path[i];
                int yy = y + y_path[i];

                if (xx >= 0 && yy >= 0 && xx < n && yy < m && g[xx][yy] == 1 && vis[xx][yy] == false)
                {
                    cnt++;
                    Q.push(make_pair(xx, yy));
                    vis[xx][yy] = true;
                }
            }
        }

        return cnt;
    }

    int findAreaUtil(int n, int m, int g[SIZE][SIZE], bool vis[SIZE][SIZE])
    {

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (g[i][j] == 1 and !vis[i][j])
                {
                    int curr = bfs(i, j, n, m, g, vis);
                    ans = max(ans, curr);
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.findMaxArea(grid);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends
