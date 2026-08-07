class Twitter {
private:
    unordered_map<int, vector<int>> following; //[user] = users they are following
    deque<pair<int, int>> pq; //FIFO - user, tweet
public:
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        pq.push_front(make_pair(userId, tweetId));

    }
    
    vector<int> getNewsFeed(int userId) {

        vector<int>ams;
        bool narc = false;
        for(auto itr = pq.begin(); itr != pq.end(); itr++)
        {
            if(following.contains(userId))
            {
                if(find(following[userId].begin(), following[userId].end(), itr->first)!=following[userId].end())
                {
                    ams.push_back(itr->second);
                    if(itr->first == userId)narc = true;
                }
            }
            if(itr->first == userId && narc == false)ams.push_back(itr->second);
            
            if(ams.size() == 10)return ams;
        }
        return ams;

    }
    
    void follow(int followerId, int followeeId) {
        if(find(following[followerId].begin(), following[followerId].end(), followeeId) != following[followerId].end())return;
        following[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        
        auto itr = find(following[followerId].begin(), following[followerId].end(), followeeId);
        if(itr!= following[followerId].end())
        {
            following[followerId].erase(itr);
        }
    }
};
