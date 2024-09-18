class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack <char> s1;
        stack <char> s2;
        for(int i = 0;i < s.length();i++){
            if(s[i] != '#'){
                s1.push(s[i]);
            }
            else{
                if(!s1.empty() && s[i] == '#'){
                    s1.pop();
                }
            }
        }
        for(int i = 0;i < t.length();i++){
            if(t[i] != '#'){
                s2.push(t[i]);
            }
            else{
                if(!s2.empty() && t[i] == '#'){
                    s2.pop();
                }
            }
        }
        string ans1, ans2;
        while(!s1.empty()){
            ans1 = ans1 + s1.top();
            s1.pop();
        }
        reverse(ans1.begin(), ans1.end());
        while(!s2.empty()){
            ans2 = ans2 + s2.top(); 
            s2.pop();
        }
        reverse(ans2.begin(), ans2.end());
        if(ans1 == ans2){return true;}
        else{return false;}
    }
};