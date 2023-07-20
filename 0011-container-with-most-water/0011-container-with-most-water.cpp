class Solution {
public:
    int maxArea(vector<int>& height) {
        int head = 0;
        int tail = height.size()-1;
        int maxArea = 0;
        while(head < tail)
        {
            int h = min(height[head], height[tail]);
            maxArea = max(maxArea, h * (tail - head));
            if(height[head] < height[tail])
                head++;
            else
                tail--;
        }
        return maxArea;
    }
};
