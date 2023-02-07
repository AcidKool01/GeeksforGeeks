#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
 

// Simple fact is that in this Question 
// we just have to find out how many number of operations req !
// THE MAIN FACT IS --->
// WE CAN ONLY INCREAMENT the VALUES so 
// FOR MINIMUM OPERATION we have to make other row's / col's SUM 
// equal to the SUM of Maximum VAL present in a row/col

// SO lets assume a ROW contains max value SUM ,
//Then you just need to make other Rows also same as this Row ;
// So the Result Matrix Value = n* (Max_Val of any row/col present)
// but the actual sum of the given matrix = Total Sum;
// So total increament = RESULT MATRIX SUM - GIVEN MATRIX SUM ;


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        int maxRow = 0, maxCol = 0, total = 0;
        
        for (int i=0; i<n; i++)
        {   
            int rowSum = 0, colSum = 0;
            for (int j=0; j<n; j++)
            {
                rowSum+=matrix[i][j];
                colSum+=matrix[j][i];
                total+=matrix[i][j];
            }
            
            maxRow = max(rowSum, maxRow);
            maxCol = max(colSum, maxCol);
        }
        
        int res = max(maxCol, maxRow);
        
        return (n*res-total);
    } 
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}