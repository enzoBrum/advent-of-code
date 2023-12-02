#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<unordered_set>
#include<algorithm>
#include<cstring>
#include<sstream>

using namespace std;

int main() {
  unordered_map<string, int> mp = {
    {"red", 12},
    {"green", 13},
    {"blue", 14},
  };

  string line;
  int ans = 0;
  while (getline(cin, line)) {
    stringstream ss;
    ss << line;

    ss.ignore(1024, ' ');
    int id;
    ss >> id;
    ss.ignore(1024, ':');
    string round;
    bool success = true;
    int red = 0, green = 0, blue = 0;
    while (getline(ss, round, ';')) {
      stringstream ss2;
      ss2 << round;

      int num;
      string col;

      while (ss2 >> num >> col) {
        if (col.back() == ',')
          col.pop_back();
        if (col == "red")
          red = max(red, num);
        else if (col == "green")
          green = max(green, num);
        else
          blue = max(blue, num);
      }

    }
    
    ans += (red*green*blue);
  }

  cout << ans << '\n';
}
