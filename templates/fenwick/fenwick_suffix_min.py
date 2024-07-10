class FenwickTreeMin:
    def __init__(self, arr):
        self.n = len(arr)
        self.bit = [float('inf')] * len(arr)
        for idx, v in enumerate(arr):
            self.update(idx, v)

    def update(self, idx, val):
        while idx >= 0:
            self.bit[idx] = min(self.bit[idx], val)
            idx = (idx & (idx + 1)) - 1

    def get_min(self, l):
        ret = float('inf')
        while l < self.n:
            ret = min(ret, self.bit[l])
            l |= l + 1
        return ret
