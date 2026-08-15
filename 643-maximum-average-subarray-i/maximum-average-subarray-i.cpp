class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int low=0;int high=k;long long sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];

        }
        double maxi=(double)sum/k;
        while(high<nums.size()){
            sum+=nums[high];
            sum-=nums[low];
            low++;
            high++;
            double ans=(double)sum/k;
            maxi=max(maxi,ans);

        }
        return maxi;
    }
};