import heapq

class Solution:
    def mostBooked(self, n, meetings):
        meetings.sort()
        available = list(range(n))
        heapq.heapify(available)
        used = []  # (end_time, room)
        count = [0] * n

        for start, end in meetings:
            duration = end - start

            # Libera salas que já ficaram disponíveis
            while used and used[0][0] <= start:
                _, room = heapq.heappop(used)
                heapq.heappush(available, room)

            if available:
                room = heapq.heappop(available)
                heapq.heappush(used, (end, room))
            else:
                end_time, room = heapq.heappop(used)
                heapq.heappush(used, (end_time + duration, room))

            count[room] += 1

        return count.index(max(count))
