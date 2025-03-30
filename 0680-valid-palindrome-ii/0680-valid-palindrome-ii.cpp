class Solution {
public:
    bool check(string &s,int i,int j){
        while(i<s.length() && i<=j){
            if(s[i]==s[j]){
                i++,j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0,j=s.length()-1;
        int mismatch=0;
        while(i<=j && i<s.length()){
            if(s[i]==s[j]){
                i++,j--;
            }
            else{
                return check(s,i,j-1)|check(s,i+1,j);
            }
        }
        return true;
    }
};