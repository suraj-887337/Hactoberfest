#include<iostream>
using namespace std;
int partitionArray(int input[], int start, int end){
    int pivot = input[start];
    int count=0;
    for(int i=start+1; i<=end; i++){
        if(input[i] <= pivot){
            count++;
        }
    }
    int pivotIndex= start+count;
    int temp = input[start];
    input[start]=input[pivotIndex];
    input[pivotIndex]=temp;
    int i=start, j=end;
    while(i<= pivotIndex && j>=pivotIndex)
    {
    while(input[i]<=pivot){
        i++;
    }
    while(input[j] > pivot){
        j--;
    }
    if(i<pivotIndex && j>pivotIndex){
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
        i++;
        j--;
    }
}
return pivotIndex;
}
void quicksSort(int input[], int start, int end){
    if(start >= end){
        return;
    }

int pivotIndex = partitionArray(input, start, end);
    quicksSort(input, start, pivotIndex-1);
    quicksSort(input, pivotIndex+1, end);
    
}
void quickSort(int input[], int n){
    quicksSort(input, 0, n-1);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


