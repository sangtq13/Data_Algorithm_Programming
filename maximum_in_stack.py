# Implement max function for stack. It will return maximum of stack
# in O(1) time complexity but we need to O(n) space complexity to
# store array of max valud at each index of stack.
class Stack(object):
    def __init__(self):
        self.name = 'S->13'
        self.stack = []
        self.maxes = []

    def push(self, value):
        self.stack.append(value)
        if self.maxes and value < self.maxes[-1]:
            self.maxes.append(self.maxes[-1])
        else:
            self.maxes.append(value)

    def pop(self):
        if self.maxes:
            self.maxes.pop()
        return self.stack.pop()

    def max(self):
        return self.maxes[-1]

s = Stack()
s.push(1)
s.push(2)
s.push(3)
s.push(2)
print('max', s.max())
print(s.pop())
