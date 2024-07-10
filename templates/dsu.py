class DSU:
    def __init__(self, size):
        self.parent = list(range(size))
        self.rank = [0] * size
        
    def find(self, x):
        if self.parent[x] == x:
            return x
        return self.find(self.parent[x])
    
    def unite(self, x, y):
        px = self.find(x)
        py = self.find(y)
        if px == py:
            return
        if self.rank[px] > self.rank[py]:
            self.parent[py] = px
        elif self.rank[px] < self.rank[py]:
            self.parent[px] = py
        else:
            self.parent[px] = py
            self.rank[py] += 1
    
    def set_size(self, x):
        return self.rank[self.find(x)]
            
    def same_group(self, x, y):
        return self.find(x) == self.find(y)
