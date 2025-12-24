class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     unordered_map<int, int> freq;
    for (int num : nums)
        freq[num]++;

    priority_queue<pair<int,int>> maxHeap;
    for (auto& it : freq)
        maxHeap.push({it.second, it.first});

    vector<int> result;
    while (k--) {
        result.push_back(maxHeap.top().second);
        maxHeap.pop();
    }

    return result;    
    }
};