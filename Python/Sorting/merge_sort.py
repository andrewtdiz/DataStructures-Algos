# An implementation of Merge Sort in python
# Time efficiency = O(n log(n))
# Space efficiency = O(n)
# Andrew DiZenzo, 11/28/2020

def merge(arr1,arr2):
  hold = []
  while(len(arr1)>0 and len(arr2)>0):
    if(arr1[0]<=arr2[0]):
      hold.append(arr1.pop(0))
    else:
      hold.append(arr2.pop(0))
  
  while(len(arr1)>0):
    hold.append(arr1.pop(0))
  
  while(len(arr2)>0):
    hold.append(arr2.pop(0))
  return hold


def mergeSort(arr):
  if(len(arr)==1):
    return arr
  mid = len(arr)//2
  return merge(mergeSort(arr[0:mid]), mergeSort(arr[mid:]))
