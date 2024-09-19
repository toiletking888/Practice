// easy
class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack <char> layer;
        int ans = 0;
        for(int i = 0;i < logs.size();i++){
            if(logs[i][0] == '.' && logs[i][1] == '/'){
                
            }
            else if(logs[i][0] == '.' && logs[i][1] == '.'){
                if(layer.empty()){

                }
                else{
                    layer.pop();
                }
            }
            else{
                layer.push(i);
            }
        }
        while(!layer.empty()){
            layer.pop();
            ans++;
        }
        return ans;
    }
};

//top solution:
for (const auto& log : logs) {
    if (log == "../") {
        if (step > 0) step--;
    } else if (log != "./") {
        step++;
    }
}
return step;