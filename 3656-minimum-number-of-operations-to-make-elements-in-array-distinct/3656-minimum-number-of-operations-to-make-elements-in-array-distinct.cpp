class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        //seems greedy due to operation is limited to erase from beginning
        vector<int>freq(*max_element(nums.begin(),nums.end())+1,0);
        for(int i=nums.size()-1;i>=0;i--){
            freq[nums[i]]++;
            if(freq[nums[i]]>1){
                return (i+3)/3;
            }
        }

        return 0;
    }
};