class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> res(n+1);
        res[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            res[i] = res[i&(i-1)] + 1;
        }
        return res;
    }

        /* O(nlog(n)) Sol 
        vector<int> res(n+1);
        if (n >=1)
        {
            res[0] = 0;
            res[1] = 1;
        }
        for(int i = 2 ; i <= n; i++)
        {
            int count = 0;
            int j = i;
            while(j!=0)
            {
                j = j&(j-1);
                ++count;
            }
            res[i] = count;
        }
        return res; 
    }
    */
};