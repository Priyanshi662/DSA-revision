// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


class Solution 
{
    public:
    static bool comparator(Job a,Job b)
    {
        return a.profit > b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    {
        vector<int> res;
        // returns count of jobs and maximum profit in vector
        sort(arr,arr+n,comparator);
        vector<bool> schedule(n,false);
        int ans=0;
        int profit=0;
        for(int i=0;i<n;i++)
        {
            // For all the jobs :
            int d=arr[i].dead;
            for(int j=min(n,d-1);j>=0;j--)
            {
                // For all the deadlines before it:
                if(!schedule[j])
                {
                    // j is the time to be scheduled for job[i]
                    ans+=1;
                    // i is the job to be scheduled
                    profit+=arr[i].profit;
                    schedule[j]=true;
                    // break to prevent furthur scheduling of this job[i]
                    break;
                }
            }
        }
        res.push_back(ans);
        res.push_back(profit);
        return res;
    }
};

int main() 
{ 
        int n;
        
        //size of array
        cout<<"Enter size of array :";
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        cout<<"Enter details of "<<n<<" jobs: Job id ,deadline , profit format"<<endl;
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<"Answer : "<<endl;
        cout<<ans[0]<<" "<<ans[1]<<endl;
	return 0; 
}