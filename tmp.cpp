#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int n;
    cin>>n;

    char arr[n][n];

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>arr[i][j];
            cout<<arr[i][j];
        }
        cout<<endl;
    }

    int flagD=0;
    int flagS=0;

    char x = arr[0][0];
    char y = arr[0][1];

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if(i==j || i==n-1-j) {
                if(arr[i][j]!=x)
                    flagD=1;
            } else {
                if(arr[i][j]==x && arr[i][j]!=y) {
                    flagD=1;
                }
            }
        }
    } 

    if(!flagD) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }

	return 0;
}

