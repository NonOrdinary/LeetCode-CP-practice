class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>dp(nums.size()+1,0);
        int mx=1;
        int n=nums.size();
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[j]%nums[i]==0){
                    dp[i]=max(dp[j]+1,dp[i]);
                }
                mx=max(dp[i],mx);
            }
        }
        vector<int>result;
        int prev=1;
        for(int i=0;i<n;i++){
            if(mx==dp[i] && (nums[i]%prev)==0){
                prev=nums[i];
                mx--;
                result.push_back(nums[i]);
            }
        }

        return result;

    }
};