// link : https://leetcode.com/problems/container-with-most-water/description/

// the solution :
/*
Intuition:
The maximum water container problem can be efficiently solved using a two-pointer approach. 
By starting with pointers at both ends of the array and moving the pointer with the shorter height inward,
we ensure we explore all potential maximum areas optimally. The key insight is that the area is always
constrained by the shorter line, so moving the taller pointer would never increase the area.

Approach:
1. Initialize two pointers: left at start (0) and right at end (n-1)
2. Calculate current area: min(height[left], height[right]) * (right - left)
3. Track maximum area encountered
4. Move the pointer pointing to the shorter line inward
   - If heights are equal, move both pointers
   - Skip all subsequent lines that are shorter than current line
5. Repeat until pointers meet

Complexity Analysis:
- Time Complexity: O(n) - Each element is visited at most once
- Space Complexity: O(1) - Constant extra space is used
*/

#include <vector>
#include <algorithm> // For std::min and std::max

using  namespace std;

  int maxArea(vector<int>& height) {
        int left{};
        int right = height.size() - 1;

        int bigArea{};
        while(left < right){
            // Calculate current area
            int leftLine{height.at(left)};
            int rightLine{height.at(right)};
          
            int waterArea{min(leftLine, rightLine) * (right - left)};
            if(waterArea > bigArea)
                bigArea = waterArea;
          
            // Move pointers and skip smaller heights
            if(leftLine > rightLine)
                while(height.at(--right) < rightLine);
            else if(rightLine > leftLine)
                while(height.at(++left) < leftLine);
            else
                ++left,--right;
        }
        return bigArea;
    }
