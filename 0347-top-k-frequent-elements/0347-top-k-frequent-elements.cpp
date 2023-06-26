class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp; //{number:frequency}
        vector<int> res;
        for(auto &num:nums)
        {
            mp[num]++;
        }

        /* QuickSelect Algorithm */
        vector<pair<int, int>> p;
        for(auto &m: mp)
        {
            p.push_back({-m.second, m.first});
        }
        nth_element(p.begin(), p.begin()+k-1, p.end());
        for(int i = 0; i < k; i++)
        {
            res.push_back(p[i].second);
        }
        return res;

        /* Max Heap Solution 
        priority_queue<pair<int, int>> maxHeap; //{frequency:number}
        for(auto & elem: mp)
        {
            maxHeap.push({elem.second, elem.first});
            if(maxHeap.size() > mp.size() - k)
            {
                res.push_back(maxHeap.top().second);
                maxHeap.pop();
            }
        }
        return res;
        */

        /* Min Heap Solution
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for(auto &elem: mp)
        {
            minHeap.push({elem.second, elem.first});
            if(minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        while(!minHeap.empty())
        {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return res;
        */

        /* Bucket solution
         Each index in the li vector represents a frequency,
         and the vector at each index holds all the numbers that have that frequency.
         Hence +1 as vector 0 indexed.
        vector<vector<int>> li(nums.size() + 1);
        for(auto &m : mp)
        {
            li[m.second].push_back(m.first);
        }
        for(int i = li.size()-1; res.size() < k; i--)
        {
            for(auto &n: li[i])
            {
                res.emplace_back(n);
                if(res.size() == k)
                    break;
            }
        }
        return res;
        */
    }
};