class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int l=-1,r=-1;
        vector<vector<int>>result;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            if(l==-1 && r==-1){
                l=intervals[i][0];
                r=intervals[i][1];
            }
            else{
                if(r<intervals[i][0]){
                    //new interval begin
                    result.push_back({l,r});
                    l=intervals[i][0];
                    r=intervals[i][1];
                }
                else{
                    r=max(r,intervals[i][1]);
                }
            }
        }

        if(l!=-1){
            result.push_back({l,r});
        }
        return result;
    }
};