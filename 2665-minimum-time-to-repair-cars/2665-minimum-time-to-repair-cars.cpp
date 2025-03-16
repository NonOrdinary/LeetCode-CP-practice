class Solution {
public:
    bool check(vector<int>&ranks,long long mid,int cars){
        long long count=0;
        for(int i=0;i<ranks.size();i++){
            long long squaredOffset=mid/ranks[i];
            int carsRepaired=sqrt(squaredOffset);
            count+=carsRepaired;
        }
        return count<cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        //given that it repair k cars in r*k*k minutes i.e r*k for 1 car
        //so in time t it will repair sqrt k*k<=t/r i.e k=sqrt(k)
        //so if total Cars >=cars than t is possible otherwise we need 
        //to increment time i.e function is monotonic FFFTTTTT and so on
        //its a binary search problem where f(t)=can all cars be repaired in t minutes

        long long s=-1,e=*max_element(ranks.begin(),ranks.end())*(cars*1ll*cars) +1;

        while(s+1<e){
            long long mid=s+(e-s)/2;
            if(check(ranks,mid,cars)){
                s=mid;
            }
            else{
                e=mid;
            }
        }
        return e;
    }
};