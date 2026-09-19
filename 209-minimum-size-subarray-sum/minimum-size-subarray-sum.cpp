class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int low=0;int right=0;int ans=INT_MAX;int sum=0;
       while(right<nums.size()){
        sum+=nums[right];
        while(sum>=target){
            ans=min(ans,right-low+1);
            sum-=nums[low];
            low++;
        }
        right++;
       }
       if(ans!=INT_MAX) 
       return ans;
       else return 0;
    }
};