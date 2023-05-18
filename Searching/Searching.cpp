#include <bits/stdc++.h>

using namespace std;

// Return True if element is Present
bool binarySearchRecursive(vector<int> &arr,int element,int l,int h){
    if(l>h){
        return -1;
    }
    int ans = -1;
    int mid = (l + h)/2;
    if(arr[mid] == element){
        return true;
    }
    else if(arr[mid]<element){
        return binarySearchRecursive(arr,element,mid+1,h);
    }
    else{
        return binarySearchRecursive(arr,element,l,mid-1);
    }
    return false;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,15,20,90,154};
    int n = arr.size();
    int element;
    cout << "Enter element : ";
    cin >> element;

    int low = 0, high = n - 1;
    int ansi = -1;
    while(low <= high) {
        int mid = (low + high)/2;
        
        if(arr[mid]==element){
            ansi = mid;
            break;
        }
        else if(arr[mid] < element){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    if(ansi==-1){
        cout << "Element Not Found!!" << endl;
    }
    else{
        cout << "Element Found at : " << ansi << endl;
    }

}