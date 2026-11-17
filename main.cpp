#include <iostream>
#include <chrono>
#include <random>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;
static final int[] size_check = {100, 1000, 10000, 100000};
static long long startTime;
static long long endTime;
static vector<long long> runtime;
static vector<int> swapCheck;
static vector<int> comparisonCheck;
static int swaps = 0, comparisons = 0;

static void testSorts(int n);
static void quickSortInitializer(vector<int>& arr, int left, int right, key);
static vector<int> randDistArr(int n);
static vector<int> copyArr(const vector<int>& arr);
static vector<int> sorted(vector<int> arr);
static vector<int> reverseSorted(vector<int> arr);
static vector<int> almostSorted(vector<int> arr);

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
    vector<int> original(n) = randDistArr(n);
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
static void quickSortInitializer(vector<int>& arr, int left, int right, key) {
    startTime = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now().time_since_epoch()).count();
    //Check here to lead to correct quickSort implementation
    switch (key) {
        case 0:
            //quickSort first element pivot
            
            break;
        case 1:
            //quicksort last element pivot
            
            break;
        case 2:
            //quicksort median pivot
            
            break;
        case 3:
            //quicksort random pivot
            
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
