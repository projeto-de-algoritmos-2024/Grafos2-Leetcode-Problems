class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int size = points.size();
        if(size == 0){return 0;}

        vector<int> usadas(size, INT_MAX);

        int custo = 0;

        for(int i = 0; i < (size - 1); i++){
            int menor = INT_MAX;
 
            vector<int> corde = points[i];
            auto x = corde[0];
            auto y = corde[1];

            for(int j = 0; j < size; j++){
                vector<int> temp = points[j];
                auto x_temp = temp[0];
                auto y_temp = temp[1];

                if(x == x_temp && y == y_temp){
                    continue;
                }

                if(usadas[j] == i){
                    continue;
                }

                int soma = abs(x - x_temp) + abs(y - y_temp);
                
                if(soma < menor){
                    menor = soma;
                    usadas[i] = j;
                }
            }
            custo = custo + menor;
        }

        return custo;
    }
};
