class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int left=0;int right= nums.size()-1;int ans=-1;
       while(left<=right){
        int mid=(left+right)/2;
        if (nums[mid]==target){
            ans=mid;
            right=mid-1;
        }
        else if(target>nums[mid]) 
        left=mid+1;
        else  right=mid-1;
       } 
       int low=0;int high=nums.size()-1;int ans2=-1;
       while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            ans2=mid;
            low=mid+1;
        }
        else if (target<nums[mid])
        high=mid-1;
        else 
        low=mid+1;
       } 
       return {ans,ans2};
       
    }
};