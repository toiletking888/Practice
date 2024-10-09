class Solution {
public:
    int minSwaps(string s) {
       int count = 0;
       int imbalance = 0;
       for(char c : s){
            if(c == ']'){
                if(imbalance == 0){
                    imbalance++;
                    count++;
                }
                else{
                    imbalance--;
                }
            }
            else{
                imbalance++;
            }
       }
       return count;
    }
};