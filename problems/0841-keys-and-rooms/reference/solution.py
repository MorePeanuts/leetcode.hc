class Solution:
    def canVisitAllRooms(self, rooms: list[list[int]]) -> bool:
        seen = [False] * len(rooms)
        seen[0] = True
        stack = [0]
        count = 1
        while stack:
            room = stack.pop()
            for key in rooms[room]:
                if not seen[key]:
                    seen[key] = True
                    count += 1
                    stack.append(key)
        return count == len(rooms)
