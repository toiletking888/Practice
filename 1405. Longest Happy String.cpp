class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char> > p;
        string ans;
        if(a > 0) p.push({a, 'a'});
        if(b > 0) p.push({b, 'b'});
        if(c > 0) p.push({c, 'c'});

        while(!p.empty()){
            auto [count01, char01] = p.top();
            p.pop();
            if(ans.length() >= 2 && ans.back() == char01 && ans[ans.length()-2] == char01){
                if(p.empty()) break;

                auto [count02, char02] = p.top();
                p.pop();
                ans += char02;
                count02--;
                if(count02 > 0) p.push({count02, char02});
                p.push({count01, char01});
            }
            else{
                ans += char01;
                count01--;
                if(count01 > 0) p.push({count01, char01});
            }
        }
        return ans;
    }
};