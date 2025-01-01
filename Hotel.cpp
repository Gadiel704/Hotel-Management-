#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Room {
    int number;
    string type;
    bool isOccupied;
    string guestName;
};
class HotelManagement {
private:
    vector<Room> rooms;