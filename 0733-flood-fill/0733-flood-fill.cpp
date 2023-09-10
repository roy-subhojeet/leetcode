class Solution {
public:

    vector<vector<int>> fill(int y, int x, int color, vector<vector<int>>& image, int val)
    {
        if(!(x >= 0 && x < image[0].size() && y >= 0 && y < image.size())) return image;
        if(image[y][x] != val) return image;
        image[y][x] = color;
        image = fill(y, x+1, color, image , val);
        image = fill(y, x-1, color, image, val);
        image = fill(y+1, x, color, image, val);
        image = fill(y-1, x, color, image, val);
        return image;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        int m = image.size();
        int n = image[0].size();
         
        return fill(sr, sc, color, image, image[sr][sc]);
        
    }
};