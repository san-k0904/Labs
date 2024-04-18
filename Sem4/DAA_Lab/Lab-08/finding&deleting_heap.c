#include <stdio.h>

void swap(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int Delete(int A[], int n){
    int x = A[0];  // Max element
    A[0] = A[n-1];
 
    int i = 0;
    int j = 2 * i + 1;
 
    while (j < n-1){
        // Compare left and right children
        if (A[j] < A[j+1]){
            j = j+1;
        }
 
        // Compare parent and largest child
        if (A[i] < A[j]){
            swap(A, i, j);
            i = j;
            j = 2 * i + 1;
        } else {
            break;
        }
    }
    return x;
}

void Heapify(int A[], int n){
    // # of leaf elements: (n+1)/2, index of last leaf element's parent = (n/2)-1
    for (int i=(n/2)-1; i>=0; i--){
 
        int j = 2 * i + 1;  // Left child for current i
 
        while(j < n-1){
            // Compare left and right children of current i
            if (A[j] < A[j+1]){
                j = j+1;
            }
 
            // Compare parent and largest child
            if (A[i] < A[j]){
                swap(A, i, j);
                i = j;
                j = 2 * i + 1;
            } else {
                break;
            }
        }
    }
}

void Print(int A[], int n, const char* s){
    printf("%s: [", s);
    for (int i=0; i<n; i++){
        printf("%d", A[i]);
        if (i < n-1){
            printf(", ");
        }
    }
    printf("]\n");
}

int findIndex(int A[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (A[i] == key) {
            return i;
        }
    }
    return -1; // Element not found
}

void deleteElementFromHeap(int A[], int* n, int key) {
    int index = findIndex(A, *n, key);
    if (index == -1) {
        printf("Element not found in heap.\n");
        return;
    }

    A[index] = A[*n - 1];
    (*n)--;
    Heapify(A, *n);
}

int main() {
    int A[] = {5, 10, 30, 20, 35, 40, 15};
    int n = sizeof(A) / sizeof(A[0]);
    Print(A, n, "Original Array");

    deleteElementFromHeap(A, &n, 30);
    Print(A, n, "Array after deleting 30 from heap");

    return 0;
}
