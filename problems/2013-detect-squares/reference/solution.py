from collections import Counter, defaultdict

class DetectSquares:
    def __init__(self):
        self.columns = defaultdict(Counter)

    def add(self, point: list[int]) -> None:
        x, y = point
        self.columns[x][y] += 1

    def count(self, point: list[int]) -> int:
        x, y = point
        total = 0
        for other_y, multiplicity in self.columns.get(x, {}).items():
            side = other_y - y
            if side == 0:
                continue
            for other_x in (x - side, x + side):
                column = self.columns.get(other_x, {})
                total += multiplicity * column.get(y, 0) * column.get(other_y, 0)
        return total
