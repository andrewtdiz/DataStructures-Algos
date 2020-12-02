# Implementations of Largest Subarray problem in python

# Brute Force Solution
# Time efficiency = O(n^2)
# Space efficiency = O(1)
# Andrew DiZenzo, 11/28/2020

def maxSubArray(arr):
  max = -math.inf
  for i in range(0,len(arr)):
    sum = 0
    for j in range(i,len(arr)):
      sum += arr[j]
      if(sum>max): max = sum
  return max

# Optimization 1: 
# Time efficiency = O(n)
# Space efficiency = O(1)
# Andrew DiZenzo, 11/28/2020

def middleSubArrayHandler(arr,p,q,r):
  leftMax = -math.inf
  rightMax = -math.inf
  sum = 0
  for i in range(q,p-1,-1):
    sum += arr[i]
    if(sum>leftMax): leftMax = sum
  sum = 0
  for i in range(q+1,r+1):
    sum += arr[i]
    if(sum>rightMax): rightMax = sum
  return max(leftMax, rightMax, leftMax+rightMax)

def divideAndConqMaxSubarray(arr,p=0,r=len(arr)-1):
  if(p==r): return arr[p]
  q = (p+r)#2
  return max(divideAndConqMaxSubarray(arr, p, q),divideAndConqMaxSubarray(arr, q+1,r), middleSubArrayHandler(arr,p,q,r))


# Optimization 2: Kadanes Algorithm 
# Time efficiency = O(n)
# Space efficiency = O(1)
# Andrew DiZenzo, 11/28/2020

def maxSubArray(arr):
  maximum = -math.inf
  sum = 0
  for (i,val) in enumerate(arr):
    sum = max(0,sum+val)
    maximum = max(sum,maximum)
  return maximum
