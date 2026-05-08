class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
      vector<int> v(n,0);int j=0;
      for(int i=0;i<nums.size();i++){
         if(nums[i]!=0)
         v[j++]=nums[i];
      }
      for(int i=0;i<nums.size();i++){
        nums[i]=v[i];
      }  
    }
};