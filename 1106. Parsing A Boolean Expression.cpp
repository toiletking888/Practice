class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> s;
        char op;
        for(char c : expression){
            if(c == ',' || c == '(') continue;
            if(c == 't' || c == 'f' || c == '|' || c == '&' || c == '!' ){
                s.push(c);
            }
            else if(c == ')'){
                bool hasT = false, hasF = false;
                while(s.top() != '|' && s.top() != '&' && s.top() != '!'){
                    if(s.top() == 't') hasT = true;
                    if(s.top() == 'f') hasF = true;
                    s.pop();
                }
                op = s.top();
                s.pop();
                if(op == '!'){
                    if(hasT) s.push('f');
                    else s.push('t');
                }
                else if(op == '|'){
                    if(hasT) s.push('t');
                    else s.push('f');
                }
                else if(op == '&'){
                    if(hasF) s.push('f');
                    else s.push('t');
                }
            }
        }
        return s.top() == 't';
    }
};