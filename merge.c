#include<stdio.h>
#include<time.h>

void merge(int a[], int beg, int mid, int end){
    int i,j,k;
    int n1 =mid-beg+1;
    int n2 = end-mid;

    int leftarr[n1];
    int rightarr[n2];

    for(i=0;i<n1;i++){
        leftarr[i] = a[beg+i];
    }
    for(j=0;j<n2;j++){
        rightarr[j] = a[mid+1+j];
    }
    i=0; j=0;k=beg;

    while(i<n1 && j<n2){
        if(leftarr[i]<=rightarr[j]){
            a[k] = leftarr[i];
            i++;
        }
        else{
            a[k] = rightarr[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        a[k] = leftarr[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k] = rightarr[j];
        j++;
        k++;
    }

}

void mergesort(int a[], int beg, int end){
    if(beg<end){
        int mid = (beg+end)/2;
        mergesort(a, beg, mid);
        mergesort(a, mid+1, end);
        merge(a, beg, mid, end);
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
    mergesort(a, 0, num-1);
    et = clock();

    printf("After sorting: \n");
    for(i=0;i<num;i++){
        printf("a[%d] = \t %d \n",i, a[i]);
    }

    printf("Time taken: %f\n", (double)(et-st)/CLOCKS_PER_SEC);
    return 0;
}