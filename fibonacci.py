class Solution:
  def fibonacci(self, n):
    if n == 0:
      return 0
    if n == 1:
      return 1
    return self.fib(n-1) + self.fib(n-2)

  def fibIterative(self, n):
    stack = []
    stack.append(n)
    sum = 0
    while(len(stack) > 0):
      n = stack.pop()
      if n == 0:
        sum += 0
      elif n == 1:
        sum +=1
      else:
        stack.append(n-1)
        stack.append(n-2)
    return sum
  def fibonacciB(self, n):
    if n == 1 or n == 2: return 1
    pre = 1
    cur = 1
    for i in range(3, n+1):
        pre, cur = cur, pre+cur
    return cur

    def fibonacciC(self, n):
      a = math.sqrt(5)
      return round(1/a * ((0.5 + a/2) ** n + (0.5 - a/2) ** n))

s = Solution()
# print(s.fibonacciA(50))
print(s.fibonacciB(50))
print(s.fibonacciC(50))
    
