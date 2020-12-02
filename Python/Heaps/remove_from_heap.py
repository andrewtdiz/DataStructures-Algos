# An implementation of Removing an element from a Heap
# Time efficiency = O(log(n))
# Space efficiency = O(1)
# Andrew DiZenzo, 11/28/2020

def childCheckandSwap(arr,i):
  left = i*2+1
  right = i*2+2
  if(left>len(arr)-1):
    return
  elif(right>len(arr)-1):
    if(arr[left]>arr[i]):
      arr[left], arr[i] = arr[i], arr[left]
      return
  if(arr[left]>arr[right] and arr[left]>arr[i]):
    arr[left], arr[i] = arr[left], arr[i]
    childCheckandSwap(arr,left)
  elif(arr[right]>arr[left] and arr[right]>arr[i]):
    arr[right], arr[i] = arr[i], arr[right]
    childCheckandSwap(arr,right)

def removeFromHeap(arr):
  arr[0] = arr[-1]
  del arr[-1]
  childCheckandSwap(arr, 0)