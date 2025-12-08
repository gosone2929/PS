def maxProduct(nums: list[int]) -> int:
        dp = []
        dp.append((nums[0], nums[0], nums[0]))

        for i in range(1, len(nums)):
            cur = nums[i]
            tempMax = max(dp[i - 1])
            tempMin = min(dp[i - 1])

            dp.append((cur, tempMax * cur, tempMin * cur))
        
        x = []
        for t in dp:
            for p in t:
                x.append(p)
        print(x)
        return max(x)
    
print(maxProduct([2,3,-2,4]))