class Node:
    left = -1
    right = -1
    parent = None
    highNode = 0

    def __init__(self, value):
        self.value = value

    def _insert_rigth(self, node):
        if(self.right != -1):
            return self.right.insert(node)
        else:
            self.right = node
            return 1
    
    def _insert_left(self, node):
        if(self.left != -1):
            return height += self.left.insert(node)
        else:
            self.left = node
            return 1

    def check_height(self, height):
        if (height > self.highNode)
            

    def insert(self, node):
        height = 0
        if (node.value > self.value):
            height += self._insert_rigth(node)
        else:
            height += self._insert_left(node)
        check_height(height)
