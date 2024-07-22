#include<iostream>
using namespace std;

void selectionSort(int a[], int n) {

    int least, pos;
    int i, j;

    for(i=0; i < n; i++) {

        least = a[i];
        pos = i;

        for(j=i+1; j < n; j++) {

            if(a[j] < a[i]) {

                least = a[j];
                pos = j;
            }
        }

        int temp = a[i];
        a[i] = a[pos];
        a[pos] = temp;

    }

    for(i=0; i < n; i++) {
        cout<<a[i]<<" ";
    }
    

}

int main() {

    int a[20], i, n;

    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(i=0; i < n; i++) {
        cout<<"["<<i<<"]";
        cin>>a[i];
    }

    selectionSort(a, n);

}