#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    // Note that `#include <cstdlib>` is required for using rand(), srand().
    srand(2019);    // *** do NOT change this seed ***
    // Note that in a production version of the program, something like
    //  `srand(time(0))` would be used to set an initial seed based on the
    //  system clock, thus "randomizing" the number sequence.

    // Declare variables
    int num = 2;
    int side = 0;

    // Prompt user for number of sides
    cout << "Number of sides (4, 6, 8, 10, 12, or 20): ";
    cin >> side;
    cout << side;

    int f1 = rand() % side + 1;
    int f2 = rand() % side + 1;
    int s1 = rand() % side + 1;
    int s2 = rand() % side + 1;
    int t1 = rand() % side + 1;
    int t2 = rand() % side + 1;

    // Generate and print the result of roll one\
    // Role one
    cout << "2d" << side << " result:" << f1 << " + " << f2 << " = " << f1 + f2 << endl;
    // Roll two
    cout << "2d" << side << " result:" << s1 << " + " << s2 << " = " << s1 + s2 << endl;
    // Generate and print the result of roll three
    // Roll three
    cout << "2d" << side << " result:" << t1 << " + " << t2 << " = " << t1 + t2 << endl;

    return 0;
}
