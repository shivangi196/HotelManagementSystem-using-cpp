#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include<stdlib.h>

using namespace std;

struct Booking {
    string guestName;
    string address;
    string mobileNumber;
    int roomNumber;
    int numberOfPeople;
    int lengthOfStay;
    bool checkedIn;
    double totalPayment;
};

class HotelManagementSystem {
    
private:
    vector<Booking> bookings;
    bool roomsAvailability[10];

public:
    HotelManagementSystem() {
    for (int i = 0; i < 10; ++i) {
            roomsAvailability[i] = true;
        }
    }
void displayAvailableRooms() {
        cout << "Available Rooms:" << endl;
        for (int i = 0; i < 10; ++i) {
            if (roomsAvailability[i]) {
                cout << "Room " << i + 1 << ": Available" << endl;
            }
        }
    }
    void reserveRoom() {
        Booking booking;
        displayAvailableRooms();
        cout << "Enter guest name: ";
        cin.ignore();
        getline(cin,booking.guestName);
        cout << "Enter room number: ";
        cin >> booking.roomNumber;

        for (int i = 0; i < bookings.size();i++) {
            if (bookings[i].roomNumber == booking.roomNumber) {
                cout << "Room is already reserved. Please choose a different room." << endl;
                cout << "Enter room number: ";
                cin >> booking.roomNumber;
                continue;
            }
        }
        cout << "Enter guest address: ";
        cin.ignore();
        getline(cin, booking.address);
        cout << "Enter guest mobile number: ";
        cin >> booking.mobileNumber;
        while(booking.mobileNumber.length()!=10){
            cout<<"Please enter a valid mobile number!!"<<endl;
            cin >> booking.mobileNumber;
        }
        
        cout << "Enter number of people (in number): ";
        cin >> booking.numberOfPeople;
        cout << "Enter length of stay (in days): ";
        cin >> booking.lengthOfStay;
        
        double roomRate = 500.0;
        booking.totalPayment = booking.lengthOfStay * roomRate;

        bookings.push_back(booking);
        roomsAvailability[booking.roomNumber - 1] = false;
        cout << "Room reserved successfully." << endl;
    }

    void checkInGuest() {
        int roomNumber;
        cout << "Enter room number: ";
        cin >> roomNumber;

        for (int i = 0; i < bookings.size(); i++) {
            if (bookings[i].roomNumber == roomNumber) {
                if (!bookings[i].checkedIn) {
                    bookings[i].checkedIn = true;

                    cout << "Guest checked in successfully." << endl;
                    cout<<"To see the details PRESS"<<endl<<"1.Guest"<<endl<<"2.Owner"<<endl;
                    int ch;
                    cin>>ch;
                    if(ch==1)
                    displayBookingDetailsG(bookings[i]);
                    else
                    displayBookingDetails(bookings[i]);
                } else {
                    cout << "Guest is already checked in." << endl;
                }
                return;
            }
        }

        cout << "Room not found or reserved." << endl;
    }

    void checkOutGuest() {
        int roomNumber;
        cout << "Enter room number: ";
        cin >> roomNumber;

        for (int i = 0; i < bookings.size(); i++) {
            if (bookings[i].roomNumber == roomNumber) {
                if (bookings[i].checkedIn) {
                    bookings[i].checkedIn = false;
                    cout << "Guest checked out successfully." << endl;
                    displayBookingDetails(bookings[i]);
                } else {
                    cout << "Guest is not checked in." << endl;
                }
                return;
            }
        }

        cout << "Room not found or reserved." << endl;
    }

    void displayBookings() {
        cout << "List of bookings:" << endl;
        for (int i = 0; i < bookings.size(); i++) {
            displayBookingDetails(bookings[i]);
            cout << "-----------------------" << endl;
        }
    }

    void searchCustomer() {
        string guestName;
        cout << "Enter guest name to search: ";
        cin >> guestName;

        cout << "Search results:" << endl;
        for (int i = 0; i < bookings.size(); i++) {
            if (bookings[i].guestName == guestName) {
                displayBookingDetails(bookings[i]);
                return;
            }
        }

        cout << "Guest not found." << endl;
    }

    void checkOutRoom() {
        int roomNumber;
        cout << "Enter room number to check out: ";
        cin >> roomNumber;

        for (int i = 0; i < bookings.size(); i++) {
            if (bookings[i].roomNumber == roomNumber) {
                if (bookings[i].checkedIn) {
                    bookings[i].checkedIn = false;
                    cout << "Room checked out successfully." << endl;
                    displayBookingDetails(bookings[i]);
                } else {
                    cout << "Room is not checked in." << endl;
                }
                return;
            }
        }

        cout << "Room not found or reserved." << endl;
    }

    void guestSummaryReport() {
        int checkedInCount = 0;
        int checkedOutCount = 0;

        for (int i = 0; i < bookings.size(); i++) {
            if (bookings[i].checkedIn) {
                checkedInCount++;
            } else {
                checkedOutCount++;
            }
        }

        cout << "Guest Summary Report:" << endl;
        cout << "Checked In Guests: " << checkedInCount << endl;
        cout << "Checked Out Guests: " << checkedOutCount << endl;
    }

    void totalBill() {
        double totalRevenue = 0.0;
        for (int i = 0; i < bookings.size(); i++) {
            totalRevenue += bookings[i].totalPayment;
        }

        cout.precision(2);
        cout << "Total Revenue: Rs." << fixed << totalRevenue << endl;
    }

private:
    void displayBookingDetails(const Booking& booking) {
        cout << "Guest: " << booking.guestName << endl;
        cout << "Address: " << booking.address << endl;
        cout << "Mobile Number: " << booking.mobileNumber << endl;
        cout << "Room: " << booking.roomNumber << endl;
        cout << "Number of People: " << booking.numberOfPeople << endl;
        cout << "Length of Stay: " << booking.lengthOfStay << " days" << endl;
        cout << "Checked In: " << (booking.checkedIn ? "Yes" : "No") << endl;
        cout.precision(2);
        cout << "Total Payment: Rs. " << fixed << booking.totalPayment << endl;
    }

    void displayBookingDetailsG(const Booking& booking) {
        cout << "Guest: " << booking.guestName << endl;
        cout << "Address: " << booking.address << endl;
        cout << "Mobile Number: ";
        string MobNumber=booking.mobileNumber.substr(6,4);
        cout<<"******"<<MobNumber<<endl;
        cout.precision(2);
        cout << "Total Payment: Rs. " << fixed << booking.totalPayment << endl;
    }
};

int main() {
    HotelManagementSystem hotel;

    int choice;
    do {
    system("CLS");
	cout<<endl<<"****************************************"<<endl;
    cout<<endl<<"--------WELCOME TO MYSIG HOTEL----------"<<endl;//mysig(swedish): a cozy and warm atmosphere especially on a cold day 
    cout<<endl<<"****************************************"<<endl;
        cout << "\nHotel Management System Menu:" << endl;
        cout << "1. Reserve a room" << endl;
        cout << "2. Check in a guest" << endl;
        cout << "3. Check out a guest" << endl;
        cout << "4. Display all bookings" << endl;
        cout << "5. Search customer" << endl;
        cout << "6. Check out room" << endl;
        cout << "7. Guest summary report" << endl;
        cout << "8. Total Bill" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hotel.reserveRoom();
                break;
            case 2:
                hotel.checkInGuest();
                break;
            case 3:
                hotel.checkOutGuest();
                break;
            case 4:
                hotel.displayBookings();
                break;
            case 5:
                hotel.searchCustomer();
                break;
            case 6:
                hotel.checkOutRoom();
                break;
            case 7:
                hotel.guestSummaryReport();
                break;
            case 8:
                hotel.totalBill();
                break;
            case 9:
                cout<<"Exiting.."<<endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << "------Thank you fo using MYSIG Hotel sevices------" << endl;
    } while (choice != 9);

    return 0;
}
