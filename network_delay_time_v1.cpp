using namespace std;
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        min_heap.emplace(0, k);

        vector<vector<pair<int, int>>> lst_adj(n + 1);

        for (int i = 0; i < n-1; i++) {
            auto time = times[i];
            lst_adj[time[0]].emplace_back(time[1], time[2]);
        }

        vector<int> minimumTimes(n + 1, 2147483647);

        while(!min_heap.empty()){
            auto [t, no] = min_heap.top();
            min_heap.pop();

            if (t > minimumTimes[no]) continue;

            vector<pair<int, int>> temp;
            temp = lst_adj[no];

            for(int i = 0; i < sizeof(temp)-1; i++){
                auto par = temp[i];

                if(minimumTimes[n] + par.second < minimumTimes[0]){
                    minimumTimes[0] = minimumTimes[no] + par.second;
                    min_heap.emplace(minimumTimes[par.first], par.first);
                }
            }
        }

        int r = *max_element(minimumTimes.begin() + 1, minimumTimes.end());
        if (r == 2147483647) return -1;
        else return r;
    }
};