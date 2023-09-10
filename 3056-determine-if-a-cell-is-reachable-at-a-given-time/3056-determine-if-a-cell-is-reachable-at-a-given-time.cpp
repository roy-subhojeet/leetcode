class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dx = abs(fx - sx);
        int dy = abs(fy - sy);

        // Calculate distance in grid cells between the two points
        int distance = max(dx, dy);

        if (fx == sx && sy == fy && t == 1) return false;

        if (t >= distance) return true;

       

        return false;
    }
};