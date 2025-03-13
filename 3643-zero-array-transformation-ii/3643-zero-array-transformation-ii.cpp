class Solution {
public:
    bool check(vector<int>&nums,vector<vector<int>>&queries,int &k){
        vector<int>arr(nums.size()+1,0);
        for(int i=0;i<k;i++){
            arr[queries[i][0]]-=queries[i][2];
            arr[queries[i][1]+1]+=queries[i][2];
        }
        for(int i=1;i<nums.size();i++){
            arr[i]+=arr[i-1];
        }
        for(int j=0;j<nums.size();j++){
            arr[j]+=nums[j];
            if(arr[j]>0){
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int s=-1,e=queries.size()+1;
        while(s+1<e){
            int mid=s+(e-s)/2;
            cout<<mid<<endl;
            if(!check(nums,queries,mid)){
                s=mid;
            }
            else{
                e=mid;
            }
        }
        if(e==queries.size()+1)e=-1;
        return e;
    }
};