class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
     int low=0;int right=0;int sum=0;int ans=INT_MAX;
     while(right<nums.size()){
      sum+=nums[right];
      while(sum>=target){
        ans=min(ans,(right-low+1));
        sum-=nums[low];
        low++;

      }
      right++;
     } 
     return ans==INT_MAX?0: ans; 
    }
};