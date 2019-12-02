// TODO (1): includes and namespace declaration
#include <iostream>
#include <sstream>
#include <cmath>
#include <fstream>
using namespace std;

const string TXT = ".txt";
// main() function:
int main(){
    // TODO (2): declare local variables
    string fileName;
    ifstream inFS;
    ofstream outE;
    ofstream outO;
    string eFile, oFile, file;
    int oWord = 0;
    int eWord = 0;
    int tWords = 0;
    // TODO (3): acquire input filename (validated)
    cout << "Enter the name of the input file: " << endl;
    cin >> fileName;

    while (fileName.find(".txt") == string::npos){
        cout << "Only filenames ending in '.txt' are accepted!" << endl;
        cout << "Enter the name of the input file: " << endl;
        cin >> fileName;
    }
    // TODO (4): open input file (abort if failure)
    inFS.open(fileName);
    if (!inFS.is_open()){
        cout << "Failed to open file for read: " << fileName << endl;
        return 1;
    }
    // TODO (5): generate output file names and open output files
    eFile = fileName.substr(0, fileName.size() - 4) + "-even.txt";
    oFile = fileName.substr(0, fileName.size() - 4) + "-odd.txt";
    //           (check there were no errors, abort if failure)
    // TODO (6): initialize word counts

    outE.open(eFile);
    outO.open(oFile);

    // TODO (7): use a `while` loop to read in / test / output each word
    while (inFS >> file){
        if (file.size()%2 == 0){
            outE << file << endl;
            eWord += 1;
        }
        else{
            outO << file << endl;
            oWord += 1;
        }
    }
    // TODO (8): close all files
    outE.close();
    outO.close();
    inFS.close();
    // TODO (9): output summary
    tWords = eWord + oWord;
    cout << tWords << " words read in from " << fileName << endl;
    cout << eWord <<  " words written to " << eFile << endl;
    cout << oWord <<  " words written to " << oFile << endl;
    // (and what do we finish main() with?)


    return 0;

}
