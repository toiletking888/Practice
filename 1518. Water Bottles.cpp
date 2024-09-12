class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = 0;
        int rest = 0;
        while(numBottles >= numExchange){
            rest = numBottles % numExchange; // the rest of this turn of exchange
            numBottles /= numExchange; // exchange
            total += (numBottles * numExchange); // sum of the bottle drinkable
            if(rest + numBottles >= numExchange){
                numBottles += rest;             // sum of the rest and exchange bottles
            }
        }
        total += (numBottles+rest); // final turn of exchange and the rest of final turn
        return total;
    }
};

// top solution:
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        int empty = 0;
        int filled = numBottles;

        int ans = 0;

        while(filled > 0){
            filled = numBottles;
            ans += filled;
            empty += filled;


            numBottles = empty / numExchange;
            empty = empty % numExchange;
        }

        return ans;
        
    }
};