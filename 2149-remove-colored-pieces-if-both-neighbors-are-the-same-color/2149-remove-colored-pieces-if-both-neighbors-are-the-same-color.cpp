class Solution {
public:
    bool winnerOfGame(string colors) {
        if(colors.size() < 3) return false;
        int countAliceWins = 0;
        int countBobWins = 0;
        int countA = 1;
        int countB = 1;
        char prev = colors[0];
        for(int i = 1; i < colors.size(); ++i)
        {
            if(colors[i] == 'A' and colors[i] == prev)
            {
                ++countA;
            }
            else if(colors[i] == 'B' and colors[i] == prev)
            {
                ++countB;
            }
            else
            {
                if(prev == 'A') 
                {
                    if(countA >= 3) countAliceWins += countA - 3 + 1;
                    countA = 0;
                    countB = 1;
                }
                else 
                {
                    if(countB >= 3) countBobWins += countB - 3 + 1;
                    countB = 0;
                    countA = 1;
                }
            }
            prev = colors[i];
        }
        if(countA >= 3) countAliceWins += countA - 3 + 1;
        if(countB >= 3) countBobWins += countB - 3 + 1;

        if(countAliceWins > countBobWins) return true;

        return false;
        
    }
};