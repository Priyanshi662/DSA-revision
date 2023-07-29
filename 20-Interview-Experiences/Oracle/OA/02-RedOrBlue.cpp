/*
There are a number of cities in a row, and there are two bus lines
that go between them. They both visit all cities in order, but one
may take longer than the other to go between any two cities.
Starting on or moving to the Blue line takes a certain amount of
extra time. There is no extra time required to start on or move to
the Red line. Determine the minimum cost to move from the first
city to each of the cities.
.
There are 4 cities numbered 0 through 3. Times from city 0 to cities
1, 2, and 3 are at indices 0, 1, and 2 respectively in the red and blue
arrays.
Through the explanation, an answer array, ans, will be created
• The minimum cost to go from city 0 to itself is 0. Now ans (0
• The time from city 0 to city 1 is
o 2 on the Red line
. Continuing to city 2:
second leg, Now ans 24
To get to city 3:
o take the Red Bine arriving at 549
stay on the Blue Bloe arong at
Test
Results
3+ blueCost-5 on the Blue line
• The blueCost applies when you start on the Blue line
The minimum time to city 1 is 2 on the Red line, so ans-4
stay on the Red line, arriving at 2+3=5
switch to the Blue line and arrive at 2+1+248
*/
// Brute force:
#include <bits/stdc++.h>
using namespace std;

int cost(int red[],int blue[],int n,int bcost)
{
    int redDp[n+1];
    int blueDp[n+1];
    redDp[0]=0;
    blueDp[0]=bcost;
    int ans[n];
    ans[0]=0;
    for(int i=1;i<n;i++)
    {
        redDp[i]=min(redDp[i-1]+red[i-1],redDp[i-1]+blue[i-1]);
        blueDp[i]=min(blueDp[i-1]+blue[i-1],redDp[i-1]+bcost+blueDp[i-1]);
        ans[i]=min(redDp[i],blueDp[i]);
    }
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    return ans[n-1];
}
int main()
{
    int red[]={2,1,4,5};
    int blue[]={3,2,1,2};
    int bcost=2;
    int mincost=cost(red,blue,4,bcost);
    cout<<mincost<<endl;
}