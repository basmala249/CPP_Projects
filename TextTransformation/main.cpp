#include <iostream>
#include <string>
using namespace std;
int main() {
    int m = 0, l = 0, k = 0, j = 0;
    char ch;
    string s;
    while (getline(cin, s)) {
        //loop for taking string with spaces
        if ((s[0] >= 65 and s[0] <= 90) or (s[0] >= 97 and s[0] <= 122)) {
            //check if first char is alphapt
            k = 0;
            for (int i = 0; i < s.size(); ++i) {
                if ((s[i] >= 65 and s[i] <= 90) or (s[i] >= 97 and s[i] <= 122) or s[i] == ',' or s[i] == '.' or isdigit(s[i])) {
                    //if char is number or alpha or comma or dot
                    ch = toupper(s[i]);//to capitalize first caracter
                    if (m == 0) {
                        // m means first character to make it capitilize
                        cout << ch;
                        l = 0;
                        m = 1;
                    }
                    else if (s[i] == '.') {
                        cout << s[i];
                        j = 1;  //to detect dot
                        break;
                    }
                    else if (s[i] == ',') {
                        cout << s[i]; //cout comma
                        cout << ' '; //make space between words 
                        m = 1;
                        l = 0;
                    }
                    else {
                        if (isdigit(s[i])) {
                            cout << s[i];
                        }
                        else {
                            ch = tolower(s[i]);
                            cout << ch;// any char not first char will be small
                            l = 0;
                        }
                    }
                    l = 0;
                    k = 0;
                }
                else {
                    if (l == 0 and s[i] == ' ') {
                        cout << ' '; // l for not repeating space if there is exist space
                        l = 1; // to not repeat space again
                    }
                    else if (s[i] != ' ') {
                        cout << s[i];
                    }
                }
            }
            if (j == 1) {
                break; //break after finding dot
            }
        }
        else if (k == 0) {
            // if text contain lots of new lines just compress it in one line
            cout << "\n\n";
            k = 1; // not to repeat it again
        }
    }
    return 0;
}
