class Solution:
    def findDuplicates(self, nums: list[int]) -> list[int]:
        st = set()
        for i in nums:
            if nums[abs(i)-1] < 0 :
                st.add(abs(i))
            else:
                nums[abs(i)-1] = -nums[abs(i)-1]
        
        return list(st)

        