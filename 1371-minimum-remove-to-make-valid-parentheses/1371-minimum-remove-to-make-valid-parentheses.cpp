class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string result="";
        int i=0;
        int currSum=0;
        while(i<s.length()){
            if(s[i]=='('){
                currSum++;
            }
            else if(s[i]==')'){
                currSum--;
            }
            cout<<currSum<<endl;
            if(currSum>=0){
                result+=s[i];
            }
            else{
                currSum=0;
            }
            i++;
        }
        cout<<result<<endl;
        string ans="";
        i=result.length()-1;
        while(i>=0){
            if(currSum>0 && result[i]=='('){
                currSum--;
            }
            else{
                ans+=result[i];
            }
            i--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};