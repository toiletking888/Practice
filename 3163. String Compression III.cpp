class Solution {
public:
    string compressedString(string word) {
        string ans;
        int count = 1;
        for(int i = 0;i < word.length();i++){
            if(i != word.length()-1 && word[i] == word[i+1] && count < 9){
                count++;
            }
            else if(i == word.length()-1 && count < 9){
                ans += count+'0';
                ans += word[i];
                count = 1;
            }
            else{
                ans += count+'0';
                ans += word[i];
                count = 1;
            }
        }
        return ans;
    }
};
//top solution
class Solution {
public:
    static string compressedString(string& word) {
        int n=word.size(), l=0;
        string ans;
        ans.reserve(n);
        for(int r=0; r<n; ){
            while( r<n && word[r]==word[l]) r++;

            auto [q, rem]=div(r-l, 9);
            
            for(int i=0; i<q; i++){
                ans.push_back('9');
                ans.push_back(word[l]);
            }
            if (rem>0) {
                ans.push_back(rem+'0');
                ans.push_back(word[l]);
            }
            l=r;
        }
        return ans;
    }
};



auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();