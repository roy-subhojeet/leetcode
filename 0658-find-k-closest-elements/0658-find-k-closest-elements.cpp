class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size() - k;
        
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(m + k < arr.size() && x - arr[m] > arr[m + k] - x){
                l = m + 1;
            } else {
                if(m > 0)
                    r = m - 1;
                else
                    break;
            }
        }
        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};