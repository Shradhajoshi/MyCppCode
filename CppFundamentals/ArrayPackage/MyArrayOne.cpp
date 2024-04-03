#include <iostream>
/* Search, Insert, and Delete in an Unsorted Array | Array Operations */
using namespace std;

int linearSearch(int arr[], int n, int key){
    for(int i = 0; i < n; i++){
        if(arr[i] == key)
        return i;
    }
    return -1;
}

int insertElementAtEnd(int arr[], int n, int key, int capacity){
    if(n >= capacity)
        return n;
    
    arr[n] = key;

    return (n + 1);
}

void insertElementAtPosition(int arr[], int n, int key, int capacity, int pos){
    if(n >= capacity || pos < 0 || pos > n)
        return;
    
    for(int i = n - 1; i >= pos; i--) {
        arr[i+1] = arr[i];
    }

    arr[pos] = key;
    n++;
}

int deleteElementAtPosition(int arr[], int n, int key){
    int pos = linearSearch(arr,n,key);
    if(pos == -1){
        cout << "Element not found" << endl;
        return n;
    }
    int i;
    for (i = pos; i < n - 1; i++) {
        arr[i] = arr[i+1];
    }

    return n - 1;
}
int main(){
    int myArr[10];
    myArr[0] = 3;
    myArr[1] = 6;
    myArr[2] = 8;
    myArr[3] = 1;
    myArr[4] = 4;
    myArr[5] = 5;
    myArr[6] = 2;

    int size = sizeof(myArr)/sizeof(myArr[0]);
    int found = linearSearch(myArr, size, 5);
    if(found >= 0){
        cout << "Element found at index: " << found << endl;
    } else {
        cout << "Element not found." << endl;
    }

    int newSize = insertElementAtEnd(myArr, 7, 9, 10);
    for(int i = 0; i < newSize; i++){
        cout << myArr[i] << " ";
    }
    cout << endl;

    insertElementAtPosition(myArr,newSize, 10, 10, 5);
    for(int i = 0; i < newSize + 1; i++){
        cout << myArr[i] << " ";
    }
    cout << endl;
    int currentSize = deleteElementAtPosition(myArr,newSize+1,10);
    for(int i = 0; i < currentSize; i++){
        cout << myArr[i] << " ";
    }
    cout << endl;
    return 0;
}