class Solution {
public:
    bool comp(vector<int>&a,vector<int>&b){
        if(a[1]!=b[1]){
            return a[1]<b[1];
        }
        return a<b;
    }
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int prev=1;
        int result=0;
        for(int i=0;i<meetings.size();i++){
           cout<<meetings[i][0]<<" "<<meetings[i][1]<<endl; 
            result+=max(meetings[i][0]-prev,0);
            prev=meetings[i][1]+1;
        }

        result+=max(days-prev+1,0);
        return result;
    }
};