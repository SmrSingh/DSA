class Solution {
public:
    vector<vector<int>> generate(int numRows) {
     vector<vector<int>> ans;
     
     for(int i=0;i<numRows;i++){
        vector<int> row(i+1,1);
        if(i>0){
        vector<int>& prev=ans.back();
     
        

        for(int j=1;j<i;j++){
        row[j]=prev[j-1]+prev[j];
        }}
        ans.push_back(row);
       
            } 
            return ans;  
    }
};