class Solution:
    def maxArea(self, height):
        i, j = 0, len(height)-1
        water = 0
        #print("i=", str(i), "j=", str(j))
        while i<j:
            print
            water = max(water, (j-i)*min(height[i], height[j]))
            if height[i]< height[j]:
                i+=1
            else:
                j-=1
        return water


if __name__ == "__main__":
    height = [1,8,6,2,5,4,8,3,7]
    a=Solution()
    print(a.maxArea(height))