class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
     int low=0;int high=0;unordered_map<int,int>mp;int maxi=0;
     while(high<nums.size()){
      mp[nums[high]]++;
      int l=high-low+1;
      while((l-mp[1])>k){
        mp[nums[low]]--;
        if(mp[nums[low]]==0)
        mp.erase(nums[low]);
        low++;
        l=high-low+1;

      }
      if ((l-mp[1])<=k){
        maxi=max(maxi,l);
      }
      high++;
     }
     return maxi;   
    }
};