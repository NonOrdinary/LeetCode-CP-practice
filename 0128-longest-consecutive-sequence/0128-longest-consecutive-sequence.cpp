class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto& i : nums) {
            mp[i]++;
        }
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(mp[nums[i]]!=-1){
                int j = nums[i];
                while (mp.find(j + 1) != mp.end()) {
                    mp[j] = -1;
                    j++;
                }
                int k = nums[i];
                while (mp.find(k - 1) != mp.end()) {
                    mp[k] = -1;
                    k--;
                }
                result = max(result, j - k + 1);
            }
        }
        return result;
    }
};