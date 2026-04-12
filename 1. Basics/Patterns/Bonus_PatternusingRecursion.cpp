#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

void Solution(int n,int temp){

    if(n==1) {
        cout<<1<<" ";
        for(int i=1;i<2*temp-2;i++){
            cout<<"  ";
        }
        cout<<1<<endl;
        return;
    }
    
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
    }

    for(int i=1;i<2*(temp-n);i++){
        cout<<"  ";
    }
    

    // cout<<"n is "<<n<<endl;
    for(int i=n;i>=1;i--){
        if(n==temp && i==n) i--;
        cout<<i<<" ";
    }
    // cout<<"n is "<<n<<endl;
    cout<<endl;
    Solution(n-1,temp);

    for(int i=1;i<=n;i++){
        cout<<i<<" ";
    }

    for(int i=1;i<2*(temp-n);i++){
        cout<<"  ";
    }

    for(int i=n;i>=1;i--){
        if(n==temp && i==n) i--;
        cout<<i<<" ";
    }
    cout<<endl;
}



int main()
{
    int n;
    cin>>n;

    Solution(n,n);

    return 0;
}
