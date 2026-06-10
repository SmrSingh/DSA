class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int low=0;int high=0;unordered_map<char,int> mp;int maxi=0;
       while(high<s.length()){
        mp[s[high]]++;
        int l=high-low+1;
        while(mp.size()<l){
            mp[s[low]]--;
            if(mp[s[low]]==0)
            mp.erase(s[low]);
            low++;
            l=high-low+1;

        }
        if(l==mp.size()){
          maxi=max(maxi,l);
        }
        high++;
       } 
       return maxi;
    }
};