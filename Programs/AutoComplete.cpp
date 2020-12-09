#include <iostream>
#include <fstream>
using namespace std;

const int MAX_SIZE = 4000000;
const string FILE_NAME = "GoogleWords.txt";
string a[MAX_SIZE];

void insertionSort(string a[], int size);
int binarySearch(string a[], string key, int size);
int readDictionary(string a[], string fileName);
void writeDictionary(string a[], int size, string fileName);
int updateDictionary(string a[], int size, string s, string fileName);
void outputMatches(string a[], int size, string s);

int main()
{
    int size = readDictionary(a, FILE_NAME);
    string input;
    cout << "Type one word.  \"q\" to quit." << endl;
    cout << "> ";
    cin >> input;
    while(input != "q")
    {
        outputMatches(a, size, input);
        size = updateDictionary(a, size, input, FILE_NAME);
        cout << "> ";
        cin >> input;
    }
    return 0;
}

int binarySearch(string a[], string key, int size){
    int mid = 0;
    int low = 0;
    int high = 0;

    high = size - 1;

    while (high >= low) {
        mid = (high + low) / 2;
        if (a[mid] < key) {
         low = mid + 1;
    }
      else if (a[mid] > key) {
         high = mid - 1;
      }
      else {
         return mid;
      }
   }

   return -1; // not found
}


void insertionSort(string a[], int size){
    int i = 0;
    int j = 0;
    string temp;  // Temporary variable for swap

    for (i = 1; i < size; ++i) {
        j = i;
      // Insert numbers[i] into sorted part
      // stopping once numbers[i] in correct position
        while (j > 0 && a[j] < a[j - 1]) {

         // Swap numbers[j] and numbers[j - 1]
            temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            --j;
        }
    }
}


int readDictionary(string a[], string fileName){
    int sum;
    string word;
    ifstream inFS;
    inFS.open(fileName);
    while (inFS >> word){
        a[sum++] = word;
    }
    inFS.close();
    return sum;
}
/*
- Open an ifstream using fileName
- Read one word at a time, separated by \n, into a
- return the number of words read.  This will be used for size throughout the rest of the code.
*/

void writeDictionary(string a[], int size, string fileName){
    ofstream outFS;
    outFS.open(fileName);
    for (int i = 0; i < size; i++){
        outFS << a[i] << endl;
    }
    outFS.close();
}
/*
- Open an ofstream using fileName
    - Use its default behavior of deleting the existing file, we will write a new one.
- Write each element of a to the file.
*/

int updateDictionary(string a[], int size, string s, string fileName){
    ///binarySearch(a, s, size);
    if (binarySearch(a, s, size) == -1){
        a[size] = s;
        size++;
        insertionSort(a, size);
        writeDictionary(a, size, fileName);
    }
    return size;
}
/*
- Use binarySearch to search a for s.
- If s is NOT found at a valid index:
    - assign s to the end of the array.
        - The index of the end of the array is size.  eg if size is 5, the new element should be written to index 5.
    - increment size
    - Sort a using insertionSort
    - Write a to the file using writeDictionary
*/

void outputMatches(string a[], int size, string s){
    for (int i = 0; i < size; i++){
        if (a[i].find(s) == 0){
            cout << a[i] << endl;
        }
    }
}
/*
- loop through each element of a
    - call .find on each element, searching for s
    - If the element begins with s, ie the index returned from .find is 0, then print the element
*/
