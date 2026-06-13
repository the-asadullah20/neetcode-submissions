class Solution:
    def solve(self, p, q):
        if not p and not q:
            return True

        if not p or not q:
            return False

        if p.val != q.val:
            return False

        return self.solve(p.left, q.left) and self.solve(p.right, q.right)

    def isSameTree(self, p, q):
        return self.solve(p, q)