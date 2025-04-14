class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(auto &i:s){
            if(stk.empty()){
                stk.push(i);
            }
            else{
                if(stk.top()=='(' && i==')'){
                    stk.pop();
                }
                else if(stk.top()=='{' && i=='}'){
                    stk.pop();

                }
                else if(stk.top()=='[' && i==']'){
                    stk.pop();
                }
                else if(i==')' || i=='}'||i==']'){
                    return false;
                }
                else{
                    stk.push(i);
                }
            }
        }
        return stk.empty();
    }
};