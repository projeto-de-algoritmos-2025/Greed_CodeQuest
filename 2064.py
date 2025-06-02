import math

class Solution:
    def minimizedMaximum(self, n, quantities):
        left, right = 1, max(quantities)
        
        def can_distribute(max_load):
            stores_needed = 0
            for q in quantities:
                stores_needed += (q + max_load - 1) // max_load
            return stores_needed <= n
        
        while left < right:
            mid = (left + right) // 2
            if can_distribute(mid):
                right = mid  # tenta diminuir o máximo possível
            else:
                left = mid + 1
        
        return left

