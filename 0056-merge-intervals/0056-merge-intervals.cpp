class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //finest implementation
        if (intervals.empty()) return intervals;

        vector<vector<int>> merge;
        
        sort(intervals.begin(), intervals.end());
        merge.push_back(intervals[0]);
        for(int i=0;i<intervals.size();i++)
        {
            int s = intervals[i][0];
            int e = intervals[i][1];
            if(merge.back()[1] < s)
            {
                merge.push_back({s,e});
            }
            else
            {
                merge.back()[1] = max(merge.back()[1], e);
            }
        }
        return merge;
    }
};