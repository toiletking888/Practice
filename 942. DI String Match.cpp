class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        deque<int> dq;
        vector<int> ans;
        for(int i = 0;i <= n;i++){
            dq.push_back(i);
        }
        for(int i = 0;i < s.length();i++){
            if(s[i] == 'I'){
                ans.push_back(dq.front());
                dq.pop_front();
            }
            if(s[i] == 'D'){
                ans.push_back(dq.back());
                dq.pop_back();
            }
        }
        ans.push_back(dq.front());
        return ans;
    }
};

//top solution
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.length(), left=0, right=n;
        vector<int> answer(n+1, 0);
        for( int i=0; i<n ; i++ ){
            answer[i] = s[i] == 'I' ? left++ : right--;  
        }
        answer[n] = left;
        return answer;
    }
};