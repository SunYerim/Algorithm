#이진 트리의 넓이 우선 순회(ArrayQueue() 메소드도 구현)
class ArrayQueue:
    def __init__(self):
        self.data = []
    
    def size(self):
        return len(self.data)
    
    def isEmpty(self):
        return self.size() == 0
    
    def enqueue(self, x):
        self.data.append(x)
    def dequeue(self):
        return self.data.pop(0) #제일 앞 데이터 삭제
    def peek(self):
        return self.data[0]

class Node:
    def __init__(self, item):
        self.data = item
        self.left = None
        self.right = None

class BinaryTree:
    def __init__ (self, r):
        self.root = r
    
    def bft(self):
        result = []
        q = ArrayQueue()
        if self.root:
            q.enqueue(self.root)
            while not q.isEmpty():
                node = q.dequeue()
                result.append(node.data)
                if node.left:
                    q.enqueue(node.left)
                if node.right:
                    q.enqueue(node.right)
        else:
            result = []
        
        return result

def solution(x):
    return 0