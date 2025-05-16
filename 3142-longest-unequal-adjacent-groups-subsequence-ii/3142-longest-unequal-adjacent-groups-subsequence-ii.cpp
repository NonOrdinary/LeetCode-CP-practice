class Solution {
public:
    bool ValidHD(string& a, string& b) {
        if (a.length() != b.length()) {
            return false;
        }
        int count = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                count++;
            }
        }

        return count == 1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {
        /*Similar to LIS type DP ,as its variant i.e same name I ,can be solved
        greedily too but due to selection of particular length make it difficult
        to use the same solution here TC=O(n2) SC=O(n)*/
        vector<int> dp(words.size(), 1);
        for (int i = (int)words.size() - 2; i >= 0; i--) {
            for (int j = i + 1; j < words.size(); j++) {
                if ((groups[i] != groups[j]) && ValidHD(words[i], words[j])) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
        }

        int len = *max_element(dp.begin(), dp.end());
        int lastGroup = -1;
        vector<string> result;
        for (int i = 0; i < words.size(); i++) {
            
            if (lastGroup != groups[i] && dp[i] == len) {
                if (result.empty()) {
                    result.push_back(words[i]);
                    len--;
                    lastGroup = groups[i];
                } else if (ValidHD(words[i], result.back())) {
                    result.push_back(words[i]);
                    len--;
                    lastGroup = groups[i];
                }
            }
        }

        return result;
    }
};