class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {


        stack<int> st;
        st.push(-1); // Sentinel value to avoid checking for empty stack
        int maxArea = 0;

        for(int i = 0; i < heights.size(); ++i) {
            // As long as the current bar's height is smaller than the height of the bar's index at the top of the stack,
            // it means that the current bar is limiting the "width" of the rectangle that can be formed using the bar 
            // at the top of the stack as the shortest bar.
            while(st.top() != -1 && heights[i] < heights[st.top()]) {
                //cout << heights[st.top()] << " "<< heights[i] << endl;
                int height = heights[st.top()];
                //cout << "pop " << st.top() << endl;
                st.pop();
                maxArea = max(maxArea, height * (i - st.top() - 1));
                //cout << maxArea << endl;
            }
            //cout << "push " << i << endl;
            st.push(i);
        }

        while (st.top() != -1) {
            int current_height = heights[st.top()];
            st.pop();
            int current_width = heights.size() - st.top() - 1;
            maxArea = max(maxArea, current_height * current_width);
        }

        return maxArea;







        // O(N^2)

        /*
        int maxArea = 0;

        for(int left = 0; left < heights.size(); ++left)
        {
            int minHeight = INT_MAX;
            for(int right = left; right < heights.size(); ++right)
            {
                minHeight = min(minHeight, heights[right]);
                if(left == right) maxArea = max(maxArea, heights[left] * 1); // redundant check
                else maxArea = max(maxArea, minHeight*(right - left + 1));
                cout << minHeight << " "<< maxArea << endl;
            }
        }
        return maxArea;
        */
    }
};