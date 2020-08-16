string command1 = "";
string command2 = "";

void parse(string x) {
  string c1 = "";
  string c2 = "";

  int index = 0;

  for (int i = 0; i < x.size(); i++) {
    if (x.at(i) != ' ') {
      c1 += x.at(i);
    } else {
      break;
    }
    index++;
  }

  for (int i = index + 1; i < x.size(); i++) {
    if (i != x.size()) {
      c2 += x.at(i);
    } else {
      break;
    }
  }
  
  command1 = c1;
  command2 = c2;

  transform(command1.begin(), command1.end(), command1.begin(), ::toupper);
  transform(command2.begin(), command2.end(), command2.begin(), ::toupper);
}

bool processCommand() {
  string input;

  cout << "> ";
  getline(cin, input);
  parse(input);

  if (command1 == "HELP") {
    help();
  } else if (command1 == "GO") {
    go(command2);
  } else if (command1 == "QUIT" || command1 == "EXIT" || command1 == "CLOSE") {
    return true;
  } else if (command1 == "INVENTORY") {
    printInventory();
  } else if (command1 == "GET") {
    getItem(command2);
  } else if (command1 == "DROP") {
    dropItem(command2);
  } else if (command1 == "HOME") {
    go(command1);
  } else if (command1 == "WHAT") {
    what(command2);
  } else if (command1 == "NORTH") {
    go("NORTH");
  } else if (command1 == "EAST") {
    go("EAST");
  } else if (command1 == "SOUTH") {
    go("SOUTH");
  } else if (command1 == "WEST") {
    go("WEST");
  } else {
    cout << "I don't know what you mean! " << endl;
  }
  return false;
}