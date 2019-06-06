import sys

class Node:
    def __init__(self,data):
        self.right=self.left=None
        self.data = data
class Solution:
    def insert(self,root,data):
        if root==None:
            return Node(data)
        else:
            if data<=root.data:
                cur=self.insert(root.left,data)
                root.left=cur
            else:
                cur=self.insert(root.right,data)
                root.right=cur
        return root
    def levelOrderHelper(self, q):
        if len(q) == 0:
            return
        
        node = q.pop(0)
        print(node.data, end=' ')
        if node.left:
            q.append(node.left)
        if node.right:
            q.append(node.right)
        self.levelOrderHelper(q)

    def levelOrder(self,root):
        if not root:
            return
        print(root.data, end=' ')
        
        q = []
        q.append(root.left)
        q.append(root.right)
        self.levelOrderHelper(q)

T=int(input())
