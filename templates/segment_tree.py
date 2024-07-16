class SegmentTree:
    def __init__(self, data, join_func):
        self.n = len(data)
        self.tree = [0] * (2 * self.n)
        self.join_func = join_func
        self._build(data)
    
    def _build(self, data):
        for i in range(self.n):
            self.tree[self.n + i] = data[i]
        for i in range(self.n - 1, 0, -1):
            self.tree[i] = self.join_func(self.tree[2 * i], self.tree[2 * i + 1])
    
    def update(self, pos, value):
        pos += self.n
        self.tree[pos] = value
        while pos > 1:
            pos //= 2
            self.tree[pos] = self.join_func(self.tree[2 * pos], self.tree[2 * pos + 1])
    
    def query(self, left, right):
        left += self.n
        right += self.n
        result = None
        while left < right:
            if left % 2:
                if result is None:
                    result = self.tree[left]
                else:
                    result = self.join_func(result, self.tree[left])
                left += 1
            if right % 2:
                right -= 1
                if result is None:
                    result = self.tree[right]
                else:
                    result = self.join_func(result, self.tree[right])
            left //= 2
            right //= 2
        return result

