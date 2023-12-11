class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int c=0,r=0,o=0,a=0,k=0;
        int ans=INT_MIN;
        int frogs=0;
        int n=croakOfFrogs.size();
        for(int i=0;i<n;i++){
            switch(croakOfFrogs[i]){
                case 'c':
                    frogs++;
                    c++;
                    break;
                case 'r':
                    r++;
                    break;
                case 'o':
                    o++;
                    break;
                case 'a':
                    a++;
                    break;
                case 'k':
                    k++;
                    frogs--;
                    break;
            }
            ans=max(ans,frogs);
            if(c<r || r<o || o<a || a<k) return -1;
            
        }
        return frogs==0?ans:-1;
    }
};