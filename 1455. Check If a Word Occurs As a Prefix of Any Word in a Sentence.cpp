class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> list;
        string temp;
        stringstream s;
        s.str("");
        s.clear();
        s << sentence;
        int check = 0;
        while(s >> temp){
            list.push_back(temp);
        }
        for(int i = 0;i < list.size();i++){
            if(searchWord[0] == list[i][0]){
                for(int j = 0;j < list[i].length();j++){
                    if(searchWord[j] == list[i][j]){
                        check++;
                    }
                }
                if(check == searchWord.length()){
                    return i+1;
                }
                check = 0;
            }
            else{
                continue;
            }
        }
        return -1;
    }
};