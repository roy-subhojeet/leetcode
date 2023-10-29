class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int left = 1; // speed of eating / hour
        int right = *max_element(piles.begin(), piles.end());
        int ans;

        while(left <= right)
        {
            int mid = left - (left - right)/2;
            long int totalHours = 0;

            for(auto &p : piles)
            {
                totalHours += (p/(mid)) + (p%mid != 0);
                //cout << totalHours << endl;
            }

            if(totalHours <= h) 
            {
                ans = mid;
                right = mid - 1;
            }

            if(totalHours > h) left = mid + 1;

        }
        return ans;
    }
};