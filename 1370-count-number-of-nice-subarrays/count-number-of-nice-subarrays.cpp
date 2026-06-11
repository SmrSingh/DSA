class Solution {
public:
 int atMost(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        int odd = 0;
        int count = 0;

        while (high < nums.size()) {

            if (nums[high] % 2 == 1)
                odd++;

            while (odd > k) {
                if (nums[low] % 2 == 1)
                    odd--;
                low++;
            }

            count += (high - low + 1);

            high++;
        }

        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
      return atMost(nums, k) - atMost(nums, k - 1);  
    }
};