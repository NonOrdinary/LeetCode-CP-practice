class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<int>>mp;
        for(int i=0;i<strs.size();i++){
            vector<int>num(26,0);
            for(int j=0;j<strs[i].size();j++){
                num[strs[i][j]-'a']++;
            }
            mp[num].push_back(i);
        }
        vector<vector<string>>result;
        for(auto &i:mp){
            result.push_back({});
            for(auto &j:i.second){
                result.back().push_back(strs[j]);
            }
        }
        return result;

    }
};