# find number of unordered subset having sum equal to x 
import sys

sys.setrecursionlimit(1000001)



def coin_combination_ordered_rec(arr,ind,sm,x,dp):
    if sm == x and ind == len(arr):
        return 1
    if sm > x or ind == len(arr):
        return 0
    if dp[ind][sm] != -1 :
        return dp[ind][sm]
    include = coin_combination_ordered_rec(arr,0,sm+arr[ind],x,dp)
    exclude = coin_combination_ordered_rec(arr,ind+1,sm,x,dp)
    dp[ind][sm] = include + exclude 
    return dp[ind][sm]


def coin_combination_unordered_rec(arr,ind,sm,x,dp):
    if sm == x and ind == len(arr):
        return 1
    if sm > x or ind == len(arr):
        return 0
    if dp[ind][sm] != -1 :
        return dp[ind][sm]
    include = coin_combination_unordered_rec(arr,0,sm+arr[ind],x,dp)
    exclude = coin_combination_unordered_rec(arr,ind+1,sm,x,dp)
    dp[ind][sm] = include + exclude 
    return dp[ind][sm]


n,m=map(int,input().split())
arr = list(map(int,input().split()))
dp = [[-1 for i in range(m+1)] for j in range(n)]
ans = coin_combination_ordered_rec(arr,0,0,m,dp)
print(ans)


