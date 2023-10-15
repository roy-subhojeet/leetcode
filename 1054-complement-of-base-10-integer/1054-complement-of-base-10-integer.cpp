class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        
        // Find the length of binary representation of n
        int length = 0;
        int temp = n;
        while (temp > 0) {
            length++;
            temp >>= 1;
        }
        
        // Compute complement using ~ operator
        int complement = ~n;
        
        // Only consider least significant bits using a mask
        return complement & ((1 << length) - 1);
    }
};
