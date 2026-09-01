class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
      class cmp{
        public:
        bool operator()(pair<int,string> &a,pair<int,string> &b){
         if(a.first!=b.first)
         return a.first>b.first;
         return a.second<b.second;
        }
      };
      unordered_map<string,int>mp;
      for(auto it:words){
        mp[it]++;
      }
      priority_queue<
            pair<int,string>,
            vector<pair<int,string>>,
            cmp
        > pq;

        // Put every word into heap
        for(auto it : mp) {

            pq.push({it.second, it.first});

            // Keep only k best words
            if(pq.size() > k)
                pq.pop();
        }

        vector<string> ans;

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        // Heap gives worst → best,
        // so reverse it.
        reverse(ans.begin(), ans.end());

        return ans;
    }
};