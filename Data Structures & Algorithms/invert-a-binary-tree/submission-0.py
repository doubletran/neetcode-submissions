# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def invert(curr):
            inverted_right, inverted_left = None, None
            if not curr:
                return None
            if curr.right:
                inverted_right = invert(curr.right)
            if curr.left:
                inverted_left = invert(curr.left)
            curr.right, curr.left = inverted_left, inverted_right
            return curr
        return invert(root)

            

        