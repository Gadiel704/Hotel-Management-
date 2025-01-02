#include <iostream>
#include <string>
using namespace std;

// Room structure to store room details
struct Room {
    int roomNumber;
    string roomType;
    bool isBooked;
    string guestName;
};

class HotelManagement {
private:
    Room rooms[5]; // Array to store room details

public:
    HotelManagement() {
        // Initialize rooms
        for (int i = 0; i < 5; i++) {
            rooms[i].roomNumber = i + 1;
            rooms[i].roomType = (i % 2 == 0) ? "Single" : "Double";
            rooms[i].isBooked = false;
            rooms[i].guestName = "";
        }
    }

    void displayAvailableRooms() {
        cout << "\nAvailable Rooms:\n";
        for (const auto &room : rooms) {
            if (!room.isBooked) {
                cout << "Room Number: " << room.roomNumber
                     << ", Room Type: " << room.roomType << endl;
            }
        }
    }

    void bookRoom() {
        int roomNumber;
        string guestName;

        cout << "\nEnter Room Number to Book: ";
        cin >> roomNumber;
        cin.ignore(); // Clear the input buffer

        if (roomNumber < 1 || roomNumber > 5) {
            cout << "Invalid Room Number. Please try again.\n";
            return;
        }

        if (rooms[roomNumber - 1].isBooked) {
            cout << "Room already booked. Please choose another room.\n";
        } else {
            cout << "Enter Guest Name: ";
            getline(cin, guestName);

            rooms[roomNumber - 1].isBooked = true;
            rooms[roomNumber - 1].guestName = guestName;

            cout << "Room " << roomNumber << " booked successfully for " << guestName << ".\n";
        }
    }

    void displayBookedRooms() {
        cout << "\nBooked Rooms:\n";
        for (const auto &room : rooms) {
            if (room.isBooked) {
                cout << "Room Number: " << room.roomNumber
                     << ", Room Type: " << room.roomType
                     << ", Guest Name: " << room.guestName << endl;
            }
        }
    }

    void cancelBooking() {
        int roomNumber;
        cout << "\nEnter Room Number to Cancel Booking: ";
        cin >> roomNumber;

        if (roomNumber < 1 || roomNumber > 5) {
            cout << "Invalid Room Number. Please try again.\n";
            return;
        }

        if (!rooms[roomNumber - 1].isBooked) {
            cout << "Room is not booked.\n";
        } else {
            rooms[roomNumber - 1].isBooked = false;
            rooms[roomNumber - 1].guestName = "";
            cout << "Booking for Room " << roomNumber << " has been canceled.\n";
        }
    }
};

int main() {
    HotelManagement hotel;
    int choice;

    do {
        cout << "\n--- Hotel Management System ---\n";
        cout << "1. Display Available Rooms\n";
        cout << "2. Book a Room\n";
        cout << "3. Display Booked Rooms\n";
        cout << "4. Cancel Booking\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hotel.displayAvailableRooms();
                break;
            case 2:
                hotel.bookRoom();
                break;
            case 3:
                hotel.displayBookedRooms();
                break;
            case 4:
                hotel.cancelBooking();
                break;
            case 5:
                cout << "Exiting... Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
