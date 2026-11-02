#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Swap function
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

// Deterministic Quick Sort
void deterministicQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);

        deterministicQuickSort(arr, low, p - 1);
        deterministicQuickSort(arr, p + 1, high);
    }
}

// Randomized Quick Sort
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {

        int randomIndex = low + rand() % (high - low + 1);

        // Swap random pivot with last element
        swap(arr[randomIndex], arr[high]);

        int p = partition(arr, low, high);

        randomizedQuickSort(arr, low, p - 1);
        randomizedQuickSort(arr, p + 1, high);
    }
}

// Display function
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr1[100], arr2[100];

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }

    srand(time(0));

    // Deterministic Quick Sort
    deterministicQuickSort(arr1, 0, n - 1);

    cout << "\nDeterministic Quick Sort: ";
    display(arr1, n);

    // Randomized Quick Sort
    randomizedQuickSort(arr2, 0, n - 1);

    cout << "Randomized Quick Sort: ";
    display(arr2, n);

    return 0;
}