class Solution {
public:
    bool tabulation(vector<int>&nums,int &sum){
    int n=nums.size();
    vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    if(sum>=nums[0]){
        dp[1][nums[0]]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=sum;j++){
            bool pick=0;
            if(nums[i]<=j){
                pick=dp[i-1][j-nums[i]];
            }
            bool notPick=dp[i-1][j];
            dp[i][j]=pick|notPick;
        }
    }
    return dp[n-1][sum];
    
}
bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(auto i:nums){
            sum+=i;
        }
        if(sum%2==1){
            return 0;
        }
        int x=(sum/2);
        vector<vector<int>>dp(n,vector<int>(x+1,-1));
        bool ans=tabulation(nums,x);
        return ans;
    }
};