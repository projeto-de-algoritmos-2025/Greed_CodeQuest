#include <vector>
#include <numeric> 

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty() || prices.size() < 2) {
            return 0; // Não é possível realizar transações com menos de 2 dias.
        }

        int maxProfit = 0;
        for (size_t i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }
        return maxProfit;
    }
};
