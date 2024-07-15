class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int size = points.size();
        if(size <= 1){return 0;}

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;

        vector<bool> usadas(size);
        
        int custo = 0;
        int conexoes_feitas = 0;
        int i = 0;
        
        while(++conexoes_feitas < size){
            usadas[i] = true;

            vector<int> cord_i = points[i];

            for(int j = 0; j < size; j++){
                if(usadas[j]){continue;}
                vector<int> cord_j = points[j];
                min_heap.emplace(abs(cord_i[0] - cord_j[0]) + abs(cord_i[1] - cord_j[1]), j);
            }

            while(usadas[min_heap.top().second]){
                min_heap.pop();
            }

            int menor = min_heap.top().first;
            i = min_heap.top().second;
            custo = custo + menor;
            min_heap.pop();
        }

        return custo;
    }
};

//Accepted
