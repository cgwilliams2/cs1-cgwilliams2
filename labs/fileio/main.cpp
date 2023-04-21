/*
    CS1 - File IO Lab

    Updated by: Colton Williams
    Date: 04/21/2023

    The program reads numbers from a file and finds statistical values from those numbers.
    Lab demonstrates the file io and vector application. 
    Statistical value's definitions for mean, median, mode, etc. can be found here: https://www.purplemath.com/modules/meanmode.htm
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const float EPSILON = 1e-4; //accuracy upto 4 decimal points

// function prototypes
void readData(vector<int> &, const string);
int findMax(const vector<int> &);
int findMin(const vector<int> &);
float findMean(const vector<int> &); // average
int findRange(const vector<int> &);
float findMedian(vector<int>);
// bonus implement findMode function
int findMode(const vector<int> &);

void writeData(const vector<int> & numbers);
void test();

int main(int argc, char* argv[]) {
    if (argc == 2 && string(argv[1]) == "test") {
        test();
        return 0;
    }
    vector<int> numbers;
    string inFile;
    cout << "Enter input file name: ";
    getline(cin, inFile);
    readData(numbers, inFile);
    writeData(numbers);
    cin.ignore();
    cout << "All done. Enter to exit...";
    cin.get();
    return 0;
}

void readData(vector<int> & numbers, const string inputFileName) {
    // FIXME1: Open inputFileName for reading data
    ifstream inputFile("input.txt");
    // read the data until eof marker and store each num into numbers vector
    int num;
    while (inputFile >> num) {
        numbers.push_back(num);
    }
}

void writeData(const vector<int> & numbers) {
    // FIXME2
    /*
    Algorithm steps:
    1. Prompt user to enter output file name
    2. Store and use the file name to open the file in write mode
    3. Write output as shown in output.txt file with proper formatting using iomanip
    */
   string fileOutName; 
   cout << "Enter an output file name: "; 
   cin >> fileOutName; 

   ofstream outputFile(fileOutName); 

   outputFile << "List of Numbers:";
   for(int n: numbers)
        outputFile << " " << n;
   outputFile << endl << endl; 

    outputFile << "========================================" << endl;
    outputFile << "          Statistical Results" << endl;
    outputFile << "========================================" << endl;
    outputFile << "Max     Min     Mean     Median    Range" << endl;
    outputFile << setw(4) << findMax(numbers) << "    ";
    outputFile << setw(4) << findMin(numbers) << "    ";
    outputFile << setw(4) << fixed << setprecision(2) << findMean(numbers) << "    ";
    outputFile << setw(4) << fixed << setprecision(2) << findMedian(numbers) << "    ";
    outputFile << setw(4) << findRange(numbers) << endl;
}





int findMax(const vector<int> & nums) {
    int max = nums[0];
    for(int n: nums)
        max = (n>max) ? n : max;
    return max;
}

int findMin(const vector<int> & nums) {
    // FIXME3 - implement function to find and return min value in nums vector
    int min = nums[0];
    for(int n: nums)
        min = (n<min) ? n : min;
    return min;
} 

float findMean(const vector<int> & nums) {
    // same as average
    long long int sum = 0;
    for(int n: nums)
        sum += n;
    return sum/float(nums.size());
}

int findRange(const vector<int> & nums) {
    // FIXME6 - implement function that finds and returns the range value
    // range = max - min
    int max = findMax(nums);
    int min = findMin(nums);
    return max - min;
}

float findMedian(vector<int> nums) {
    sort(nums.begin(), nums.end());
    float median;
    if (nums.size() % 2 == 0) {  // even set
        median = (nums[nums.size()/2] + nums[nums.size()/2-1])/float(2);
    } else { // odd set
        median = nums[nums.size()/2];
    }
    return median;
}

void test() {
    vector<int> numbers = {100, 10, 5, 0, -99, 10, 99};
    //cout << findMean(numbers) << " " << findMean(numbers)-17.857142 << endl;
    assert(fabs(findMean(numbers)-17.857142) <= EPSILON );
    assert(findMax(numbers) == 100);
    assert(findMedian(numbers) == 10);
    assert(findMin(numbers) == -99);
    assert(findRange(numbers) == 199);
    vector<int> numbers1 = {10, 10, 10, 0, -10, -10};
    assert(fabs(findMean(numbers1) -1.6667) <= EPSILON  );
    assert(findMax(numbers1) == 10);
    assert(findMedian(numbers1) == 5);
    assert(findMin(numbers1) == -10);
    assert(findRange(numbers1) == 20);
    // FIXME7: Write at least two test cases for other functions

    cerr << "all test cases passed!\n";
}