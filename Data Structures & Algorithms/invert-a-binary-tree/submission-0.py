# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def solve(self,root:Optional[TreeNode]):
        if not root:
            return
        r=root.right
        l=root.left
        root.right=l
        root.left=r
        self.solve(root.left)
        self.solve(root.right)

    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.solve(root)
        return root
        