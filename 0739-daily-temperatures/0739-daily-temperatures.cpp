class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

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