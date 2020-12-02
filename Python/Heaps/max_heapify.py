# An implementation of Creating a Max Heap
# Time efficiency = O(n log(n))
# Space efficiency = O(1)
# Andrew DiZenzo, 11/28/2020

arr = [10,20,15,12,40,25,18]

def heapify(arr,i):
  if(i>len(arr)//2-1): return 
  if(arr[i*2+1]>arr[i*2+2] and arr[i*2+1]>arr[i]):
    arr[i], arr[i*2+1] = arr[i*2+1], arr[i]
    heapify(arr,i*2+1)
  elif (arr[i*2+1]<arr[i*2+2] and arr[i*2+2]>arr[i]):
    arr[i], arr[i*2+2] = arr[i*2+2], arr[i]
    heapify(arr,i*2+2)
  
def buildHeap(arr):
  for i in range(len(arr)//2-1, -1, -1):
    heapify(arr,i)

buildHeap(arr)