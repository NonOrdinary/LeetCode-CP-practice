class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>sub(n,0);
        for(int i=0;i<n;i++){
            sub[i]+=1;
            sub[min(n-1,i+nums[i])]-=1;
        }
        for(int i=1;i<n;i++){
            sub[i]=sub[i]+sub[i-1];
        }
        for(int i=0;i<n-1;i++){
            if(sub[i]==0){
                return false;
            }
        }
        return true;
    }
};