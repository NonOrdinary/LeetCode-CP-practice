class Solution {
public:
    bool check(vector<int>&candies,long long &mid,long long &k){
        
        long long count=0;
        for(int i=0;i<candies.size();i++){
            count+=(candies[i]/mid);
        }
        return count>=k;
        //value at e will be making count <k
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long s=0,e=accumulate(candies.begin(),candies.end(),0LL)+1;
        while(s+1<e){
            long long mid=s+(e-s)/2;
            if(check(candies,mid,k)){
                s=mid;
            }
            else{
                e=mid;
            }
        }
        return s;
    }
};