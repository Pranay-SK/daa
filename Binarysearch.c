#include<stdio.h>
int bs(int array[],int x,int low,int high){
    if(high>=low){
    int mid=(high+low)/2;
    if(array[mid]==x)
    return mid;
    
    if(array[mid]>x)
    return bs(array,x,low,mid-1);
    else
    return bs(array,x,mid+1,high);
    }
    return -1;
}
int main(){
    int array[]={1,3,4,6,7,8,99,101,233};
    int n=sizeof(array)/sizeof(array[0]);
    int x=4;
    int result=bs(array,x,0,n-1);
    if(result==-1){
        printf("\nNOT FOUND...!");
    }
    else{
        printf("FOUND AT INDEX %d",result);
    }
    return 0;
}