class Solution {
public:
    int back_tracking(string &s, unordered_set<string> &sub, int start){
        if(start == s.length()){
            return 0;
        }
        int count = 0;
        for(int i = start+1;i <= s.length();i++){
            string subs = s.substr(start, i-start);
            if(sub.find(subs) == sub.end()){
                sub.insert(subs);
                count = max(count, 1+back_tracking(s, sub, i));
                sub.erase(subs);
            }
        }
        return count;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> sub_list;
        return back_tracking(s, sub_list, 0);
    }
};