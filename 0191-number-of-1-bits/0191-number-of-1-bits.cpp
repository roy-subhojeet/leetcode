class Solution {
public:
    int hammingWeight(uint32_t n) {

        uint32_t num = n;
        int count = 0;
        while(num != 0)
        {
            num = num & (num-1);
            ++count;
        }
        return count;

        /* Simple Solution by Masking each bit at a time 
        int counter = 0;
        uint32_t mask = 1;
        for(int i=0; i<32; i++)
        {
            if((n&mask) != 0)
                ++counter;
            mask <<= 1;
        }
        return counter;
        */
    }
};