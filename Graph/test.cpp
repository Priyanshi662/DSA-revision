#include <iostream>

#include <cmath>

using namespace std;


 

int main(){

// u&l are points on other side, su and sl are sides consisiting of u and l points

    long int t, n, b1, b2, u, l, su, sl;

    long long sum{};

    cin >> t;

    while(t--){

        sum = 0;

        cin >> n >> b1 >> b2;

        l = abs(b1-b2)-1;

        u = n-l-2;

        if(l>0){sl = l-1;}

        else if(l==0){sl = 0;}

        if(u>0){su = u-1;}

        else if(u==0){su = 0;}

        //cout << l << ' ' << u << ": ";


 

        //opposite side

        sum = sl*u + su*l;


 

        //same side 1 side common

        if(l>3){sum += (l-3)*(l-2);}

        if(u>3){sum += (u-3)*(u-2);}


 

        //same side 2 side common

        if(sl>1){sum += sl-1;}

        if(su>1){sum += su-1;}


 

        cout << sum << '\n';

    }

}