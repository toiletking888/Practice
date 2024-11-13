class Solution {
public:
    bool isPrime(int p){
        for(int i = 2;i <= sqrt(p);i++){
            if(p % i == 0){
                return false;
            }
        }
        return true;
    }
    int findPrime(int start, int end){
        for(int i = end; i >= start;i--){
            if(isPrime(i)){
                return i;
            }
        }
        return 0;
    }

    bool primeSubOperation(vector<int>& nums) {
        int start = 0, end = 0;
        for(int i = 0;i < nums.size()-1;i++){
            end = nums[i] -1;
            if(end == 0 || end == 1) continue;
            int p = findPrime(start, end);
            int temp = nums[i] - p;
            while(temp <= start){
                end = p-1;
                p = findPrime(start, end);
                temp = nums[i] - p;
            }
            nums[i] = temp;
            start = nums[i];
        }
        for(int i = 0;i < nums.size()-1;i++){
            if(nums[i+1] <= nums[i]){
                return false;
            }
        }
        return true;
    }
};
// top solution
class Solution {
public:
    vector<int> prime;
    void sieve(int M){
        bitset<1001> isPrime=0;
        isPrime.set();
        isPrime[0]=isPrime[1]=0;
        prime.reserve(int(M/max(1.0, log(M))));// use prime Numbery theorem
        int sqrtM=sqrt(M);
        for(int p=2; p<=sqrtM; p++){
            if (isPrime[p]==0) continue;
            prime.push_back(p);
            for(int j=p*p; j<=M; j+=p){
                isPrime[j]=0;
            }
        }
        int q=(sqrtM&1)?sqrtM+2:sqrtM+1;
        for(int p=q; p<=M; p+=2){
            if (isPrime[p])
                prime.push_back(p);
        }
    //    cout<<prime.size();
    }
    void print(){
        for (int x:prime) cout<<x<<", ";
        cout<<endl;
    }

    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size(), M=*max_element(nums.begin(), nums.end());
        sieve(max(M, 4));// M>=4 edge case for Sieve method
    //    print();
        for(int i=n-2; i>=0; i--){
            if (nums[i+1]>nums[i]) continue;
            //Find location of smallest p such that nums[i]-p < nums[i+1]
            auto it=upper_bound(prime.begin(), prime.end(), nums[i]-nums[i+1]);
            if (it==prime.end()) return 0;// no found
            int p=*it;
            nums[i]-=p;
        //    cout<<"i="<<i<<", p="<<p<<", nums[i]="<<nums[i]<<endl;
            if (nums[i]<=0) return 0;
        }
        return 1;
    }
};
