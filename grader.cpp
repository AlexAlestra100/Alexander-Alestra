// -----------------------------------------------------------------------
// grader.cpp
// -----------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;
// -----------------------------------------------------------------------
// global constants
const string INFILE_PREFIX = "rawgrades-";
const string OUTFILE_PREFIX = "grade-report-";
const string IN_FILE_EXT = ".csv";
const string OUT_FILE_EXT = ".txt";

const size_t LEN_PREFIX = INFILE_PREFIX.length();
const size_t LEN_F_EXT = 3;

///this will be used for extra space between fields in the output file
const string SPACER = "  ";

const double A_GRADE = 90.0;
const double B_GRADE = 80.0;
const double C_GRADE = 70.0;
const double D_GRADE = 60.0;
// anything below D_GRADE is an 'F'

// output field widths
const int FW_NAME = 24;
const int FW_SCORE = 4;
const int FW_LOW = 3;
const int FW_TOTAL = 5;
const int FW_AVG = 7;
const int FW_GRADE = 3;
const int FW_SCORE_X4 = FW_SCORE * 4;

// -----------------------------------------------------------------------
// function prototypes

// top-level functions
string getInputFilename();
string deriveOutputFilename(const string &inFname);
bool openFiles(const string &inName, const string &outName, ifstream &fin, ofstream &fout);
void processGradeFile(ifstream &fin, ofstream &fout);

// helper functions

bool validInputFilename(const string &fname);
void parseStudentRecord(const string &line, string &name, string &id, int &s1, int &s2, int &s3, int &s4);
int min(int a, int b);
int min(int a, int b, int c, int d);
char gradeFromScore(double score);
void processLine(ostream &out, const string &line);
void writeReportHeader(ofstream &out);


// -----------------------------------------------------------------------
// program entry point
int main() {
    // main() has been implemented for you; no need to change anything here
    ifstream fin;
    ofstream fout;

    string inFilename = getInputFilename();
    string outFilename = deriveOutputFilename(inFilename);

    if (!openFiles(inFilename, outFilename, fin, fout)) {
        return EXIT_FAILURE;
    }

    cout << "Processing " << inFilename << " ..." << endl;
    processGradeFile(fin, fout);
    cout << "Report written to " << outFilename << endl;

    fin.close();
    fout.close();

    return EXIT_SUCCESS;
}


// -----------------------------------------------------------------------
// helper function definitions

// Returns true if `fname` of the form "rawgrades-<className>.csv"
bool validInputFilename(const string &fname) {
    size_t nameLen = fname.length();

    if (fname.substr(0,10)== INFILE_PREFIX && fname.substr(fname.size() - 4, 4) == IN_FILE_EXT && nameLen > (INFILE_PREFIX.size() + IN_FILE_EXT.size())){
        return true;
    }
    else {
        return false;
    }

    // currently this assumes that all names are valid
    //  but this will fail the unit tests
    return true;
}


// Parses a record, placing the substrings into `name`, `id`, and `s1...s4`
void parseStudentRecord(const string &line, string &name, string &id, int &s1, int &s2, int &s3, int &s4) {

    istringstream iss (line);
    getline(iss, name , ',');
    getline(iss, id, ',');

    char c;

    iss >> s1 >> c >> s2 >> c >> s3 >> c >> s4;

    //placing the results into the appropriate reference variables
}

// Returns the smaller of the two values
int min(int a, int b) {

    int min;

    if (a < b){
        min = a;
    }
    else{
        min = b;
    }
    return min;
}

// Returns the smallest of all the values
int min(int a, int b, int c, int d) {
    // HINT: use min(int, int)
    return min(min(a , b), min(c, d));
}

// Returns a letter grade for the given score
char gradeFromScore(double score) {
    char grade = 'F';

    if (score >= A_GRADE){
        grade = 'A';
    }
    else if (score >= B_GRADE){
        grade = 'B';
    }
    else if (score >= C_GRADE){
        grade = 'C';
    }
    else if (score >= D_GRADE){
        grade = 'D';
    }
    else {
        grade = 'F';
    }

    return grade;
}

// Processes a line read from the raw-grades input file
void processLine(ostream &out, const string &line) {
    string studentName, studentId, scores;
    int score1, score2, score3, score4;
    int total, lowest;
    double average;
    char letterGrade;

    parseStudentRecord(line, studentName, studentId, score1, score2, score3, score4);

    lowest = min(min(score1, score2), min(score3, score4));

    total = (score1 + score2 + score3 + score4) - lowest;

    average = total / 3.0;

    letterGrade = gradeFromScore(average);

    out << setw(FW_NAME) << left << studentName << SPACER
    << setw(FW_SCORE) << right << score1
    << setw(FW_SCORE) << right << score2
    << setw(FW_SCORE) << right << score3
    << setw(FW_SCORE) << right << score4 << SPACER
    << "(" << setw(FW_LOW) <<right << lowest << ")" << SPACER
    << setw(FW_TOTAL) << right << total << SPACER
    << setw(FW_AVG) << right << average << SPACER
    << setw(FW_GRADE) << letterGrade << left
    << endl;

}

// Writes the report header to the given output stream
void writeReportHeader(ofstream &out) {
    // Lucky you! I've implemented this one for you. Don't change it! :)
    out << left;

    out << setw(FW_NAME) << "Name" << SPACER
        << setw(FW_SCORE_X4) << "Scores" << SPACER
        << "(" << setw(FW_LOW) << "Low" << ")" << SPACER
        << setw(FW_TOTAL) << "Total" << SPACER
        << setw(FW_AVG) << "Average" << SPACER
        << "Grade"
        << endl;

    out << setfill('-');

    out << setw(FW_NAME) << "" << SPACER
        << setw(FW_SCORE_X4) << "" << SPACER
        << "-" << setw(FW_LOW) << "" << "-" << SPACER
        << setw(FW_TOTAL) << "" << SPACER
        << setw(FW_AVG) << "" << SPACER
        << "-----"
        << endl;

    out << setfill(' ') << fixed << setprecision(2);
}


// -----------------------------------------------------------------------
// top-level function definitions

// Returns a validated input filename from the user
string getInputFilename() {
    string fname;

    while (validInputFilename(fname) == false){
        cout << "Enter input filename (rawgrades-<className>.csv): ";
        cin >> fname;
        cout << endl;
    }
    //until it matches the required form.
    return fname;
}

// Derives the output filename from the given input filename
string deriveOutputFilename(const string &inFname) {

    string oFileName;

    oFileName = inFname;
    oFileName.replace(0, 10, OUTFILE_PREFIX);
    oFileName.replace(oFileName.size() - 4, 4, OUT_FILE_EXT);

    return oFileName;
}

// Returns true only if both files opened without error
bool openFiles(const string &inName, const string &outName, ifstream &fin, ofstream &fout) {

    fin.open(inName);
    fout.open(outName);

    if (!(fin.is_open())){
        cout << "Failed to open for read: " << inName << endl;

        return false;
    }
    else if (!(fout.is_open())){
        cout << "Failed to open for write: " << outName << endl;

        return false;
    }
    else {
        ifstream fin(inName);
        ofstream fout(outName);

        return true;
    }
}

// Read input records, process, write formatted output records
void processGradeFile(ifstream &fin, ofstream &fout) {
    // This function, too, has been implemented for you... nothing to do here
    string rawLine;

    writeReportHeader(fout);
    while (getline(fin, rawLine)) {
        processLine(fout, rawLine);
    }
}

// -----------------------------------------------------------------------
