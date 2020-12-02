# An implementation of Quick Sort in python
# Implemented with the pivot at the end of the array
# Time efficiency = O(n log(n))
# Space efficiency = O(1)
# Andrew DiZenzo, 11/28/2020

def quickSort(arr):
  if(len(arr)<=1): return arr
  pivot=len(arr)-1
  i=0
  while(i<pivot):
    if(arr[i]>arr[pivot]):
      arr.append(arr.pop(i))
      pivot -= 1
    else: i += 1
  return quickSort(arr[0:pivot]) + [arr[pivot]] + quickSort(arr[pivot+1:])
  

# An implementation of Quick Sort in python
# Implemented with a central pivot
# Time efficiency = O(n log(n))
# Space efficiency = O(1)
# Andrew DiZenzo, 11/28/2020

  def quickSort(arr):
  if(len(arr)<=1): return arr
  pivot = len(arr)//2
  i=0
  while(i<pivot):
    if(arr[i]>arr[pivot]):
      arr.append(arr.pop(i))
      pivot -= 1
    else: i += 1
  i=0
  while(pivot+i+1<len(arr)-1):
    if(arr[pivot+i+1]<arr[pivot]):
      hold = arr.pop(pivot+i+1)
      arr = [hold] + arr
      pivot+=1
    else: i+=1
  left = arr[0:pivot]
  right = arr[pivot+1:]
  return quickSort(left) + [arr[pivot]] + quickSort(right)

