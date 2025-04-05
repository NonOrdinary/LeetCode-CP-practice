class Solution {
public:
    void getSums(int &totalSum,int index,int exor,vector<int>&nums,int &n){
        if(index>=n){
            cout<<exor<<endl;
            totalSum+=exor;
            return;
        }

        getSums(totalSum,index+1,exor^nums[index],nums,n);//pick this one
        getSums(totalSum,index+1,exor,nums,n);//skip this one
        return;
    }
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        getSums(result,0,0,nums,n);
        return result;
    }
};