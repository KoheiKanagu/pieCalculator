#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int hoge(int);
double convertTime(void);


int main(void){
    int n, count;
    double start, finish;
    
    printf("何点打点するかを入力:");
    scanf("%d",&n);
    
    start = convertTime();
    count = hoge(n);
    double ans = (count/(double)n)*4;
    finish = convertTime();

    printf("%f\n",ans);
    
    printf("%d回 : 計算時間%f\n", count, finish-start);
    
    return 0;
}


int hoge(int n)
{
    int i, random, k=0;
    double x,y;

    srand((unsigned)time(NULL));
    
    for(i=0;i<n;i++){
        random=rand();
        x=rand()/(RAND_MAX+1.0);
        y=rand()/(RAND_MAX+1.0);
        if((x*x+y*y)<1.0){
            k+=1;
        }
//        printf("%d:random=%d\n",i+1,random);
    }
    return k;
}


double convertTime(void){
    struct timeval time;
    gettimeofday(&time, NULL);
    
    return ((double) time.tv_sec + (double) time.tv_usec * 0.001 * 0.001);
}