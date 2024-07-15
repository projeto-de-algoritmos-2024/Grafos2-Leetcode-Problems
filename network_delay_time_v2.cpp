class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        min_heap.emplace(0, k);

        vector<vector<pair<int, int>>> lst_adj(n + 1);

        for (const auto& time : times) {
            lst_adj[time[0]].emplace_back(time[1], time[2]);
        }

        vector<int> minimumPaths(n + 1, INT_MAX);
        minimumPaths[k] = 0;

        while (!min_heap.empty()) {
            auto [t, no] = min_heap.top();
            min_heap.pop();

            if (t > minimumPaths[no]) continue;

            for (const auto& [vizinho, time] : lst_adj[no]) {
                if (minimumPaths[no] + time < minimumPaths[vizinho]) {
                    minimumPaths[vizinho] = minimumPaths[no] + time;
                    min_heap.emplace(minimumPaths[vizinho], vizinho);
                }
            }
        }

        int r = *max_element(minimumPaths.begin() + 1, minimumPaths.end());
        return r == INT_MAX ? -1 : r;
    }
};
