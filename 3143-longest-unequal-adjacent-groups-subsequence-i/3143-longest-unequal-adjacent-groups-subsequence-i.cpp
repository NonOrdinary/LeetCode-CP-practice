class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        //alternate greedy soln ,notice if we consider all 0 segments
        //then for each segment we need to select one string and return result
        int group=-1;
        vector<string>result;
        for(int i=0;i<groups.size();i++){
            if(groups[i]!=group){
                result.push_back(words[i]);
                group=groups[i];//updating the last as current group value element
            }
        }

        return result;
    }
};