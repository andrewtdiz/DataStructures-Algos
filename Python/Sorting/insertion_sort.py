# An implementation of Insertion Sort in python
# Time efficiency = O(n^2)
# Space efficiency = O(1)
# Andrew DiZenzo, 11/28/2020

def insertionSort(arr):
  for i in range(1,len(arr)):
    for j in range(i,0,-1):
      if(arr[j]>arr[j+1]):
        arr[j], arr[j+1] = arr[j+1], arr[j]
  return arr
