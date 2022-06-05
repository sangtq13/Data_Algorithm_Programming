class Heap(object):
    def __init__(self, minHeap=False):
        self.name = "S->13"
        self.minHeap = minHeap

    def __compare(self, a, b, greater=True):
        if greater:
            return a>b
        else:
            return a<b

    def __heapifydown(self, arr, n ,i, greater=True):
        largest = i
        l = 2*i + 1
        r = 2*i + 2

        if l<n and self.__compare(arr[largest], arr[l], greater):
            largest = l
        if l<n and self.__compare(arr[largest], arr[r], greater):
            largest = r
        if largest != i:
            arr[i], arr[largest] = arr[largest], arr[i]
            self.__heapifydown(arr, n ,largest, greater)

    def buildHeap(self, arr):
        # Index of last non-leaf node
        n = len(arr)
        startIdx = n // 2 - 1

        # Perform reverse level order traversal
        # from last non-leaf node and heapify
        # each node
        for i in range(startIdx, -1, -1):
            self.__heapifydown(arr, n, i, self.minHeap)

    def delete(self, arr):
        lastElement = arr[-1]
        arr[0] = lastElement
        arr.pop()
        self.__heapifydown(arr, len(arr)-1, 0, self.minHeap)

    def __heapifyup(self, arr, n, i, greater=True):
        parent = (i-1)//2
        if parent >= 0 and self.__compare(arr[i], arr[parent], not greater):
            arr[i], arr[parent] = arr[parent], arr[i]
            self.__heapifyup(arr, n, parent, self.minHeap)

    def insert(self, arr, value):
        arr.append(value)
        n = len(arr)
        self.__heapifyup(arr, n, n-1, self.minHeap)

    def heapSort(self, arr):
        if len(arr) == 1:
            return
        n = len(arr)-1
        while n >= 1:
            arr[0], arr[n] = arr[n], arr[0]
            n -= 1
            self.__heapifydown(arr, n, 0, self.minHeap)

# arr = [1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17]
# minHeap = Heap(True)
# minHeap.buildHeap(arr)
# print(arr)
# minHeap.delete(arr)
# print(arr)
# minHeap.insert(arr,1)
# print(arr)
# minHeap.delete(arr)
# print(arr)
array = [1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17]
maxHeap = Heap(False)
maxHeap.buildHeap(array)
print(array)
maxHeap.heapSort(array)
print(array)
