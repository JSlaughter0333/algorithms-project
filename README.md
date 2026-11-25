# Quick Sort: A Comparative Study of Pivoting Strategies

CSCE 4110 (Algorithms) – Group 8

## Team Members

- Sushil Gautam
- Damian Mercado
- John Slaughter

## Project Summary

Quick Sort picks one number (the pivot) and splits the list around it.
The pivot you pick changes how fast the sort is.

This project writes Quick Sort in C++ with 4 pivot choices:
First, Last, Median-of-3, and Random.

It tests them on 4 kinds of data (Random, Nearly sorted, Reverse sorted,
Sorted) and 4 sizes (100, 1,000, 10,000, 100,000).

For each test it counts comparisons and swaps, measures the runtime, and
checks that the result is sorted. Everything is saved to `results.csv`.

## Dependencies

- A C++ compiler that supports C++17 (for example, g++)
- Github

No other libraries are needed.

## Installation / Setup

1. Download the project from GitHub and open its folder in a terminal.
2. Check that g++ is installed:

g++ --version

3. Compile the program:

g++ -std=c++17 -O2 -o quicksort *.cpp

## Execution Instructions

Run the program:
./quicksort

The program saves the results to `results.csv`.

## Example 

Example rows from `results.csv`:

Size,Dataset,Pivot,Runtime_ns,Swaps,Comparisons
1000,Random,First,187042,7290,11120
1000,Sorted,Last,4388334,501498,499500
1000,Sorted,Median-of-3,68083,5079,9681
.......

Columns: data size, data type, pivot type, time in nanoseconds,
number of swaps, number of comparisons.
