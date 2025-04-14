class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>freq;
        int left = 0;
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
            while (freq[s[i]] > 1) {
                freq[s[left]]--;
                left++;
            }
            result = max(result, i - left + 1);
        }
        return result;
    }
};