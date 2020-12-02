# An implementation of Bubble Sort in python
# Time efficiency = O(n^2)
# Space efficiency = O(1)
# Andrew DiZenzo, 11/28/2020

def bubbleSort(arr):
  for i in range(0,len(arr)):
    count = 0
    for j in range(0,len(arr)-1):
      if(arr[j]>arr[j+1]):
        arr[j], arr[j+1] = arr[j+1], arr[j]
        count+=1
    if(count==0):
      break
  return arr
