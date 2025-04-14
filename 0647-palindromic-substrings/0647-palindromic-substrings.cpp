class Solution {
public:
    int countSubstrings(string s) {
        int result=0;
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),0));
        for(int i=0;i<s.length();i++){
            dp[i][i]=1;
            result++;
        }

        for(int i=0;i<s.length()-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                result++;
            }
        }
        
        for(int len=3;len<=s.length();len++){
            for(int j=0;j<=s.length()-len;j++){
                int right=j+len-1;
                if(s[j]==s[right] && dp[j+1][right-1]==1){
                    dp[j][right]=1;
                    result++;
                }
            }
        }

        return result;
    }
};