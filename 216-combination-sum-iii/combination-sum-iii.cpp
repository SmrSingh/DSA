class Solution {
public:
void help(int i,int k,int sumTillNow,int n,vector<int> &subset,vector<vector<int>> &ans){
    if(k<0)
    return;
    if(sumTillNow == n){
        if(k==0){
            ans.push_back(subset);
        }
        return;
    }
    if(i==10)
    return;
    
    subset.push_back(i);
    help(i+1,k-1,sumTillNow +i,n,subset,ans);
    
    subset.pop_back();
    help(i+1,k,sumTillNow,n,subset,ans);
}
    vector<vector<int>> combinationSum3(int k, int n) {
     vector<int> subset;
     vector<vector<int>> ans;
     help(1,k,0,n,subset,ans);
     return ans;   
    }
};