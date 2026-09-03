class Solution {
public:
class cmp{
    public:
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        if(a.first!=b.first)
        return a.first<b.first;
        return a.second<b.second;
    }
};
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
      priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
      for(int i=0;i<mat.size();i++){
        int strength=0;
        for(auto it:mat[i]){
           strength+=it; 
        }
        pq.push({strength,i});
        if(pq.size()>k)
        pq.pop();
      }
      vector<int>ans;
      while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
      }
      reverse(ans.begin(),ans.end());
     return ans;   
    }
};