class Solution {
public:
    int compress(vector<char>& chars) {
        int j = 0;
        for(int i = 0; i < chars.size(); ++i)
        {

                int groupSize = 0;
                while(i+groupSize < chars.size()-1 && chars[i+groupSize] == chars[i+groupSize+1])
                {
                    ++groupSize;
                }
                if(groupSize > 0 && groupSize < 9)
                {
                    chars[j] = chars[i+groupSize];
                    chars[j+1] = groupSize + 1 + '0';
                    if(j+2 < chars.size()-1 && i+groupSize < chars.size()-1) chars[j+2] = chars[i+groupSize+1];
                    j +=2;
                }
                else if(groupSize >= 9)
                { 
                    string temp = to_string(groupSize+1);
                    int c = temp.size();
                    chars[j] = chars[i+groupSize];
                    ++j;
                    int idx = 0;
                    while(c>0)
                    {
                        chars[j] = temp[idx];
                        ++idx;
                        --c;
                        ++j;
                    }
                }
                else 
                {
                    chars[j] = chars[i+groupSize];
                    ++j;
                }

                i += groupSize;

        }
        return j;
    }
};