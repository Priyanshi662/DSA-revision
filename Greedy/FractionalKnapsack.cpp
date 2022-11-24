#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool comparator(Item a,Item b)
    {
        double p1=(double)a.value/a.weight;
        double p2=(double)b.value/b.weight;
        return p1>p2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Sort by profit/weight value :
        // For example -
        // value - 60 30 100 50 120
        // weight- 10 20 20  30  30
        sort(arr,arr+n,comparator);
        double profit=0;
        for(int i=0;i<n;i++)
        {
            int wt=arr[i].weight;
            int value=arr[i].value;
            if(wt<=W)
            {
                profit+=value;
                W-=wt;
            }
            else{
                double currentvalue=(((double)value*W)/(double)wt);
                profit+=currentvalue;
            }
        }
        return profit;
    }
        
};


int main()
{
	    //size of array and weight
        cout<<"Enter number of items and Total Capacity : ";
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
        cout<<"Enter profit and Weight of each item : ";
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
    return 0;
}