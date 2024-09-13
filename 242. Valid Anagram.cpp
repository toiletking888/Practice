// sorted and compare, time is O(nlogn)
class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_sum = 0, t_sum = 0;
        if(s.length()!=t.length()){
            return false;
        }
        else{
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            if(s == t){
                return true;
            }
            else{
                return false;
            }
        }
    }
};

//top solution:
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;

        for (const auto& letter : s) {
            mp[letter]++;
        }

        for (const auto& letter : t) {
            mp[letter]--;
        }

        for (auto& it : mp) {
            if (it.second != 0) {
                return false;
            }
        }
        return true;
    }
};

/* Brute force solution
Previous solution was O(NlogN)

Now write a solution that is O(N)

Create unordered_map<char, int> representing string s

For every letter in t
    mp[letter]--;

Iterate through mp again
    if a value of mp != 0
        return false

return true
*/