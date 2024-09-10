// use vector.insert to add the zero follow the original zero, then delete the overflow element
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int max_size = arr.size();
        for(int i = 0;i < arr.size();i++){
            if(arr[i] == 0){
                arr.insert(arr.begin()+i, 0);
                i++;
            }
        }
        while(arr.size() > max_size){
            arr.erase(arr.begin()+(arr.size()-1));
        }       
    }
};

// top solution:
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int i=0, n=arr.size();
        while(i<n)
        {
            if(arr[i]==0)
            {
                arr.insert(arr.begin()+i, 0);
                i += 2;
            }
            else
            {
                i++;
            }
        }
        arr.resize(n); // use resize could save a for loop
    }
};
