class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        auto [_, finalNotHold] = trade( prices.size()-1, prices );
        return finalNotHold;
    }
    
    tuple<int, int> trade(int day, vector<int>& prices){
        
        if( day == 0 ){      
            return tuple<int, int>{ -prices[0], 0};
        }
        
        auto [prevHold, prevNotHold] = trade( day - 1, prices );
        int curHold = max( prevHold, prevNotHold - prices[ day ] );
        int curNotHold = max( prevNotHold, prevHold + prices[ day ] );        
        
        return tuple<int, int>{ curHold, curNotHold};
    }
};