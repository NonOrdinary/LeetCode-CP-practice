class Solution {
public:
    static bool cmp(const pair<int,int>&a ,const pair<int,int>&b){
        if(a.second==b.second){
            return a<b;
        }
        return a.second<b.second;

    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //it is similar to keeping track of least finish time 
        //as it ensures that we can always choose to select next interval 
        //as soon as it exceeds least finish time until now
        vector<pair<int,int>>points;
        for(auto &i:intervals){
            points.push_back({i[0],i[1]});
        }
        sort(points.begin(),points.end());
        int result=0;
        int minEnd=INT_MIN;
        for(int i=0;i<intervals.size();i++){
            if(points[i].first>=minEnd){
                minEnd=points[i].second;
                result++;
            }
            else{
                minEnd=min(points[i].second,minEnd);
            }
           
        }
        return intervals.size()-result;
    }
};