#include <vector>

using namespace std;

class item {
public:
  string name;

  void setName(string newName) {
  	transform(newName.begin(), newName.end(), newName.begin(), ::toupper);
    name = newName;
  }

  string getName() {
    return name;
  }
};
vector<item> inventory;