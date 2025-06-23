#include<stdio.h>
int main(){
    int a[2][2],b[2][2],c[2][2];
    int t1,t2,t3,t4,t5,t6,t7;
    printf("Enter matrix one elements:\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&a[i][j]);
        }
    }
     printf("Enter matrix two elements:\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&b[i][j]);
        }
    }
    t1=(a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
    t2=b[0][0]*(a[1][0]+a[1][1]);
    t3=a[0][0]*(b[0][1]-b[1][1]);
    t4=a[1][1]*(b[1][0]-b[0][0]);
    t5=b[1][1]*(a[0][0]+a[0][1]);
    t6=(b[0][0]+b[0][1])*(a[1][0]-a[0][0]);
    t7=(b[1][0]+b[1][1])*(a[0][1]-a[1][1]);
    
    c[0][0]=t1+t4-t5+t7;
    c[0][1]=t3+t5;
    c[1][0]=t2+t4;
    c[1][1]=t1+t3-t2+t6;
    printf("MATRIX SOLUTION IS:\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
}