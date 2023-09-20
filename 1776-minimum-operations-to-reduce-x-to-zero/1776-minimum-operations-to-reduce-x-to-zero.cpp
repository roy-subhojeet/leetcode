class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int, int> prefixSum;
        unordered_map<int, int> suffixSum;
        int pSum= 0;
        int idx = 0;
        for(auto i : nums)
        {
            pSum += i;
            prefixSum[pSum] = idx;
            ++idx;
        }
        int sSum= 0;
        idx = 0;
        for(int i = nums.size() -1; i >=0; i--)
        {
            sSum += nums[i];
            suffixSum[sSum] = idx;
            ++idx;
        }
        auto psItr = prefixSum.find(x);
        auto ssItr = suffixSum.find(x);
        int ans = INT_MAX;

        if(psItr != prefixSum.end())
        {
            if(ssItr != suffixSum.end())
            {
                if(ssItr->second < psItr->second) ans = min(ans, ssItr->second + 1);
            }
            ans = min(ans, psItr->second + 1);
        }

        if(ssItr != suffixSum.end())
        {
            if(psItr != prefixSum.end())
            {
                if(psItr->second < ssItr->second) ans = min(ans, psItr->second + 1);
            }
            ans = min (ans, ssItr->second + 1);
        }
        
        for(auto& mp : prefixSum)
        {
            if(mp.first != pSum)
            {
                auto it = suffixSum.find(x - mp.first);
                if(it != suffixSum.end())
                {
                    if(it->first != pSum)
                    {
                        ans = min(ans, it->second + mp.second + 2);
                    }
                }
            }
        }

        if(ans != INT_MAX) return ans;

        return -1;


/*
        int left = 0;
        int right = nums.size() - 1;
        int ops = 0;
        int sum = 0;

        if(nums[left] == x || nums[right] == x) return 1;

        while(left <= right)
        {
            if(sum != x && nums[left] == x || sum !=x && nums[right] == x) return ops;
            if(nums[left] > x)
            {
                ++left;
                continue;
            }
            else if(nums[right] > x)
            {
                --right;
                continue;
            }

            if(nums[left] <= nums[right] && nums[right] < x)
            {
                sum += nums[right];
                --right;
                ++ops;
            }
            else if(nums[left] >= nums[right] && nums[left] < x)
            {
                sum += nums[left];
                ++left;
                ++ops;
            }
            if(sum == x) return ops;
        }
        return -1;
   */     
    }

};