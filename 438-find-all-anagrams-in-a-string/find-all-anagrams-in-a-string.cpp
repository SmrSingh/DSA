class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       int n=s.length();vector<int> v;unordered_map<char,int>mp;unordered_map<char,int>need;
       int m=p.length();
       if(m>n) return {};
       int low=0;int high=m-1;
       for(int i=low;i<=high;i++){
         mp[s[i]]++;
         need[p[i]]++;
       } 
       if (mp==need)
       v.push_back(low);
       while(high<n){
        high++;
        mp[s[high]]++;
        mp[s[low]]--;
        if (mp[s[low]]==0)
        mp.erase(s[low]);
        low++;
        if(need==mp)
        v.push_back(low);

       }
       return v;
    }
};