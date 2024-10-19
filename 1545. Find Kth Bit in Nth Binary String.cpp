class Solution {
public:
    string invert_S(string s){
        for(int i = 0;i < s.length();i++){
            if(s[i] == '0'){
                s[i] = '1';
            }
            else{
                s[i] = '0';
            }
        }
        return s;
    }
    string generate_S(int n){
        vector<string> store;
        string ex_s, curr_s;
        string r, invert;
        int i = 0;
        store.push_back("0");
        if(n == 1){
            return store[i];
        }
        else{
            while(i < n-1){
                i++;
                ex_s = store[i-1];
                invert = invert_S(ex_s);
                reverse(invert.begin(), invert.end());
                curr_s = ex_s + "1" + invert;
                store.push_back(curr_s);
            }
        }
        return curr_s;
    }
    char findKthBit(int n, int k) {
        string n_string;
        string temp = "";
        n_string = generate_S(n);
        cout << n_string;
        return n_string[k-1];
    }
};
//top solution
class Solution {
public:
    char findKthBit(int n, int k) {
        if (k==1) return '0';// base case
        int sz=32-__builtin_clz(k);
        int k0=(1<<sz)-k; // reflected number
        if (k0==k) return '1';// k is a symmetry number
    //    cout<<(1<<sz)<<", k="<<k<<endl;
        return (findKthBit(n, k0)=='0')?'1':'0';
    }
};