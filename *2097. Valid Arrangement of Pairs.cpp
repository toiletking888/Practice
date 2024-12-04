class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adjList;
        for(auto& e : pairs){
            int u = e[0];
            int v = e[1];
            adjList[u].push_back(v);
        }
        
        stack<int> currPath;
        vector<int> path;
        currPath.push(pairs[0][0]);
        int currVertex = pairs[0][0];
        while(!currPath.empty()){
            if(!adjList[currVertex].empty()){
                currPath.push(currVertex);
                int nextVertex = adjList[currVertex].back();
                adjList[currVertex].pop_back();
                currVertex = nextVertex;
            }
            else{
                path.push_back(currVertex);
                currVertex = currPath.top();
                currPath.pop();
            }
        }
        reverse(path.begin(), path.end());
        vector<vector<int> > ans;
        for(int i = 0;i < path.size()-1;i++){
            vector<int> temp = {path[i], path[i+1]};
            ans.push_back(temp);
        }
        return ans;
    }
};