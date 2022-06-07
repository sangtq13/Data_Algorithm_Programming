import time

class Sorting(object):
    def bubbleSort(self, arr):
        s = len(arr)
        for i in range(s):
            for j in range(s-i-1):
                if arr[j] > arr[j+1]:
                    arr[j], arr[j+1] = arr[j+1], arr[j]

    def insertionSort(self, arr):
        s = len(arr)
        for i in range(1, s):
            key = arr[i]
            j = i-1
            while j >= 0 and arr[j] > key:
                arr[j+1] = arr[j]
                j-= 1
            arr[j+1] = key

    def selectionSort(self, arr):
        s = len(arr)
        for i in range(s-1):
            min_index = i
            for j in range(i+1, s):
                if arr[j] < arr[min_index]:
                    min_index = j
            arr[i], arr[min_index] = arr[min_index], arr[i]

    #arr = [3,1,5,6,7,2]
    def __partitionLeft(self, arr, low, high):
        i = low
        pivot = arr[low]
        for j in range(low+1, high+1):
            if arr[j] <= pivot:
                i += 1
                arr[i], arr[j] = arr[j], arr[i]
        arr[i], arr[low] = arr[low], arr[i]

        return i

    def __partitionMid(self, arr, low, high):
        mid = (low+high)//2
        pivot = arr[mid]
        i = low
        j = high
        while i < j:
            while arr[i] < pivot:
                i += 1
            while arr[j] > pivot:
                j -= 1
            arr[i], arr[j] = arr[j], arr[i]
        if i>=j:
            return j
        return i+1

    def __partitionRight(self, arr, low, high):
        i = low-1
        pivot = arr[high]
        for j in range(low, high):
            if arr[j] <= pivot:
                i += 1
                arr[i], arr[j] = arr[j], arr[i]
        arr[i+1], arr[high] = arr[high], arr[i+1]
        return i+1

    def quickSort(self, arr, low, high):
        if low < high:
            # pi = self.__partitionRight(arr, low, high)
            # pi = self.__partitionMid(arr, low, high)
            pi = self.__partitionLeft(arr, low, high)
            self.quickSort(arr, low, pi-1)
            self.quickSort(arr, pi+1, high)

    def quickSortIterative(self, arr, low, high):
        stack = [[low, high]]
        while stack:
            left, right = stack.pop()
            if left < right:
                pi = self.__partitionLeft(arr, left, right)
                stack.append([pi+1, right])
                stack.append([low, pi-1])

    def __merge(self, arr, left, mid, right):
        left_arr = arr[left:mid+1]
        right_arr = arr[mid+1:right+1]
        i = 0
        j = 0
        merge_index = left

        while i < mid-left+1 and j < right-mid:
            if left_arr[i] <= right_arr[j]:
                arr[merge_index] = left_arr[i]
                i += 1
            else:
                arr[merge_index] = right_arr[j]
                j += 1
            merge_index += 1

        while i < mid-left+1:
            arr[merge_index] = left_arr[i]
            merge_index += 1
            i += 1
        while j < right-mid:
            arr[merge_index] = right_arr[j]
            merge_index += 1
            j += 1

    def __mergeSortHelper(self, arr, left, right):
        if left < right:
            mid = (left + right)//2
            self.__mergeSortHelper(arr, left, mid)
            self.__mergeSortHelper(arr, mid+1, right)
            self.__merge(arr, left, mid, right)
    def mergeSort(self, arr):
        left = 0
        right = len(arr)-1
        self.__mergeSortHelper(arr, left, right)

    # Merge from bottom up with width is the power of 2: 1, 2, 4, 8, ...
    def mergeSortIterativeA(self, arr):
        n = len(arr)-1
        width = 1
        while width < n:
            left = 0
            while left < n:
                mid = min(left + width - 1, n)
                right = min(left + width * 2 - 1, n)
                self.__merge(arr, left, mid, right)
                left += width * 2
            width *= 2

arr = [3,1,5,6,8,10,4,13,9,7,2]
s = Sorting()
# s.bubbleSort(arr)
# s.selectionSort(arr)
# s.insertionSort(arr)
# s.quickSort(arr, 0, len(arr)-1)
# s.quickSortIterative(arr, 0, len(arr)-1)
st = time.time()
s.mergeSort([3,1,5,6,8,10,4,13,9,7,2])
et = time.time()
print(et-st)
st = time.time()
s.mergeSortIterative([3,1,5,6,8,10,4,13,9,7,2])
et = time.time()
print(et-st)


