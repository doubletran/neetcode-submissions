
class Twitter {
    int tweetCount;
    vector<pair<int, int>>tweets; //count : {id, user}
    unordered_map<int,unordered_set<int>>users; //userId by their following
public:
    Twitter() {

    }
    bool getUser(const int &userId){
        return (users.find(userId) != users.end());
    }
    void postTweet(int userId, int tweetId) {
        tweets.push_back({tweetId, userId});
    }
    vector<int> getNewsFeed(int userId) {
        int count = 0;
        vector<int> feed;
        for (auto it = tweets.rbegin(); it != tweets.rend() && count < 10;it++){
            int posterId = (*it).second;
            if (posterId == userId || users[userId].find(posterId) != users[userId].end()){
                feed.push_back((*it).first);
                count++;
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        users[followerId].insert(followeeId);

    }
    
    void unfollow(int followerId, int followeeId) {
        users[followerId].erase(followeeId);
    }
};
