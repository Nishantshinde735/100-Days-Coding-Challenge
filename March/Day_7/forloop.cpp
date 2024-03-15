#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    
    cout<<"counting number from 1 to n"<<endl;
    int i=1 ;

    for( ; ;)
    {
        if(i<=n)
         cout<<i<<endl;
        
        else 
        {
            break;
       
        }
        i++;
   
    } 
}
