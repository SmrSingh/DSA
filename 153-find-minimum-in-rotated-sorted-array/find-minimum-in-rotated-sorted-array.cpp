class Solution {
public:
    int findMin(vector<int>& nums) {
     int low=0;int right=nums.size()-1;int mid=-1;
     while(low< right){
         mid=(low+right)/2;
        if(nums[mid]>nums[right])
        low=mid+1;
        else 
        right=mid;
     }  
     return nums[low]; 
    }
};