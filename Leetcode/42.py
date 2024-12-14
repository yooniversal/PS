class Solution:
    def trap(self, height: List[int]) -> int:
        water = 0

        l = 0
        r = len(height) - 1
        maxLeft, maxRight = height[l], height[r]

        while l < r:
            if maxLeft < maxRight:
                l += 1
                maxLeft = max(maxLeft, height[l])
                water += maxLeft - height[l]
                continue
            
            r -= 1
            maxRight = max(maxRight, height[r])
            water += maxRight - height[r]
            
        return water
