/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
#include <limits.h>

class Solution {
public:
    int guessNumber(int n) {
        long long left = 1;
        long long right = INT_MAX;
        while(left <= right)
        {
            long long mid = (left + right)/2;
            if(guess(mid) == 0)
                return mid;
            else if(guess(mid) == -1)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return -1;
    }
};