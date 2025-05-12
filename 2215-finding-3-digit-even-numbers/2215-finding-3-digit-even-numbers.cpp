class Solution {
public:
    //void count(vector<int>&digits,int &index,)
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int>used;
        unordered_set<int>made;
        for(int i=0;i<digits.size();i++){
            if(((digits[i]%2)==0) && made.find(i)==made.end()){
                made.insert(i);
                for(int j=0;j<digits.size();j++){
                    if(j!=i){
                        for(int k=0;k<digits.size();k++){
                            if(k!=i && k!=j && digits[k]!=0){
                                int num=digits[k]*100 + digits[j]*10 + digits[i];
                                used.insert(num);
                            }
                        }
                    }
                }
            }
        }
        vector<int>result;
        for(auto &i:used){
            result.push_back(i);
        }
        sort(result.begin(),result.end());
        return result;
    }
};