
class Game {
  Game() {};
  ~Game() {};

  void listInventory() {
    for (vector<item>::iterator it = invnetory.begin(); it != inventory.end(); ++it) {
      cout << (it)->name << std::endl;
    }
  }

  void listExits() {
    if (currentRoom->north != nullptr)
      std::cout << "NORTH";

    if (currentRoom->east != nullptr)
      std::cout << "EAST";
  }

  void pickupItem(char* name) {
    item* obj = currentRoom->deleteItem(name);
    if (!obj)
      cout << "invalid item " << std::endl;

    
  }
  
private:
  vector<rooms*> locations;
  vector<item*> inventory;
  room* currentRoom;
}
