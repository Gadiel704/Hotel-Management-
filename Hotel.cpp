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

    public:
    HotelManagement(int numRooms) {
        for (int i = 1; i <= numRooms; ++i) {
            rooms.push_back({i, (i % 2 == 0 ? "Double" : "Single"), false, ""});
        }
    }
    void bookRoom(const string& guestName, const string& roomType) {
        for (auto& room : rooms) {
            if (!room.isOccupied && room.type == roomType) {
                room.isOccupied = true;
                room.guestName = guestName;
                cout << "Room " << room.number << " booked for " << guestName << ".\n";
                return;
            }
        }
        cout << "No available " << roomType << " rooms.\n";
    }
        void checkOut(int roomNumber) {
        for (auto& room : rooms) {
            if (room.number == roomNumber) {
                if (room.isOccupied) {
                    room.isOccupied = false;
                    room.guestName = "";
                    cout << "Room " << roomNumber << " is now available.\n";
                    return;
                } else {
                    cout << "Room " << roomNumber << " is already vacant.\n";
                    return;
                }
            }
        }
        cout << "Invalid room number.\n";
    }

        void displayRooms() {
        cout << "\nRoom Status:\n";
        for (const auto& room : rooms) {