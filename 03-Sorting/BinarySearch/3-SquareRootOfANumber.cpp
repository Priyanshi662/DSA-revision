class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
            return x;
        int low=1,high=x;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(mid==x/mid)
                return mid;
            else if(mid>x/mid)
                high=mid-1;
            else 
                low=mid+1;
        }
        // at last iteration high=mid-1 so it is the floor value which we should return
        return high;
    }
};