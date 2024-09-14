#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int main() {
    map < pair <wstring, int >, wstring > mp;//to load file in map
    wifstream alt;//read arabic file
    alt.open("alternatives");//open alternatives file
    wstring line1;
    int i = 1, countline = 0;
    while (getline(alt, line1)) {//loop on every line
        wstringstream cn(line1);//break it into word
        wstring word1, word2;
        countline++;
        // cout<<cnt << ' ' << countline<<' ';
        while (cn >> word1, cn >> word2) {
            if (countline % 4 != 0) {
                mp[{word1, i}] = word2;//load first word with its replacement in map and alternative
                i++;
                break;
            }
            else {
                i = 1;
                mp[{word1, i}] = word2;
                ++i;
                break;
            }
            break;//stop this loop
        }
    }
    string filename;
    wifstream in;//opening read file
    cout << "enter filename you want to open :";
    cin >> filename;
    in.open(filename.c_str());
    wofstream out;//creating output file
    out.open("output.txt");
    wstring line;
    while (getline(in, line)) {
        wstringstream ss(line); // break line into words
        wstring word;
        while (ss >> word) {
            // loop on every word in input file
            for (auto i : mp) {
                //loopn on map to check is word found or not
                int m = word.find({ i.first.first });
                if (m != -1) {
                    //if found
                    int k;
                    cout << "Enter which alt ypu want to replace word with it (1,2,3):";
                    cin >> k;
                    word.replace(m, word.size(), mp[{i.first.first, k}]);
                    //change place found word with value loaded in map
                }
            }
            out << word << ' ';//print word in file
        }
        out << '\n';//to start a new line
    }
    in.close();//close both file to end operation
    out.close();
    return 0;
}
