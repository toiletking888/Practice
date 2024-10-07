class Solution {
public:
    int minLength(string s) {
        bool check = false;
        int i = 0;
        while(s.length()>0){
            if((s[i] == 'A' && s[i+1] == 'B') || (s[i] == 'C' && s[i+1] == 'D')){
                s.erase(s.begin()+i);
                s.erase(s.begin()+i);
                i = 0;
            }
            else{
                if(s.length() == i){
                    break;
                }
                else{
                    i++;
                }
            }
        }
        return s.length();
    }
};
// top solution
class Solution {
public:
    int minLength(string s) {
        stack<char> stack;

        for (int i = 0; i < s.length(); i++) {
            char cur_char = s[i];

            if (stack.empty()) {
                stack.push(cur_char);
                continue;
            }

            if (cur_char == 'B' && stack.top() == 'A') {
                stack.pop();
            }
            else if (cur_char == 'D' && stack.top() == 'C') {
                stack.pop();
            }
            else {
                stack.push(cur_char);
            }
        }

        return stack.size();
    }
};