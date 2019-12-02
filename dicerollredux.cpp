#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    // TODO (1): Initialize random number generator with correct SEED
    srand(1701);
    // TODO (2): Declare variables
    int n = 0; // number of dice thrown
    char d = 'd'; // dice
    int s = 0; // sides of dice
    // TODO (3): Prompt user for designation, and read input
    cout << "Choose 1, 2, or 3 dice (6-, 10-, 12-, or 20-sided)" << endl;
    cout << "Enter designation (e.g. '2d6'): ";
    cin >> n >> d >> s;

    int f1 = rand() % s + 1;
    int f2 = rand() % s + 1;
    int f3 = rand() % s + 1;
    int s1 = rand() % s + 1;
    int s2 = rand() % s + 1;
    int s3 = rand() % s + 1;
    int t1 = rand() % s + 1;
    int t2 = rand() % s + 1;
    int t3 = rand() % s + 1;
    // TODO (4): Validate input
    if (n != 1 && n != 2 && n != 3 || d != 'd' || s != 6 && s != 10 && s != 12 && s != 20){
    // TODO (5): If NOT valid ... output error message
        cout << "Not a valid designation" << endl;
    }
    // ... else ...
    else if (n == 1){
    // TODO (6) Generate and print the result of roll one
        cout << n << d << s << " result: " << f1 << endl;
    // TODO (7) Generate and print the result of roll two
        cout << n << d << s << " result: " << f2 << endl;
    // TODO (8) Generate and print the result of roll three
        cout << n << d << s << " result: " << f3 << endl;
    }
    else if (n == 2){
        cout << n << d << s << " result: " << f1 << " + "  << f2 << " = " << f1 + f2 << endl;

        cout << n << d << s << " result: " << f3 << " + "  << s1 << " = " << f3 + s1 << endl;

        cout << n << d << s << " result: " << s2 << " + "  << s3 << " = " << s2 + s3 << endl;
    }
    else if (n == 3){
        cout << n << d << s << " result: " << f1 << " + "  << f2 << " + " << f3 << " = " << f1 + f2 + f3 << endl;

        cout << n << d << s << " result: " << s1 << " + "  << s2 << " + " << s3 << " = " << s1 + s2 + s3 << endl;

        cout << n << d << s << " result: " << t1 << " + "  << t2 << " + " << t3 << " = " << t1 + t2 + t3 << endl;
    }

    return 0;
}
