class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums.sort()
        ans = []
        n = len(nums)
        for i in range(n):
            if(i>0 and nums[i]==nums[i-1]): continue
            req = -nums[i]
            lo = i+1
            hi = n-1
            while(lo<hi):
                sumi = nums[lo] + nums[hi]
                if(sumi == req):
                    temp = [nums[i],nums[lo],nums[hi]]
                    ans.append(temp)
                    lo+=1
                    ## duplicaltes hatane ke liye
                    while(lo<hi and nums[lo]==nums[lo-1]):lo+=1
                    hi-=1
                    ##duplicates hatane ke liye
                    while(lo<hi and nums[hi]==nums[hi+1]): hi-=1
                elif(sumi>req):
                    hi-=1
                elif(sumi<req):
                    lo+=1
            
        return ans
        