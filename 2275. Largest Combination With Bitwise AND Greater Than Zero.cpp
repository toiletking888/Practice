class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<string> bits(candidates.size());
        vector<int> m(24);
        int big = 0;
        int j = 0;
        for(int i = 0;i < candidates.size();i++){
            int temp = candidates[i];
            while(temp != 0){
                if(temp % 2 == 0){
                    temp /= 2;
                    j++;
                }
                else{
                    m[j]++;
                    j++;
                    temp /= 2;
                }
            }
            j = 0;
        }
        for(int i = 0;i < m.size();i++){
            cout << m[i] << " ";
            if(m[i] > big){
                big = m[i];
            }
        }
        return big;
    }
};
//top solution
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int max_set=0;
        for(char b=0; b<24; b++){
            int b_bit_set=0;
            for(bitset<24> x: candidates){
                b_bit_set+=x[b];
            }
            max_set=max(max_set, b_bit_set);
        }
        return max_set;
    }
};
