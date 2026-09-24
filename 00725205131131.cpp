/*
    Cinema Hall Management Program Project

    Classes,
        - Film
        - Seat
        - Ticket
*/

#include <iostream>
#include <vector>

using namespace std;

class Movie {
    private:
        string name;
        int ID;
        int duration_hr;
        float price;

    public:
        Movie(string, int, float);

        string get_name() {
            return name;
        }
        int get_id() {
            return ID;
        }
        int get_duration() {
            return duration_hr;
        }
        float get_price() {
            return price;
        }
};

Movie::Movie(string new_name, int new_duration, float new_price) {
    name = new_name;
    duration_hr = new_duration;
    price = new_price;
    ID = 0;     // ToDo
}

//  Vectors
vector<Movie> movies = {Movie("The Shawshank Redemption", 2, 300), Movie("The GodFather", 2, 400)};




void print_movie_list() {
    if (movies.size() != 0) {
        cout << endl << "===== Movie | Duration | Price =====" << endl;
        for (auto it = movies.begin(); it != movies.end(); it++) {
            cout << (*it).get_name() << " | " << (*it).get_duration() << "hr | " << (*it).get_price() << " Taka" << endl;
        }
        cout << endl << endl;
    } else {
        cout << "The list is empty!" << endl;
    }
}

void add_new_movie() {
    string movie_name;
    int movie_duration;
    float movie_price;

    cout << "Movie Name: "; cin.ignore(); getline(cin, movie_name);
    cout << "Duration: "; cin >> movie_duration; cin.ignore();
    cout << "Price: "; cin >> movie_price; cin.ignore();

    Movie new_movie(movie_name, movie_duration, movie_price);
    movies.push_back(new_movie);
    cout << "\"" << movie_name << "\" added to the list" << endl << endl << endl;

}

void manage_movie() {
    while (true) {
        cout << "---------- Movie Management ----------" << endl;
        cout << "1) View Movie List" << endl;
        cout << "2) Add New Movie" << endl;
        cout << "3) Remove a Movie" << endl;
        cout << "4) Return to Main Menu" << endl;
        cout << "Option (1-4): " << endl;

        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
            print_movie_list();
            break;

        case 2:
            add_new_movie();
            break;

        case 3:
            remove_movie();
            break;

        case 4:
            return;
        }
    }
}

void main_menu() {

    while (true) {
        cout << "==========" << " Cinema Hall Management " << "=========" << endl;
        cout << "1) Manage Movie List" << endl;
        cout << "2) Manage Seats" << endl;
        cout << "3) Generate a Ticket" << endl;
        cout << "4) Exit" << endl << endl;

        cout << "Option (1-4): ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            manage_movie();
            break;
        case 2:
            cout << "Manage seats" << endl;
            break;
            // manage_seats();
        case 3:
            cout << "Generate ticket" << endl;
            break;
            //generate_ticket();
        case 4:
            return;
        }
    }

}

int main() {
    main_menu();
    return 0;
}
