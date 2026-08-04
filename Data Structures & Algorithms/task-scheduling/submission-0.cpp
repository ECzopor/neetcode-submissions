class Solution {
public:
    class MyHeap
    {
    private: 
        vector<pair<int, int>> vec;
        
        void build_heap()
        {
            for (int i = (int)(vec.size() / 2) - 1; i >= 0; i--) {
                min_heapify(i);
            }
        }
        void min_heapify(int i)
        {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int mini = i;

            
            if (l < vec.size() && (vec[l].first < vec[mini].first || 
               (vec[l].first == vec[mini].first && vec[l].second > vec[mini].second))) {
                mini = l;
            }
            if (r < vec.size() && (vec[r].first < vec[mini].first || 
               (vec[r].first == vec[mini].first && vec[r].second > vec[mini].second))) {
                mini = r;
            }

            if (mini != i) {
                swap(vec[i], vec[mini]);
                min_heapify(mini);
            }
        }
        void add_to_heap(int time, int count) {
            vec.push_back({time, count});
            int i = vec.size() - 1;
            while (i > 0 && vec[(i - 1) / 2].first > vec[i].first) { 
                swap(vec[i], vec[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
        }
    public: 
        MyHeap(vector<pair<int, int>> v)
        {
            vec = v;
            build_heap();
        }
        pair<int, int>& top()
        {
            return vec[0];
        }
        void del()
        {
            auto maxi = vec[0];
            vec[0] = vec[vec.size()-1];
            vec.pop_back();
            min_heapify(0);
        }
        bool empty()
        {
            if(vec.size() == 0)return true;
            else return false;
        }
        void decrement_cooldowns()
        {
            for (auto& elem : vec) {
                if (elem.first > 0) {
                    elem.first--;
                }
            }
            build_heap();
        }
    };
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for(auto const& t : tasks)
        {
            counts[t]++;
        }

        vector<pair<int, int>>v;
        for (auto& [ch, count] : counts) {
            v.push_back({0, count});
        }

        MyHeap pq(v);
        int cycles = 0;

        while(!pq.empty())
        {
            cycles++;
            auto& [cooldown, remian] = pq.top();
            if(cooldown == 0)
            {
                remian--;
                if(remian == 0)
                {
                    pq.del();
                }
                else
                {
                    cooldown = n+1;
                }
            }
            pq.decrement_cooldowns();
        }
        return cycles;
    }
};
