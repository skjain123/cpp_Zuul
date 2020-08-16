#include <vector>

using namespace std;

class Room {
public:
  string name;
  vector<item> roomItems;
  vector<string> directions;
  vector<int> exits;
  int iIndex = 0;

  string getName() {
    return name;
  }

  int getExits(string dir) {
    int x = -1;

    if ((x >= 0)) {
      return x;
    } else {
      return -1;
    }
  }

  void setExit(string dir, int r) {
  	if (r != -1) {
  		transform(dir.begin(), dir.end(), dir.begin(), ::toupper);
   		directions.push_back(dir);
    	exits.push_back(r);
	}
  }

  void addItem(string itemName) {
    roomItems.push_back(item());
    roomItems.at(roomItems.size() - 1).setName(itemName);
  }

  void removeItem(string itemName) {
    if (roomItems.size() == 0) {
      cout << "No Items in room!";
    }

    for (int index = 0; index < roomItems.size(); index++) {
      if (roomItems.at(index).name == itemName) {
	       roomItems.erase(roomItems.begin() + index - 1);
         iIndex--;
      }
    }
  }

  void printItem() {
    if (roomItems.size() == 0) {
      cout << "No Items in room!" << endl;
    }
    
    for (int index = 0; index < roomItems.size(); index++) {
      cout << roomItems.at(index).getName();
    }
  }
};
Room nullRoom;
Room currentRoom;
vector<Room> rooms;

void printRoomDesc() {
  cout << "You are now in " << currentRoom.getName() << endl;
  
  if (currentRoom.exits.size() != 0) {
    cout << "Your Exits are: ";
    for (int i = 0; i < currentRoom.directions.size(); i++) {
      cout << currentRoom.directions.at(i) << "   ";
    }
    cout << endl;
  } else {
    cout << "No Exits!" << endl;
  }

  if (currentRoom.roomItems.size() != 0) {
    cout << "Items in room: ";
    for (int i = 0; i < currentRoom.roomItems.size(); i++) {
      cout << currentRoom.roomItems.at(i).getName() << "   ";
    }
    cout << endl;
  } else {
    cout << "No Items!" << endl;
  }
}

void createRooms() {
  string roomNames[15] = {
    "Stairs", "Library", "Bathroom 1", "Downstairs Hall", "Office", "Kitchen", "Eating Table",
     "Living Room", "Upstairs Hall", "Toy Room", "Guest Room", "Bathroom 2", "Your Room",
     "Sibling Room", "Parent Room"  
  };

  for (int i = 0; i < 15; ++i) {
    rooms.push_back(Room());
    rooms.at(i).name = (roomNames[i]);
  }

  rooms.at(7).addItem("Pencil");
  rooms.at(12).addItem("Computer");
  rooms.at(1).addItem("Book");
  rooms.at(5).addItem("Knife");
  rooms.at(4).addItem("Monitor");
}

void createExits() {
  string exitNames[4] {"north", "east", "south", "west"};
  int roomExitPairs[15][4] = {
    {-1,1,3,8}, {-1,-1,4,0}, {-1,3,-1,-1}, {0,4,7,2}, {1,-1,-1,3},
    {-1,7,-1,6}, {-1,5,-1,-1}, {3,-1,-1,5}, {-1,-1,-1,-1}, {-1,8,-1,-1},
    {-1,8,-1,-1}, {-1,-1,-1,8}, {-1,8,-1,-1}, {-1,8,-1,-1}, {-1,-1,-1,8}
  };

  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 4; j++) {
      rooms.at(i).setExit(exitNames[j], roomExitPairs[i][j]);
    }
  }

  //set upstairs hallway exits:
  rooms.at(8).setExit("Toy Room", 9);
  rooms.at(8).setExit("Stairs", 0);
  rooms.at(8).setExit("Guest Room", 10);
  rooms.at(8).setExit("Bathroom 2", 11);
  rooms.at(8).setExit("Your Room", 12);
  rooms.at(8).setExit("Sibling Room", 13);
  rooms.at(8).setExit("Parent Room", 14);
}