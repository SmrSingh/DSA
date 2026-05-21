class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;int right=nums.size()-1;
        while(low<=right){
            int mid=(low+right)/2;
            if(nums[mid]==target)
            return mid;
        
        else if(nums[low]<=nums[mid]){
            if(nums[low]<=target && target<nums[mid])
            right=mid-1;
        
            else{
            low=mid+1;
        }
        }
        else {
            if(nums[mid]<target && nums[right]>=target){
                low=mid+1;
            }
            else 
            right=mid-1;

        }
    }
    return -1;
    }
};