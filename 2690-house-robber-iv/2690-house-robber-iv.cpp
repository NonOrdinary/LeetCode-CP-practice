class Solution {
public:
    bool check(vector<int>&nums,int k,int mid){
        int lastIndex=-2;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if((nums[i]<=mid) && (lastIndex<(i-1))){
                count++;
                lastIndex=i;
            }
        }
        return count<k;
    }
    int minCapability(vector<int>& nums, int k) {
        //approach
        //The problem can be rephrased as can you find a subsequence of length at least
        //such that maximum of that is minimised
        //so what do we need to minimise? the maximum value 
        //Do we even need to care about what subsequence if its length is atleast k,and 
        //its maximum is bounded by some value?
        //No we don't as long as they are not adjacent selected a
        //so this hints us as binary search on ans where
        //function f(x) = can we make a subsquence of length atleast K where each element is <=X
        //it looks like FFFFFTTTTTT so we need to return first true
        int s=-1,e=*max_element(nums.begin(),nums.end())+1;
        while(s+1<e){
            int mid=s+(e-s)/2;
            if(check(nums,k,mid)){
                s=mid;
            }
            else{
                e=mid;
            }
        }
        
        return e;
    }
};