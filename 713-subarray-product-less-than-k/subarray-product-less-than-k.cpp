class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
      int low=0;int high=0;int prod=1;int count=0;
      if(k<=1)
      return 0;
      while(high<nums.size()){
        prod*=nums[high];
        while(prod>=k){
            prod/=nums[low];
            low++;
        }
        if(prod<k){
         count+=high-low+1;
        }
        high++;
      } 
      return count; 
    }
};