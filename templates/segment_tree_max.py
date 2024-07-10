class SegmentTree:
    def __init__(self, data):
        self.n = len(data)
        self.tree = [0] * (2 * self.n)
        self._build(data)
    
    def _build(self, data):
        for i in range(self.n):
            self.tree[self.n + i] = data[i]
        for i in range(self.n - 1, 0, -1):
            self.tree[i] = max(self.tree[2 * i], self.tree[2 * i + 1])
    
    def update(self, pos, value):
        pos += self.n
        self.tree[pos] = value
        while pos > 1:
            pos //= 2
            self.tree[pos] = max(self.tree[2 * pos], self.tree[2 * pos + 1])
    
    def query(self, left, right):
        # Query the maximum in the range [left, right)
        left += self.n
        right += self.n
        maximum = float('-inf')
        while left < right:
            if left % 2:
                maximum = max(maximum, self.tree[left])
                left += 1
            if right % 2:
                right -= 1
                maximum = max(maximum, self.tree[right])
            left //= 2
            right //= 2
        return maximum
