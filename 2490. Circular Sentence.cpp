class Solution {
public:
    bool isCircularSentence(string sentence) {
        string s = sentence;
        if(sentence[0] != sentence[sentence.length()-1]) return false;
        for(int i = 1;i < s.length()-1;i++){
            if(s[i] == ' '){
                if(s[i-1] != s[i+1]){
                    return false;
                }
            }
        }
        return true;
    }
};
