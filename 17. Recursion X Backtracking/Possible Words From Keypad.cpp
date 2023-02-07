#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    
    void solve (unordered_map<int, string> &keypad, string temp, int N, int a[], int i, vector<string> &vec) {
        if(i>=N) {
            vec.push_back(temp);
            temp="";
            i=0;
            return;
        }
        
        for (int k=0; k<keypad[a[i]].size(); k++) {
                solve(keypad, temp+keypad[a[i]][k], N, a, i+1, vec);
        }
    }
    
    vector<string> possibleWords(int a[], int N)
    {
        unordered_map<int, string> keypad;
        keypad[2] = "abc", keypad[3] = "def", keypad[4] = "ghi",
        keypad[5] = "jkl", keypad[6] = "mno", keypad[7] = "pqrs",
        keypad[8] = "tuv", keypad[9] = "wxyz";
        
        vector<string> vec;
        solve(keypad, "", N, a, 0, vec);
        
        return vec;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}