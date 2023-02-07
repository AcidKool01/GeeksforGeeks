// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSafe(int row, int col, vector<vector<int>> &board){
        //For same Column
        for(int i=0; i<col; i++)
            if(board[row][i] == 1)
                return false;
        
        //For Upper Left Diagonal
        for(int i=row, j=col; i>=0 && j>=0; i--, j-- )
            if(board[i][j] == 1)
                return false;
        
        //For Upper Right Diagonal
        for(int i=row, j=col; i<board.size() && j>=0; i++, j--)
            if(board[i][j] == 1)
                return false;
        return true;
    }

    bool mcQueen(int col, int n, vector<vector<int>> &board, vector<vector<int>> &res){
        if(col == n) {
            vector<int> v;
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    if(board[i][j])
                        v.push_back(j+1);
            res.push_back(v);
            return true;
        }
        
        for(int row=0; row<n; row++){
            if(isSafe(row, col, board)){
                board[row][col] = 1;
                mcQueen(col+1, n, board, res);
                board[row][col] = 0;
            }
        }
        return false;
    }
    
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board(n, vector<int> (n, 0));
        vector<vector<int>> res;
        mcQueen(0, n, board, res);
        sort(res.begin(), res.end());
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends