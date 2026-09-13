
// this is just the console menu, doesn't have any real logic in it,
// just reads input and calls the right functions.
//
// quick note: our teacher said "no header files" but also "one class per
// file", so I just made every class its own .cpp file with an include
// guard and #include them where needed (mainly here in main.cpp). it's
// not exactly how real projects separate .h and .cpp but it follows both
// rules given in the assignment.
#include <iostream>
#include <string>
#include <vector>
#include "04_Cinema.cpp"
#include "05_Show.cpp"
#include "07_Customer.cpp"
#include "10_PaymentTypes.cpp"
#include "13_BookingService.cpp"
using namespace std;

// splits something like "A1,B2" into {"A1", "B2"}
// doing this manually with find() instead of stringstream, keeps it simple
vector<string> splitSeats(string input) {
    vector<string> seats;
    string current = "";
    for (int i = 0; i < (int)input.length(); i++) {
        char c = input[i];
        if (c == ',') {
            if (current.length() > 0) seats.push_back(current);
            current = "";
        } else if (c != ' ') {
            current += c;
        }
    }
    if (current.length() > 0) seats.push_back(current);
    return seats;
}

int main() {
    // just some sample data so we have something to book. in a real system
    // this would come from a database instead of being typed in here.
    Cinema cinema("PVR Downtown");

    Movie m1("3 Idiots", "Hindi", 170);
    Movie m2("Interstellar", "English", 169);

    Screen screen1("Screen-1");
    Screen screen2("Screen-2");
    cinema.addScreen(screen1);
    cinema.addScreen(screen2);

    Show show1("S1", &m1, &cinema.getScreens()[0], "06:00 PM");
    Show show2("S2", &m1, &cinema.getScreens()[1], "09:00 PM");

    BookingService bookingService;
    Customer currentCustomer("Guest", "9999999999");

    cout << "===== MOVIE TICKET BOOKING =====" << endl;

    bool running = true;
    while (running) {
        cout << endl << "1. Movies  2. Book  3. Cancel  4. My tickets   0. Exit" << endl;
        cout << "Choose: ";
        int choice;
        cin >> choice;

        if (cin.fail()) {
            // user typed something that's not a number
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input." << endl;
            continue;
        }

        if (choice == 1) {
            cout << endl;
            cout << "  [1] " << m1.getTitle() << "\t" << m1.getLanguage() << "\t" << m1.getDurationMinutes() << " min" << endl;
            cout << "  [2] " << m2.getTitle() << "\t" << m2.getLanguage() << "\t" << m2.getDurationMinutes() << " min" << endl;

        } else if (choice == 2) {
            cout << endl << "Choose movie: ";
            int mChoice;
            cin >> mChoice;