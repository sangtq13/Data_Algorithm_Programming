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

    def __partition(self, arr, low, high):
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
            pi = self.__partition(arr, low, high)
            self.quickSort(arr, low, pi-1)
            self.quickSort(arr, pi+1, high)


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


    def mergeSort(self, arr, left, right):
        if left < right:
            mid = (left + right)//2
            self.mergeSort(arr, left, mid)
            self.mergeSort(arr, mid+1, right)
            self.__merge(arr, left, mid, right)

arr = [1,3,5,6,7,2]
s = Sorting()
# s.bubbleSort(arr)
# s.insertionSort(arr)
# s.quickSort(arr, 0, len(arr)-1)
# s.selectionSort(arr)
s.mergeSort(arr, 0 ,len(arr)-1)
print(arr)

