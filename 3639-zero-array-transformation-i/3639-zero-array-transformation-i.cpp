class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        //the problem is standard problem as difference array,
        //i might try to optimise a little bit.
        vector<int>diff(nums.size()+1,0);
        for(int i=0;i<queries.size();i++){
            diff[queries[i][0]]++;
            diff[queries[i][1]+1]--;
        }
        for(int i=1;i<diff.size();i++){
            diff[i]+=diff[i-1];
        }

        for(int i=0;i<nums.size();i++){
            if(diff[i]<nums[i]){
                return false;
            }
        }

        return true;
    }
};