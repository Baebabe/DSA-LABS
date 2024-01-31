#include<iostream>
using namespace std;
void towerofhanoi(int n, char src,char dest, char auxiliary){
    if(n==0){
        return;
    }
    towerofhanoi(n-1,src,auxiliary,dest);
    cout<<"Moving from "<<src<<" to "<<dest<<endl;
    towerofhanoi(n-1,auxiliary,dest,src);
}
int main()
{
 towerofhanoi(1,'A','C','B');
return 0;
}