#include <vector>

class Solution {
public:
    int minPatches(std::vector<int>& nums, int n) {
        long long miss = 1; // O menor número que ainda não conseguimos formar
        int patches = 0;    // Número de patches adicionados
        int i = 0;          // Índice para percorrer o array nums

        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                // Se o elemento atual do array pode ajudar a formar 'miss'
                miss += nums[i];
                i++;
            } else {
                // Se não podemos formar 'miss', adicionamos 'miss' como um patch
                miss += miss;
                patches++;
            }
        }
        return patches;
    }
};