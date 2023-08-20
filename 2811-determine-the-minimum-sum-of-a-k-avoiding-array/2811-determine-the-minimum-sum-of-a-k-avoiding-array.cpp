#include <unordered_set>
using namespace std;

class Solution {
public:
    int minimumSum(int n, int k) {
        /* O(N)
        unordered_set<int> st;  // Use a set to store numbers and allow O(1) average-time lookups.

        int ans = 0;  // This will hold our final answer (the sum of our k-avoiding array).
        
        // Start from 1 and try to construct the array with n numbers.
        // 'i' will be our candidate number to add to the array.
        for(int i = 1; st.size() < n; ++i) {  

            // Before adding 'i' to our set, check if 'k - i' exists in our set.
            // If 'k - i' exists, then adding 'i' would create a pair that sums up to 'k'.
            // The intuition is to avoid numbers that when added to existing numbers in our set will sum up to k.
            if(st.find(k - i) == st.end()) {  

                st.insert(i);  // If 'k - i' doesn't exist, it's safe to add 'i' to our set.
                ans += i;  // Add the current 'i' to our answer.
            }
        }
        
        return ans;  // Return the sum of our k-avoiding array.
        */

        // O(N^2)

        vector<int> res;
        int i = 1;
        int ans = 0;
        while(res.size() < n)
        {
            bool addFlag = true;
            for(auto & nums: res)
            {
                if(i + nums == k) 
                {
                    addFlag = false; 
                    break;
                }
            }
            if(addFlag) 
            {
                res.push_back(i);
                ans +=i;
            }
            ++i;
        }
        return ans;

    }
};
