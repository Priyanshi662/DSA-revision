class Solution{
    int findCandidate(int a[],int n){
        int count=0;
        int maj_ele=a[0];
        for(int i=0;i<n;i++){
            if(a[i]==maj_ele){
                count++;
            }
            else
                count--;
            if(count==0)
            {
                maj_ele=a[i];
                count=1;
            }
        }
        return maj_ele;
    }
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array

    int majorityElement(int a[], int size)
    {
      int cnd=findCandidate(a,size);
        int count=0;
        for(int i=0;i<size;i++)
        {
            if(cnd==a[i])
            count++;
        }
        if(count>(size/2))
            return cnd;
        else
            return -1;   
    }
};