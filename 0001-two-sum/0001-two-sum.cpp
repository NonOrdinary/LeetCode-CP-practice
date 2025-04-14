class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> loc;
        for (int i = 0; i < nums.size(); i++) {
            int num = target - nums[i];
            if (loc.find(num) != loc.end()) {
                return {loc[num], i};
            }
            loc[nums[i]] = i;
        }

        return {-1, -1};
    }
};