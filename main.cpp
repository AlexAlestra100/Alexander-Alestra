#include <iostream>
#include <sstream>
#include <cmath>
#include <fstream>
using namespace std;

const string TXT = ".txt";
// main() function:
int main(){
    string fileName;
    ifstream inFS;
    ofstream outE;
    ofstream outO;
    string eFile, oFile, file;
    int oWord = 0;
    int eWord = 0;
    int tWords = 0;
    cout << "Enter the name of the input file: " << endl;
    cin >> fileName;

    while (fileName.find(".txt") == string::npos){
        cout << "Only filenames ending in '.txt' are accepted!" << endl;
        cout << "Enter the name of the input file: " << endl;
        cin >> fileName;
    }
    inFS.open(fileName);
    if (!inFS.is_open()){
        cout << "Failed to open file for read: " << fileName << endl;
        return 1;
    }
    eFile = fileName.substr(0, fileName.size() - 4) + "-even.txt";
    oFile = fileName.substr(0, fileName.size() - 4) + "-odd.txt";
    //           (check there were no errors, abort if failure)

    outE.open(eFile);
    outO.open(oFile);

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
    outE.close();
    outO.close();
    inFS.close();
    tWords = eWord + oWord;
    cout << tWords << " words read in from " << fileName << endl;
    cout << eWord <<  " words written to " << eFile << endl;
    cout << oWord <<  " words written to " << oFile << endl;

    return 0;

}
