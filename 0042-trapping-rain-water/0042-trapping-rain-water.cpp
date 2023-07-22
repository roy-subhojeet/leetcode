class Solution {
public:
    int trap(vector<int>& height)
    {
        int head = 0;
        int tail = height.size() -1;
        int headMax = 0;
        int tailMax = 0;
        int res = 0;
        while(head < tail)
        {
            if(height[head] < height[tail])
            {
                height[head] >= headMax ? headMax = height[head] : res += headMax- height[head];
                ++head;
            }
            else
            {
                height[tail] >= tailMax ? tailMax = height[tail] : res+= tailMax - height[tail];
                --tail;
            }
        }
        return res;

        /* Brute force
        int ans = 0;
        int size = height.size();
        for (int i = 1; i < size - 1; i++) {
            int left_max = 0, right_max = 0;
            //each index find the left max
            for (int j = i; j >= 0; j--) { //Search the left part for max bar size
                left_max = max(left_max, height[j]);
            }
            //each index find the right max
            for (int j = i; j < size; j++) { //Search the right part for max bar size
                right_max = max(right_max, height[j]);
            }
            //minimum of max height of walls on both side - own height
            ans += min(left_max, right_max) - height[i];
        }
        return ans;
        */
    
    }
};