#include<bits/stdc++.h>
using namespace std;


class TimeMap {
public:
    typedef pair<int, string> pis;
    unordered_map<string, vector<pis>> m;
    /** Initialize your data structure here. */
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        m[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        vector<pis> &pairs = m[key];
        int n = pairs.size();
        if(pairs.empty())
            return "";
        pis p={timestamp,string({127})};
        auto i=upper_bound(pairs.begin(),pairs.end(),p);
        return (i-1)->second;
    }
};