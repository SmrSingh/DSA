class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      vector<int> l;vector<int> h;
      for(int i=0;i<nums.size();i++){
        if (nums[i]<0)
        l.push_back(nums[i]*nums[i]);
        else 
        h.push_back(nums[i]*nums[i]);
      } 
      reverse(l.begin(),l.end());
      int i=0,j=0;int idx=0;
      while(i<l.size() && j<h.size()){
       if (l[i]<h[j]){
       nums[idx++]=l[i];
       i++;}
       else 
       {
        nums[idx++]=h[j];
        j++;
       }

      }
      while(i<l.size()){
        nums[idx++]=l[i];
        i++;

      }
      while(j<h.size()){
        nums[idx++]=h[j];
        j++;
      } 
      return nums;
    }
};