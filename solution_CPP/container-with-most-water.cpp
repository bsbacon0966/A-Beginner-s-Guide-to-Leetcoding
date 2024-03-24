// using pointer to point the suit vertical lines
// and , if left line is shorter than right , the move the left pointer until left line is longer than right
// because if left line is not longer than right , the value will always smaller than previous value

class Solution {
public:
    int maxArea(vector<int>& height) {
        int low;
        int high;
        int maxwater;
        long int now;
        low=0;
        high=height.size()-1;
        maxwater=0;
        while(low<high){
            now=min(height[high],height[low])*(high-low);
            if(now>maxwater){
                maxwater=now;
            }
            if(height[low]<height[high]){
                low++;
            }
            else{
                high--;
            }
        }
        return maxwater;
    }
};