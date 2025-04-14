class Solution {
public:
    void count(string &s,int &result,int left,int right){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            result++;
            left--,right++;
        }
    }
    int countSubstrings(string s) {
        /*
            This is exapnding from the centre,its just the dp idea that we use 
            but we do not store previous,rather we calculate on the go 
            this will be only O(n2) as we will be traversing the array
        */
        int result=0;
        for(int i=0;i<s.length();i++){
            count(s,result,i,i);
            count(s,result,i,i+1);
        }
        return result;
    }
};