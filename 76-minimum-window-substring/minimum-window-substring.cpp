class Solution {
public:
    string minWindow(string s, string t) {
      unordered_map<char, int> need;
        unordered_map<char, int> window;

        for (char c : t)
            need[c]++;

        int required = need.size();
        int formed = 0;

        int low = 0, high = 0;

        int minLen = INT_MAX;
        int start = 0;

        while (high < s.length()) {

            char ch = s[high];
            window[ch]++;

            if (need.count(ch) && window[ch] == need[ch])
                formed++;

            while (formed == required) {

                if (high - low + 1 < minLen) {
                    minLen = high - low + 1;
                    start = low;
                }

                char leftChar = s[low];

                window[leftChar]--;

                if (need.count(leftChar) &&
                    window[leftChar] < need[leftChar])
                    formed--;

                low++;
            }

            high++;
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);   
    }
};