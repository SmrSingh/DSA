class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
      int n = hand.size();
        if (n % groupSize != 0) return false;

        unordered_map<int, int> freq;
        for (int card : hand) freq[card]++;

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto &p : freq) {
            minHeap.push(p.first);
        }

        while (!minHeap.empty()) {
            int start = minHeap.top();

            for (int i = 0; i < groupSize; i++) {
                int card = start + i;

                if (freq[card] == 0) return false;

                freq[card]--;
                 if (freq[card] == 0) {
                    if (minHeap.top() != card) return false;
                    minHeap.pop();
                }
            }
        }

        return true;  
    }
};