#include<iostream>
using namespace std;
typedef long long ll;


void IterativeMethod(int n){

    if(n>=0)cout<<0<<" ";

    if(n>=1)cout<<1<<" ";

    int prev2=0,prev1=1;

    for(int i=2;i<n;i++){

        int curr=prev2+prev1;

        prev2=prev1;
        prev1=curr;
        cout<<curr<<" ";
    }

    return;

}

int RecursiveMethod(int n)
{

    if (n <= 1)
        return n;
    return RecursiveMethod(n - 1) + RecursiveMethod(n - 2);

}


int main(){
    int n;
    cout<<"Enter Number"<<endl;
    cin>>n;

    IterativeMethod(n);
    cout<<"\n";


for(int i=0;i<n;i++)
{
    cout<<RecursiveMethod(i)<<" ";
}

return 0;

}