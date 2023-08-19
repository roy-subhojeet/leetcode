class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> arr(n, 0);
        int warmest = 0;

        for(int head = n-1; head >= 0; --head)
        {
            if(temperatures[head] >= warmest)
            {
                warmest = temperatures[head];
                continue;
            }

            int next = 1;
            while(temperatures[head] >= temperatures[head+next])
            {
                next += arr[head+next];
            }
            arr[head] = next;
        }
        return arr;
        /* O(N) - Time Complexity
           O(N) - Space Complexity
        stack<int> st;
        vector<int> res(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); ++i) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
        */

        /* initial attempt redundant checks
        stack<int> st;
        vector<int> res(temperatures.size(),0);

        for(int i = 0; i < temperatures.size(); ++i)
        {
            if(st.empty()) st.push(i);
            else if(temperatures[i] > temperatures[st.top()])
            {
                while(!st.empty() && temperatures[st.top()] < temperatures[i])
                {
                    //cout <<temperatures[i]  << " "<< st.top() << i<< endl;
                    res[st.top()] = i - st.top();
                    st.pop();
                }
                
                st.push(i);
            }

            else 
            {
                //cout <<"el" << temperatures[i] << i<< endl;
                st.push(i);
            }
        }
        return res;
        */

        /* O(n^2) Sliding window approach
        int left = 0;
        vector<int> ans;

        for(int i = 0; i < temperatures.size(); i++)
        {
            int right = left + 1;
            int count = 0;
            bool flag = false;
            
            while(right < temperatures.size())
            {
                if(temperatures[left] < temperatures[right]) 
                {
                    flag = true;
                    ans.push_back(right - left);
                    break;
                }
                if ((right == temperatures.size() - 1) && !flag)
                {
                    ans.push_back(0);
                    flag = false;
                }
                ++right;
            }
            
            ++left;
        }
        ans.push_back(0);
        return ans;
        */
    }
};