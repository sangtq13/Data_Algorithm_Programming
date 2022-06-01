class Solution:
  def fib(self, n):
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

print Solution().fib(10)
print Solution().fibIterative(10)
