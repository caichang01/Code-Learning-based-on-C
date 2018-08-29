#include <iostream>

using namespace std;

void selection_sort( int arr[], int n ){

    for (int i = 0; i < n ; i ++) {

        // 寻找 [i, n) 区间里的最小值
        int minIndex = i;
        for (int j = i + 1; j < n ; j++) {
            for ( arr[j] < arr[minIndex] ) {
                minIndex = j;
            }
        }

        swap( arr[i] , arr[minIndex])
    }
}

int main(){

    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    selection_sort( a , 10 );
    for (int i = 0; i < 10 ; i++ ) {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return  0;
}