class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>,greater<pair<int, vector<int>>>> pq;
        for(const auto& v : points)
        {
            pq.push(make_pair(v[0]*v[0] + v[1]*v[1], v));
        }
        vector<vector<int>> ans;
        for(int i =0; i < k; i++)
        {
            ans.push_back(pq.top().second);
            cout << pq.top().second[0] << " " << pq.top().second[1] << '\n';
            pq.pop();
            
        }
        
        return ans;
    }
};
