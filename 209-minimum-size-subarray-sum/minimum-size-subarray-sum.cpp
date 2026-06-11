class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
     int low=0;int high=0;int sum=0;int minlen=INT_MAX;
     while(high<nums.size()){
         sum+=nums[high];
        while(sum>=target){
            minlen=min(minlen,(high-low+1));
            sum-=nums[low];
            low++;
        }
        high++;
     } 
     if(minlen == INT_MAX)
    return 0;
     return minlen;
      
    }
};