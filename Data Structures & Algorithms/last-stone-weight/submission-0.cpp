class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(const auto& x : stones)
        {
            pq.push(x);
        }

        while(pq.size() != 1 && !pq.empty())
        {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x != y) pq.push(max(x-y, y-x));
        }
        if(pq.empty())return 0;
        else return pq.top();

    }
};
