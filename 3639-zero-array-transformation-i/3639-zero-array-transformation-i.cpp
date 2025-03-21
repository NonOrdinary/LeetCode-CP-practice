class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>diff(nums.size()+1,0);
        for(auto &i:queries){
            diff[i[0]]--;
            diff[i[1]+1]++;
        }
        for(int i=1;i<diff.size();i++){
            diff[i]+=diff[i-1];
        }
        
        for(int i=0;i<diff.size()-1;i++){
            diff[i]+=nums[i];
            if(diff[i]>0){
                return false;
            }
        }
        return true;
    }
};