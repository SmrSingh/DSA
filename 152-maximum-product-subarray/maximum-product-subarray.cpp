class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1,sufix=1;int maxi=INT_MIN;int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(prefix==0)prefix=1;
            if(sufix==0)sufix=1;
            prefix*=nums[i];
            sufix*=nums[n-i-1];
            if(prefix>maxi || sufix>maxi)
            maxi=max(prefix,sufix);
        }
        return maxi;
    }
};