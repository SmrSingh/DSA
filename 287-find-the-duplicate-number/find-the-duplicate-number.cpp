class Solution {
public:
    int findDuplicate(vector<int>& nums) {
     int slow=nums[0];
     int fast=nums[0];
     while(true){
        slow=nums[slow];
        fast=nums[fast];
        fast=nums[fast];
        if (fast==slow){
            slow=nums[0];
        while(fast!=slow){
         slow=nums[slow];
         fast=nums[fast];
        }
        return slow;
        }
     }
     return NULL ; 
    }
};