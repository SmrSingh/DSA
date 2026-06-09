class Solution {
public:
    int totalFruit(vector<int>& fruits) {
      int low=0;int high=0;unordered_map<int,int> mp;int maxi=INT_MIN;
      while(high<fruits.size()){
        mp[fruits[high]]++;
        while(mp.size()>2){
            
            mp[fruits[low]]--;
            if(mp[fruits[low]]==0)
            mp.erase(fruits[low]);
            low++;

        }
        
        if(mp.size()<=2){
            int len=high-low+1;
            maxi=max(maxi,len);
            
        }
        high++;
      } 
      
      return maxi; 
      

    }
};