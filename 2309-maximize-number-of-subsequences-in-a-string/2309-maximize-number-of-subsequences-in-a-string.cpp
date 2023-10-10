class Solution {
public:
    long long maximumSubsequenceCount(string text, string pat) {
        long long ans1=0,ans2=0;

        
//         loop for calculate the answer if pattern[0] is in the begingging
        int m=1;
        for(int i=0;i<text.size();i++){
             if(pat[1]==text[i]){
                long long tp=m*1;
                ans1+=tp;
            }
            if(pat[0]==text[i]){
                m++;
            }
        }
//         loof for calculate teh answer if pattern[1] if in the end
        int p=1;
        for(int i=text.size()-1;i>=0;i--){
             if(pat[0]==text[i]){
                long long tp=p*1;
                ans2+=tp;
            }
            if(pat[1]==text[i]){
                p++;
            }
        }
        return max(ans1,ans2);
        
    }
};