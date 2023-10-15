class Solution {
    int M=1000000007;
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int sum=0;
        long long int res=0;
        vector<int> arr2(arr);
        arr2.insert(arr2.end(),arr.begin(),arr.end());
        if(k==1) return largest(arr)%M;
        if(k==2) return largest(arr2)%M;
        for(int i:arr) sum+=i;
        if(sum>0)
        {
            res=(long long int)(k-2)*sum%M;
            res=(res+largest(arr2))%M;
        }
        else
        {
            res=largest(arr2)%M;
        }
        return res;
    }

    int largest(vector<int>& arr)
    {
        int best_sum = 0;
        int current_sum = 0;
        for (int x:arr)
        {
            current_sum = max(0, current_sum + x);
            best_sum = max(best_sum, current_sum);
        }
        return best_sum;      
    }
};