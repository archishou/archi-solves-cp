class Fenwick:
    def findRSB(self, i):
        return i & -i
    
    def __init__(self, nums: List[int]):
        self.n = len(nums) + 1
        self.nums = [0] + nums
        self.tree = [0 for i in range(self.n)]
        
        for i in range(1, self.n):
            self.tree[i] = self.nums[i]
            
        for child in range(1, self.n):
            parent = child + self.findRSB(child)
            if parent < self.n:
                self.tree[parent] += self.tree[child]

    def update(self, index: int, val: int) -> None:
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
    
    def range_sum(self, left: int, right: int) -> int:
        return self.prefix(right + 1) - self.prefix(left)
