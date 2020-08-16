using namespace std;

string input = "";
int roomIndex = 0;

void printCommands() {
  	cout << "Your Commands are: help, home, go, inventory, get, drop, what, and quit." << endl;
}

void what(string command) {
	if (command.empty() || command == "" || command == " ") {
		cout << "What command are you asking about?" << endl;
	} else {
		if (command == "HELP") {
			cout << "Displays all of the commands you can use and the current room's information. Usage: help.";
		} else if (command == "HOME") {
			cout << "Sends you to the starting room, the living room. Usage: home.";
		} else if (command == "GO") {
			cout << "Sends you to the room in the inputted direction. Usage: go (direction).";
		} else if (command == "INVENTORY") {
			cout << "Displays all of the items you are currently holding in your inventory. Usage: inventory.";
		} else if (command == "GET") {
			cout << "Picks item up from the current room and puts it in your inventory. Usage: get (Item Name).";
		} else if (command == "DROP") {
			cout << "Drops item from inventory and puts it in the current room. Usage: drop (Item Name).";
		} else if (command == "QUIT") {
			cout << "Exits the game. Usage: quit. Usage: exit. Usage: close.";
		} else if (command == "WHAT") {
			cout << "Displays information about the inputted command and how to use it. Usage: what (COMMAND).";
		} else {
			cout << "This is not a command!";
		}
		cout << " Also, nothing is case sensitive!" << endl;
	}
}

void help() {
	cout << "This is the Zuul Game!" << endl;
  	cout << "Wander around and find all 5 items!" << endl;
  	printCommands();
  	printRoomDesc();
}

void printInventory() {
	cout << inventory.size() << endl;

	if (inventory.size() == 0) {
		cout << "No Items in inventory!" << endl;
	} else {
		for (int i = 0; i < inventory.size(); i++) {
			cout << inventory.at(i).getName() << "\n";
		}
		cout << endl;
	}
}

void go(string command) {
	if (command.empty() || command == "" || command == " ") {
		cout << "Go Where?" << endl;
	} else {
		int x = -1;
		for (int i = 0; i < currentRoom.directions.size(); i++) {
			if (command == currentRoom.directions.at(i)) {
				x = currentRoom.exits.at(i);

			}
		}

		if (command == "HOME") {
			x = 7;
		}

		if (x != -1) {
			rooms.at(roomIndex) = currentRoom;
			roomIndex = x;
			currentRoom = rooms.at(x);
			printRoomDesc();
		} else {
			cout << "That is not a exit!" << endl;
		}
	}
}

void getItem(string command) {
	int itemIndex = -1;
	if (command.empty() || command == "" || command == " ") {
		cout << "Get What?" << endl;
	} else {
		for (int i = 0; i < currentRoom.roomItems.size(); i++) {
			if (command == currentRoom.roomItems.at(i).getName()) {
				itemIndex = i;
			}
		}

		if (itemIndex != -1) {
			inventory.push_back(item());
			inventory.at(inventory.size() - 1).name = command;
			currentRoom.roomItems.erase(currentRoom.roomItems.begin() + itemIndex);
			cout << "Got " << command << endl;
		} else {
			cout << "Item is not in this room!" << endl;
		}
	}
}

void dropItem(string command) {
	int itemIndex = -1;
	if (command.empty() || command == "" || command == " ") {
		cout << "Get What?" << endl;
	} else {
		if (inventory.size() != 0) {
			for (int i = 0; i < inventory.size(); i++) {
				if (command == inventory.at(i).getName()) {
					itemIndex = i;
				}
			}

			if (itemIndex != -1) {
				currentRoom.roomItems.push_back(item());
				currentRoom.roomItems.at(currentRoom.roomItems.size() - 1).name = command;
				inventory.erase(inventory.begin() + itemIndex);
				cout << "Dropped " << command << endl;
			} else {
				cout << "Item is not in this room!" << endl;
			}
		} else {
			cout << "Nothing to Drop!" << endl;
		}
	}
}