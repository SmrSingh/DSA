class Solution {
public:
    int characterReplacement(string s, int k) {
       int low=0,high=0;unordered_map<char,int>mp;int maxi=INT_MIN;
       while(high<s.length()){
        mp[s[high]]++;
        int l=high-low+1;
        int maxFreq = 0;
        for (auto &p : mp) {
     maxFreq = max(maxFreq, p.second);
        }
        
        int v=l-maxFreq;
        while(v>k){
            mp[s[low]]--;
            if(mp[s[low]]==0)
            mp.erase(s[low]);
            low++;
            
        
        l=high-low+1;
        for (auto &p : mp) {
     maxFreq = max(maxFreq, p.second);
        }
        v=l-maxFreq;}
        
        
        if(v<=k){
        int len=high-low+1;
        maxi=max(maxi,len);
        }
         high++;
       }
       return maxi;
    }
};