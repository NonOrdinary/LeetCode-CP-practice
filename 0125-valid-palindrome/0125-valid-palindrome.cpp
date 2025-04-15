class Solution {
public:
    bool isPalindrome(string s) {
        string modified="";
        for(int i=0;i<s.length();i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
                modified+=tolower(s[i]);
            }
            else if(s[i]>='0' && s[i]<='9'){
                modified+=tolower(s[i]);
            }
        }
        for(int i=0;i<modified.length()/2;i++){
            if(modified[i]!=modified[modified.length()-i-1]){
                return false;
            }
        }
        return true;
    }
};