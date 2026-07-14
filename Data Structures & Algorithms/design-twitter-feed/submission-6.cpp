class Twitter {
public:
    struct Post
    {
        int tweetId;
        int timestamp;
    };
    struct RecentTweetComp {
        bool operator()(const Post& p1, const Post& p2) const {
            return p1.timestamp < p2.timestamp; // True means p1 has lower priority than p2
        }
    };
    unordered_map<int, unordered_set<int>> followMap; // For a specific user; fetch all their followers
    unordered_map<int, priority_queue<Post, std::vector<Post>, RecentTweetComp>> userPosts;
    int timestamp;

    Twitter() 
    { 
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) 
    {
        Post p;
        p.tweetId = tweetId;
        p.timestamp = timestamp++;
        userPosts[userId].push(p);
    }
    
    vector<int> getNewsFeed(int userId) {
        // Ensure to get the feed of yourself and all the people you follow
        unordered_set<int>& usersInFeed = followMap[userId];

        // Ensure we are included in the feed
        usersInFeed.insert(userId);

        cout << "Getting news feed for user " << userId << ", he follows " << usersInFeed.size() << " people\n";

        int numEmpty = 0;
        priority_queue<Post, std::vector<Post>, RecentTweetComp>* pqPtr = nullptr;

        vector<int> postingList;
        unordered_map<int, priority_queue<Post, std::vector<Post>, RecentTweetComp>> userPostsCopy = userPosts;
        while (numEmpty < usersInFeed.size() && postingList.size() < 10)
        {
            numEmpty = 0;
            int mostRecentPost = INT_MIN;
            for (int userId : usersInFeed)
            {
                cout << "Checking userId " << userId << "\n";
                // Check all of their pq's top
                if (!userPostsCopy[userId].empty())
                {
                    cout << "User " << userId << " posts are not empty\n";
                    int postTimestamp = userPostsCopy[userId].top().timestamp;
                    if (postTimestamp > mostRecentPost)
                    {
                        pqPtr = &userPostsCopy[userId];
                        mostRecentPost = pqPtr->top().timestamp;
                    }
                }
                else
                {
                    cout << "User " << userId << " posts are empty\n";
                    numEmpty++;
                }
            }

            if (pqPtr) 
            { 
                cout << "Most recent post found was " << pqPtr->top().tweetId << "\n";
                postingList.push_back(pqPtr->top().tweetId);
                pqPtr->pop(); 
                pqPtr = nullptr;
            }
        }
        return postingList;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
