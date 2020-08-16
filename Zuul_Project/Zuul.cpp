#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <locale>
#include <sstream>
#include <string>
#include "ItemClass.cpp"
#include "RoomClass.cpp"
#include "CommandFunctions.cpp"
#include "Parser.cpp"

using namespace std;

bool endGame = false;

int main() {
  createRooms();
  createExits();
  cout << inventory.size() << endl;
  currentRoom = rooms.at(7);
  roomIndex = 7;

  help();

  while (!endGame) {
    if ((inventory.size() >= 5)) {
      endGame = false;
      cout << "You Won!\nThank you for playing my game!" << endl;
      exit(0);
    }

    endGame = processCommand();
  }
  
  return 0;
}
