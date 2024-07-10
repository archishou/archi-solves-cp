class Fenwick:
    def findRSB(self, i):
        return i & -i
    
    def __init__(self, nums):
        self.n = len(nums) + 1
        self.nums = [0] + nums
        self.tree = [0 for i in range(self.n)]
        
        for i in range(1, self.n):
            self.tree[i] = self.nums[i]
            
        for child in range(1, self.n):
            parent = child + self.findRSB(child)
            if parent < self.n:
                self.tree[parent] += self.tree[child]

    def update(self, index, val):
        index += 1
        toAdd = val - self.nums[index]
        self.nums[index] = val
        i = index
        while i < self.n:
            self.tree[i] += toAdd
            i += self.findRSB(i)

    def prefix(self, i):
        ans = 0
        while i != 0:
            ans += self.tree[i]
            i -= self.findRSB(i)
        return ans
    
    def range_sum(self, left, right):
        return self.prefix(right) - self.prefix(left)

f = Fenwick([0 for _ in range(3)])
f.update(0, 1)
f.update(1, 2)
f.update(2, 3)
print(f.range_sum(0, 3))

