class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hashmap = {}
        for index, num in enumerate(nums):
            target_rest = target - num
            if target_rest in hashmap:
                return [hashmap[target_rest], index]
            hashmap[num] = index
        return None

if __name__ == "__main__":
    sol = Solution()
    print(sol.twoSum([2,5,4,6], 7))