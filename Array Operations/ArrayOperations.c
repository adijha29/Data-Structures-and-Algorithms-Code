#include <stdio.h>
#include <stdlib.h>


void displayArray(int *arr,int n){
    printf("\n");
    printf("Array : ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int* insertInArray(int *arr,int element,int idx,int n){
    int *temp = (int*)malloc(sizeof(int)*(n+1));
    for(int i=0;i<idx;i++){
        temp[i] = arr[i];
    }
    temp[idx] = element;
    for(int i=n;i>idx;i--){
        temp[i] = arr[i-1];
    }
    return temp;
}

int* deleteInArray(int *arr,int idx,int n){
    int *temp = (int*)malloc(sizeof(int)*(n-1));
    int i = 0;
    for(int j=0;j<n;j++){
        if(j!=idx){
            temp[i] = arr[j];
            i++;
        }
    }
    return temp;
}

int searchInArray(int *arr,int n,int element){
    for(int i=0;i<n;i++){
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}


int main(){
    int n;
    printf("Enter Size of Array : ");
    scanf("%d",&n);
    int *arr = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        printf("Enter arr[%d] = ",i);
        scanf("%d",&arr[i]);
    }

    printf("\n\n");
    int operation = 0;
    while(operation!=6){
        printf("Choose any one operation from below : \n");
        printf("1. Display Array Elements\n");
        printf("2. Insert an element\n");
        printf("3. Delete an element\n");
        printf("4. Search in Array\n");
        printf("5. Update in Array\n");
        printf("6. Exit\n\n");

        printf("Operation : ");
        scanf("%d",&operation);
        printf("\n\n");

        if(operation==1){
            displayArray(arr,n);
            printf("\n\n");
        }
        else if(operation==2){
            int idx,element;
            printf("Enter Index for Insertion : ");
            scanf("%d",&idx);
            printf("Enter element to be Inserted : ");
            scanf("%d",&element);
            printf("\n\n");

            printf("Before Insertion : ");
            displayArray(arr,n);
            printf("\n\n");

            arr = insertInArray(arr,element,idx,n);
            n++;

            printf("After Insertion : ");
            displayArray(arr,n);
            printf("\n\n");
        }
        else if(operation==3){
            int idx;
            printf("Enter Index for Deletion : ");
            scanf("%d",&idx);
            printf("\n\n");

            printf("Before Deletion : ");
            displayArray(arr,n);
            printf("\n\n");

            arr = deleteInArray(arr,idx,n);
            n--;

            printf("After Deletion : ");
            displayArray(arr,n);
            printf("\n\n");
        }
        else if(operation==4){
            int element;
            printf("Enter element for Searching : ");
            scanf("%d",&element);

            int idx = searchInArray(arr,n,element);
            if(idx==-1){
                printf("OOPs!! No such elemet Exists!!\n\n");
            }else{
                printf("Element is present at %d index\n\n",idx);
            }
        }
        else if(operation==5){
            int idx,element;
            printf("Enter Index for Updation : ");
            scanf("%d",&idx);
            printf("Enter element to be Updation : ");
            scanf("%d",&element);
            printf("\n\n");

            printf("Before Updation : ");
            displayArray(arr,n);
            printf("\n\n");

            arr[idx] = element;

            printf("After Updation : ");
            displayArray(arr,n);
            printf("\n\n");
        }
    }
    return 0;
}