#include<stdio.h>
#include<time.h>

int main(){
    int a[100000],i;
    int j, temp, num;
    clock_t st,et;

    printf("Enter n: \n");
    scanf("%d", &num);

    for(i=0;i<num;i++){
        a[i] = rand()%10000;
    }

    printf("Before sorting: \n");
    for(i=0;i<num;i++){
        printf("a[%d] = \t %d \n",i, a[i]);
    }

    st = clock();
    for(i=0;i<num-1;i++){
        for(j=i+1;j<num;j++){
            if(a[i]>a[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    et = clock();

    printf("After sorting: \n");
    for(i=0;i<num;i++){
        printf("a[%d] = \t %d \n",i, a[i]);
    }

    printf("Time taken: %f\n", (double)(et-st)/CLOCKS_PER_SEC);
    return 0;
}