class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        /*
            [2,7,11,15] is the array then if for somei,j such that  i<j  a[i]+a[[j]>target then to decrease the sum i need to decrease a[j] to some extent as if i increase i then a[i]<a[i+1] so a[i+1]+a[j]>=a[i]+a[j] but if we decrease the a[j] then a[i]+a[j-1]<=a[i]+a[j] which will eventually lead us to a situation where a[i]+a[jâ]<=target this means that we cannot have one number greater that a[j].
        */
        int left=0,right=numbers.size()-1;
        while(left<right){
            if(numbers[left]+numbers[right]<target){
                left++;
            }
            else if(numbers[left]+numbers[right]>target){
                right--;
            }
            else{
                break;
            }
        }

        return {left+1,right+1};
    }
};