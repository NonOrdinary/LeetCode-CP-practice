class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int main=0,temp=0;
        while(temp<nums.size()){
            while(temp<nums.size() && nums[main]==nums[temp]){
                temp++;
            }

            if(temp<nums.size()){
                swap(nums[++main],nums[temp]);
                temp++;
            }
        }

        return main+1;
    }
};