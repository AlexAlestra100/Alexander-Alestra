#include <iostream>
#include <string>
using namespace std;


const string BFF = "BFF";
const string IDK = "IDK";
const string JK = "JK";
const string TMI = "TMI";
const string TTYL = "TTYL";

const string BFF_LONG = "best friend forever";
const string IDK_LONG = "I don't know";
const string JK_LONG = "just kidding";
const string TMI_LONG = "too much information";
const string TTYL_LONG = " talk to you later";

const size_t NUM_STRINGS = 5;
const string abbreviations[NUM_STRINGS] = {BFF, IDK, JK, TMI, TTYL};
const string longs[NUM_STRINGS] = {BFF_LONG, IDK_LONG, JK_LONG, TMI_LONG, TTYL_LONG};

int main()
{
    string userInput;
    cout << "Enter Text:" << endl;
    getline(cin, userInput);
    for (size_t i = 0; i < userInput.size(); i++){
        if (userInput.at(i) == '.'){
            ///userInput.replace(run, 1, "!");
            userInput.at(i) = '!';
        }
    }
   
   for(size_t i = 0; i < NUM_STRINGS; i++)
   {
       size_t findIndex = userInput.find(abbreviations[i]);
       ///find abbreviations[i], store its result in findIndex
       while (findIndex != string::npos){
            userInput.replace(findIndex, abbreviations[i].size(), longs[i]);
            findIndex = userInput.find(abbreviations[i], findIndex);
       }
       ///while findIndex is a valid index
       ///replace it with longs[i]
       ///repeat the find
   }

   cout << userInput << endl;
   return 0;
}
