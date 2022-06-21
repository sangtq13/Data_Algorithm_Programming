class MyQueue(object):

    def __init__(self):
        self.s1 = []
        self.s2 = []

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.s1.append(x)
        

    def pop(self):
        """
        :rtype: int
        """
        if self.s2:
            return self.s2.pop()
        if self.s1:
            while self.s1:
                self.s2.append(self.s1.pop())
            return self.s2.pop()
        return None

    def peek(self):
        """
        :rtype: int
        """
        if self.s2:
            return self.s2[-1]
        if self.s1:
            while self.s1:
                self.s2.append(self.s1.pop())
            return self.s2[-1]
        return None
        
        

    def empty(self):
        """
        :rtype: bool
        """
        return not self.s1 and not self.s2
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
