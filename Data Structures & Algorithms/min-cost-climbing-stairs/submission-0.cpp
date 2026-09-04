class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int older = 0;
        int prev = 0;
        for(size_t i=2; i <= cost.size(); i++)
        {
            int temp = min(older+cost[i-2], prev+cost[i-1]);
            older = prev;
            prev = temp;
            std::cout << prev << " " << older << '\n';
        }
        return prev;
    }
};
