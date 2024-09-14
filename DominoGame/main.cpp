#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
using namespace std;
struct domino {
    //build struct from type domino
    int left;
    int right;
};
int j = 0;
bool LetsPlayDomino(vector <domino>& v1, vector <domino>& v2, vector <int>v3) {
    if (v2.size() == v1.size()) {
        //base case to stop recrsuion
        for (int i = 0; i < v2.size(); ++i) {
            //printing chain if true
            cout << v2[i].left << "|" << v2[i].right;
            if (i != v2.size() - 1) {
                cout << "-";
            }
        }
        return true;
    }
    bool answer = false;
    for (int i = 0; i < v1.size(); ++i) {
        if (v3[i] == 1) {
            //if domino isused dont take it again 
            continue;
        }
        else {
            if (v2.empty()) {
                //if empty push value appeared at i
                v2.push_back(v1[i]);
                v3[i] = 1;//label that it is taken
                answer = answer; 
                LetsPlayDomino(v1, v2, v3);//call function
                v2.pop_back();//if return false will pop and return one step back
                v3[i] = 0;//unlabel that is taken
            }
            else if (v2.back().right == v1[i].left) {
                v2.push_back(v1[i]);//if right of domino equal left push it
                v3[i] = 1;//label it as taken
                answer = answer;
                LetsPlayDomino(v1, v2, v3);//call function
                v2.pop_back();//if it doesnt work delete last added elemnt
                v3[i] = 0;//unlabel
            }
        }
    }
    return answer;

}
int main() {
    int n, a, b;
    cin >> n;//number of dominos
    vector <domino> v, v2;//make vector of domino type
    vector<int>v3(n, 0);//set no values are taken
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        v.push_back({ a , b });//push it in vector
    }
    if (!LetsPlayDomino(v, v2, v3)) {
        //call function
        cout << "there is no solution";//if false
    }
    return 0;
}
