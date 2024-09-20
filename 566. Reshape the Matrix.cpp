// use double stack to store the order of matrix
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int> > ans;
        stack <int> reverse;
        stack <int> order;
        int org_size = 0;
        int new_size = 0;
        ans.resize(r);
        for(int i = 0;i < mat.size();i++){
            for(int j = 0;j < mat[i].size();j++){
                org_size++;
                reverse.push(mat[i][j]);
            }
        }
        while(!reverse.empty()){
            order.push(reverse.top());
            reverse.pop();
        }
        new_size = r * c;
        if(org_size != new_size){return mat;}
        else{
            for(int i = 0;i < r;i++){
                for(int j = 0;j < c;j++){
                    ans[i].push_back(order.top());
                    order.pop();
                }
            }
        }
        return ans;
    }
};
//top solution:
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size() , n= mat[0].size();
        vector<vector<int>>v(r,vector<int>(c));
        queue<int>q;
        if(m*n == r*c){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    q.push(mat[i][j]);
                }
            }
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    v[i][j] = q.front();
                    q.pop();
                }
            }
            return v;
        }
        return mat;
    }
};