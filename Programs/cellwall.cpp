#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
    const int R_SEED = 314159;
    srand(R_SEED);
    double d;

    cout << setprecision(2) << fixed;

    // _____ choice
    char choice;
    // _____ x, y
    double x;
    double y;

    cout << "Select particle location by:" << endl;

    // TODO: (5) read in user choice
    cout << "[E] entering coordinates" << endl;
    cout << "[R] random generation" << endl;
    cin >> choice;


    switch (choice) {
        // 'E' or 'e' => prompt for, and read in, user values x and y
        case 'e':
        case 'E':
            cout << "Enter X-coordinate: " << endl;
            cin >> x;
            cout << "Enter Y-coordinate:" << endl;
            cin >> y;
        break;

        // 'R' or 'r' => set x and y to random values in the range {-12..12}
        // otherwise output invalid choice message
        case 'r':
        case 'R':
            x = (rand()%25) - 12;
            y = (rand()%25) - 12;
        break;

        default:
            cout << "Unknown option: " << choice << endl;
            return 1;
        break;

    }


        cout << "Particle is at (" << x << "," << y << ")" << endl;
        d = sqrt(pow(x,2) + pow(y,2));
        if (fabs(d - 10) < 0.001){

            cout << "On cell wall" << endl;
        }

        else if (d < 10){

            cout << "Inside cell wall" << endl;
        }

        else if (d > 10){

            cout << "Outside cell wall" << endl;
        }

    // }

    return 0;
}
