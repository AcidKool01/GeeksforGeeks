#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&kp, vector<int>&tp, int n)
	{   
    	if(kp[0] == tp[0] && kp[1] == tp[1]) return 0;
        
        int board[n+1][n+1] = {0};
        int dir[][2] = {{-1, 2}, {-1, -2}, {1, -2}, {1, 2}, {-2, 1}, {-2, -1}, {2, 1}, {2, -1}};
        
        queue<pair<int, int>> q;
        q.push({kp[0]-1, kp[1]-1});
        board[tp[0]-1][tp[1]-1] = 2;
        
        int steps=0;
        
        while(!q.empty()){
            int siz = q.size();
            for(int i=0; i<siz; i++){
    	        auto p = q.front();
    	        int sr = p.first;
    	        int sc = p.second;
    	        q.pop();
    	        
    	        for(int d=0; d<8; d++){
    	            int r = sr + dir[d][0];
    	            int c = sc + dir[d][1];
    	            if(r>=0 && c>=0 && r<n && c<n){
    	                if(board[r][c]==2){
    	                    return steps+1;
    	                } else if(board[r][c]==0){
    	                    board[r][c] = -1;
    	                    q.push({r, c});
    	                }
    	            }
    	        }
            }
            steps++;
        }
        return -1;
	   
	}
	
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
} 