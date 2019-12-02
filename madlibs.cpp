#include <iostream>
#include <string>
using namespace std;

int main() {
    // Note that `#include <string>` is required for using the string type.

    // TODO (1): declare string variables here
    string location;
    string verb;
    string anotherVerb;
    string adjective;
    string adverb;
    string noun;
    string relative;

    // TODO (2): print game title here
    cout << "** MADLIBS **" << endl;

    // Ask user for input -- but not in the order of the story...
    // TODO (3): capture user input into the string variables here
    cout << "Enter a location (e.g. \"the living room\"): " << endl;
    getline(cin, location);

    cout << "Enter a verb (e.g. \"sing\"): " << endl;
    getline(cin, verb);

    cout << "Enter another verb: " << endl;
    getline(cin, anotherVerb);

    cout << "Enter an adjective (e.g. \"greedy\"): " << endl;
    getline(cin, adjective);

    cout << "Enter an adverb (e.g. \"noisily\"): " << endl;
    getline(cin, adverb);

    cout << "Enter a noun (e.g. \"peanut\"): " << endl;
    getline(cin, noun);

    cout << "Enter a relative (e.g. \"aunt\"): " << endl;
    getline(cin, relative);

    // Output a blank line
    // TODO (4): output a blank line here

    cout << endl;
    cout << endl;

    // Output the story
    //   My ADJECTIVE RELATIVE is convinced that if I VERB ADVERB,
    //   I will be able to VERB the NOUN in LOCATION.
    // TODO (5): output the story (as indicated above) here

    cout << "My " << adjective << " " << relative << "is convinced that if I " << verb << " " << adverb << "," << endl;
    cout << "I will be able to " << anotherVerb << " the " << noun << " in " << location << ".";

    return 0;
}
