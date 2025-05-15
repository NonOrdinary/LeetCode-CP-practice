class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<int>dp(groups.size(),0);
        /*The standard 0(N^2) soln suggest that dp[i]=length of max subsequence starting 
        as ith element as first element of the resultant subsequence,then we just backtrack
        using length and group variable
        TC=O(n2)
        SC=O(n)*/
        dp.back()=1;
        for(int i=(int)groups.size()-2;i>=0;i--){
            for(int j=i+1;j<groups.size();j++){
                if(groups[i]!=groups[j]){
                    dp[i]=max(1+dp[j],dp[i]);
                }
            }
        }

        int length=*max_element(dp.begin(),dp.end());
        int group=-1;
        vector<string>result;
        for(int i=0;i<groups.size();i++){
            if(dp[i]==length && groups[i]!=group){
                result.push_back(words[i]);
                length--;
                group=groups[i];
            }
        }

        return result;
    }
};