class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //we use the two sum technique to find sum=target in sorted array
        //i.e decrease when sum exceeds by reducing the right ,increase if required by moving left
        vector<vector<int>>result;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int target=-nums[i];

            int left=i+1,right=nums.size()-1;
            while(left<right){
                if(nums[left]+nums[right]<target){
                    left++;
                }
                else if(nums[left]+nums[right]>target){
                    right--;
                }
                else{
                    //found a triplet
                    vector<int>triplet={nums[i],nums[left],nums[right]};
                    result.push_back(triplet);
                    left++;
                    while(nums[left]==nums[left-1] && left<right){
                        left++;
                    }
                }
            }
        }

        return result;
    }
};