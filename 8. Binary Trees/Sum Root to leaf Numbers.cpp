int solve(TreeNode* A, int num){
    num=(num*10+A->val)%1003;

    if(A->left==NULL&&A->right==NULL)
        return num;

    int x=0, y=0;

    if(A->left) 
        x=solve(A->left,num);

    if(A->right) 
        y=solve(A->right,num);

     return x+y;
 }


int Solution::sumNumbers(TreeNode* A) {
    int num = 0;

    if(!A)
        return 0;

    int res = solve(A,0)%1003;

    return res;
}