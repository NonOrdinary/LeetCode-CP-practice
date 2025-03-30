class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        int ans=INT_MIN;
        cout<<sum<<endl;
        map<int,int>mp;
        for(auto &i:nums){
            mp[i]++;
        }
        for(int i=0;i<nums.size();i++){
            long long k=sum-nums[i];
            if((sum-nums[i])%2==0){
                if(mp.find(k/2)!=mp.end()){
                    if(nums[i]==k/2 && (mp[k/2]-1)>0){
                        ans=max(ans,nums[i]);
                    }
                    else if(nums[i]!=k/2){
                        ans=max(ans,nums[i]);
                        
                    }
                }
            }
        }

        return ans;
    }
};