#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
    const int R_SEED = 314159;
    srand(R_SEED);
    // TODO: (1) add more constants here as needed (optional)
    double d;

    cout << setprecision(2) << fixed;

    // TODO: (2) declare variables for user input
    // _____ choice
    char choice;
    // _____ x, y
    double x;
    double y;

    // TODO: (3a) configure RNG with R_SEED

    // TODO: (3b) configure `cout` to output doubles / floating points to 2 decimal places

    // TODO: (4) prompt the user with selection choices
    cout << "Select particle location by:" << endl;

    // TODO: (5) read in user choice
    cout << "[E] entering coordinates" << endl;
    cout << "[R] random generation" << endl;
    cin >> choice;


    // TODO: (6) use a switch statement to set x and y values
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

    // TODO: (7) if not an invalid choice...i


        cout << "Particle is at (" << x << "," << y << ")" << endl;
        d = sqrt(pow(x,2) + pow(y,2));
        // TODO: (10) declare/assign boolean `onWall` if particle close enough
        if (fabs(d - 10) < 0.001){

            cout << "On cell wall" << endl;
        }

        // TODO: (11) declare/assign boolean 'inside' if particle inside wall
        else if (d < 10){

            cout << "Inside cell wall" << endl;
        }

        // TODO: (12) use above flags to decide what to output as the result
        else if (d > 10){

            cout << "Outside cell wall" << endl;
        }

    // }

    return 0;
}
