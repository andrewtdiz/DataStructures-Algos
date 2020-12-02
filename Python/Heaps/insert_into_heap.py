# An implementation of Inserting into a Heap
# Time efficiency = O(log(n))
# Space efficiency = O(1)
# Andrew DiZenzo, 11/28/2020

def parentCheckAndSwap(arr,ind):
  if(arr[ind//2]<arr[ind]):
    arr[ind//2], arr[ind] = arr[ind], arr[ind//2]
  if(ind==0): return  
  parentCheckAndSwap(arr,ind//2)

def insertIntoHeap(arr,elem):
  arr.append(elem)
  l = len(arr)-1
  parentCheckAndSwap(arr,l)