int Solution::solve(vector<int> &A) {
    stack<int> st;
    int root = INT_MIN;

    for (int i=0; i<A.size(); i++) {
        while(!st.empty() and A[i]>st.top()) {
            root = st.top();
            st.pop();
        }

        if (A[i]<root)
            return false;
        st.push(A[i]);
    }

    return true;
}