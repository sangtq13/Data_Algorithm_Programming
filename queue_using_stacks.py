class Queue(object):
    def __init__(self):
        self.name = 'S->13'
        self.s1 = []
        self.s2 = []

    def enqueue(self, value):
        self.s1.append(value)

    def dequeue(self):
        if self.s2:
            return self.s2.pop()
        if self.s1:
            while self.s1:
                self.s2.append(self.s1.pop())
            return self.s2.pop()
        return None
q = Queue()
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
print(q.dequeue())
q.enqueue(4)
q.enqueue(5)
print(q.dequeue())
print(q.dequeue())
print(q.dequeue())
print(q.dequeue())
