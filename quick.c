#include<stdio.h>
#include<time.h>

int partition(int a[], int start, int end){
    int pivot = a[end];
    int i = start-1;
    
    for(int j=start;j<end;j++){
        if(a[j]<=pivot){
            i=i+1;
            int temp =a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i+1];
    a[i+1] = a[end];
    a[end] = temp;
    return i+1;
}

void quicksort(int a[], int start, int end){
    if(start<end){
        int p = partition(a, start, end);
        quicksort(a, start, p-1);
        quicksort(a, p+1, end);
    }
}

int main(){
    int a[100000],i;
    int j,num,temp;
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
    quicksort(a, 0, num-1);
    et = clock();

    printf("After sorting: \n");
    for(i=0;i<num;i++){
        printf("a[%d] = \t %d \n",i, a[i]);
    }

    printf("Time taken: %f\n", (double)(et-st)/CLOCKS_PER_SEC);
    return 0;
}