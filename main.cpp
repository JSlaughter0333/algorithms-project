#include <iostream>
#include <chrono>
#include <random>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> size_check = {100, 1000, 10000, 100000};
long long startTime;
long long endTime;
vector<long long> runtime;
vector<int> swapCheck;
vector<int> comparisonCheck;
int swaps = 0, comparisons = 0;

static void testSorts(int n);
static void quickSortInitializer(vector<int>& arr, int left, int right, int key);
static vector<int> randDistArr(int n);
static vector<int> copyArr(const vector<int>& arr);
static vector<int> sorted(vector<int> arr);
static vector<int> reverseSorted(vector<int> arr);
static vector<int> almostSorted(vector<int> arr);

static int choosePivotIndex(vector<int>& arr, int left, int right, int key) {
    switch (key) {
        case 0:
            return left;                                   // first element pivot
        case 1:
            return right;                                  // last element pivot
        case 2: {    
            int mid = left + (right - left) / 2;           // median pivot
            int a = arr[left], b = arr[mid], c = arr[right];
            comparisons += 3;                              // comparisons counts
            if ((a <= b && b <= c) || (c <= b && b <= a)) return mid;
            if ((b <= a && a <= c) || (c <= a && a <= b)) return left;
            return right;
        }
        case 3:
            return left + rand() % (right - left + 1);     // random element pivot
        default:
            return right;
    }
}

static int partitionArr(vector<int>& arr, int left, int right, int key) {
    int p = choosePivotIndex(arr, left, right, key);
    swap(arr[p], arr[right]);                              // move chosen pivot to the end
    swaps++;
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        comparisons++;                                     // compare arr[j] with the pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }
    swap(arr[i + 1], arr[right]);                          // put pivot in its final position
    swaps++;
    return i + 1;
}

static void quickSort(vector<int>& arr, int left, int right, int key) {
    while (left < right) {
        int p = partitionArr(arr, left, right, key);
        if (p - left < right - p) {
            quickSort(arr, left, p - 1, key);
            left = p + 1;
        } else {
            quickSort(arr, p + 1, right, key);
            right = p - 1;
        }
    }
}

int main() {
  //time call to seed for random number calls
  srand(time(0));


  //for loop for the test runs
  for (int i = 0; i < size_check.size(); i++) {
    testSorts(size_check[i]);
  }

  //Displaying data goes here
  
}

//16 tests per each size option
static void testSorts(int n) {
    vector<int> original = randDistArr(n);
    vector<int> almost = almostSorted(original);
    vector<int> reverse = reverseSorted(original);
    vector<int> sorteded = sorted(original);
    vector<int> carrier;
    
    for (int i = 0; i < 4; i++) {
        carrier = original;
        quickSortInitializer(carrier, 0, carrier.size() - 1, i);
        runtime.push_back(endTime - startTime);
        swapCheck.push_back(swaps);
        comparisonCheck.push_back(comparisons);
        swaps = 0;
        comparisons = 0;
    }
    
    for (int i = 0; i < 4; i++) {
        carrier = almost;
        quickSortInitializer(carrier, 0, carrier.size() - 1, i);
        runtime.push_back(endTime - startTime);
        swapCheck.push_back(swaps);
        comparisonCheck.push_back(comparisons);
        swaps = 0;
        comparisons = 0;
    }
    
    for (int i = 0; i < 4; i++) {
        carrier = reverse;
        quickSortInitializer(carrier, 0, carrier.size() - 1, i);
        runtime.push_back(endTime - startTime);
        swapCheck.push_back(swaps);
        comparisonCheck.push_back(comparisons);
        swaps = 0;
        comparisons = 0;
    }
    
        for (int i = 0; i < 4; i++) {
        carrier = sorteded;
        quickSortInitializer(carrier, 0, carrier.size() - 1, i);
        runtime.push_back(endTime - startTime);
        swapCheck.push_back(swaps);
        comparisonCheck.push_back(comparisons);
        swaps = 0;
        comparisons = 0;
    }
    
}

//initializer function with the job of checking how long each run takes in nanoseconds and directs to the correct method
static void quickSortInitializer(vector<int>& arr, int left, int right, int key) {
    startTime = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now().time_since_epoch()).count();
    //Check here to lead to correct quickSort implementation
    switch (key) {
        case 0:
            //quickSort first element pivot
            quickSort(arr, left, right, 0); 
            break;
        case 1:
            //quicksort last element pivot
            quickSort(arr, left, right, 1);
            break;
        case 2:
            //quicksort median pivot
             quickSort(arr, left, right, 2);
            break;
        case 3:
            //quicksort random pivot
            quickSort(arr, left, right, 3);
            break;
        default:
            //incorrect key
            break;
    }
    
    endTime = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now().time_since_epoch()).count();
}

static vector<int> randDistArr(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % (5 * n));
    }
    return arr;
}

static vector<int> copyArr(const vector<int>& arr) {
    return arr;
}

static vector<int> sorted(vector<int> arr) {
    sort(arr.begin(), arr.end());
    return arr;
}

static vector<int> reverseSorted(vector<int> arr) {
    sort(arr.begin(), arr.end(), greater<int>());
    return arr;
}

static vector<int> almostSorted(vector<int> arr) {
    sort(arr.begin(), arr.end());
    if (arr.size() >= 2) {
        swap(arr[arr.size() - 2], arr[arr.size() - 1]);
    }
    
    return arr;
}
