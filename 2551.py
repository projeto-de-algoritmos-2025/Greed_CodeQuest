class Solution:
    def putMarbles(self, weights, k):
        # Se só tiver uma bolsa, não há cortes e a diferença é zero
        if k == 1:
            return 0
        
        pair_sums = []
        # Calcula a soma dos pares adjacentes na lista weights
        for i in range(len(weights) - 1):
            pair_sums.append(weights[i] + weights[i + 1])
        
        # Ordena as somas dos pares para facilitar a seleção dos maiores e menores cortes
        pair_sums.sort()
        
        # Soma dos (k-1) maiores valores para a máxima soma dos cortes
        max_sum = sum(pair_sums[-(k-1):])
        # Soma dos (k-1) menores valores para a mínima soma dos cortes
        min_sum = sum(pair_sums[:k-1])
        
        # Retorna a diferença entre as somas máximas e mínimas
        return max_sum - min_sum
