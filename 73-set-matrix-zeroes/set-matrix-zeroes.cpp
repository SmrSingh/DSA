class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
     vector<pair<int,int>> loc;
     int n=matrix.size();
     for(int i=0;i<n;i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==0)
            loc.push_back({i,j});
        }

     }
     while(!loc.empty()){
        auto ans=loc.back();
        loc.pop_back();
        int i=ans.first;
        int j=ans.second;
        for(int k=0;k<matrix[0].size();k++){
            matrix[i][k]=0;
        }
        for(int l=0;l<n;l++){
            matrix[l][j]=0;
        }
     }
     
    }

};