class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        if(size < n) return false;

        int count = 0;
        for(int i = 0; i < flowerbed.size() ; ++i)
        {
            if(i+1 >= size && i-1 < 0 && flowerbed[i] == 0) ++ count;
            else if(i==0 && flowerbed[i] == 0 && flowerbed[i+1] == 0)
            {
                flowerbed[i] = 1;
                ++count;
            }
            else if(i > 0 && flowerbed[i-1] == 0 && flowerbed[i] == 0 && i+1 < size && flowerbed[i+1] == 0) 
            {
                flowerbed[i] = 1;
                ++count;
            }
            else if(i-1 > 0 && i == size-1 && flowerbed[i] == 0 && flowerbed[i-1] == 0) 
            {
                flowerbed[i] = 1;
                ++count;
            }
            if(count >= n) return true;
        }
        cout << count;
       

        return false;
        
    }
};