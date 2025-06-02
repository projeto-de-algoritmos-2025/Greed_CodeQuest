#include <vector>
#include <algorithm> // Para std::sort

class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }

        // Ordenar os balões pelo ponto final (x_end)
        std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;
        int arrowPosition = points[0][1]; // Posição da primeira flecha (no final do primeiro balão)

        for (size_t i = 1; i < points.size(); ++i) {
            // Se o início do balão atual for depois da posição da flecha atual
            if (points[i][0] > arrowPosition) {
                arrows++; // Precisamos de uma nova flecha
                arrowPosition = points[i][1]; // Posiciona a nova flecha no final do balão atual
            }
            // Caso contrário, a flecha atual já estoura este balão.
            // Não precisamos mover a 'arrowPosition' porque a atual (que é o fim de um balão anterior)
            // é uma posição mais restritiva e ainda válida para o balão atual.
        }

        return arrows;
    }
};