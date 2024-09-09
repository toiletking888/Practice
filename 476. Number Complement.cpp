class Solution {
public:
    int findComplement(int num) {
        string s;
        int ans = 0;
        while(num > 0){
            if(num % 2 == 1){
                s = s + "0";
                num  /= 2;
            }
            else{
                s = s + "1";
                num /= 2;
            }
        }   
        for(int i = 0;i < s.length();i++){
            if(s[i] == '0'){

            }
            else{
                ans += pow(2,i);
            }
        }
        return ans;
    }
};