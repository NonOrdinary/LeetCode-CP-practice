class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int>arr(*max_element(nums.begin(),nums.end())+1,0);
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2){
                return false;
            }
        }
        return true;
    }
};