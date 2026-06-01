class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
      int low = 1;
        int high = maxPile(piles);

        while(low <= high){
            int mid = low + (high - low)/2;

            if(targeth(mid, piles.size(), piles) <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }

    int maxPile(vector<int>& piles){
        int maxi = INT_MIN;
        for(int x : piles)
            maxi = max(maxi, x);
        return maxi;
    }

    long long targeth(int mid, int n, vector<int>& piles){
        long long sum = 0;

        for(int i = 0; i < n; i++)
            sum += (piles[i] + mid - 1) / mid;

        return sum;  
    }
};