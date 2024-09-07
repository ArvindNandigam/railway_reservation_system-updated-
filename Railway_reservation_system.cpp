#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

class credentials {
private:
    string name;
    string password;

public:
    credentials(string a, string b) {
        name = a;
        password = b;
    }
    void setname(string aa) {
        name = aa;
    }
    string getname() {
        return name;
    }
    void setpassword(string ab) {
        password = ab;
    }
    string getpassword() {
        return password;
    }
};

class train {
private:
    int train_no;
    string arrival;
    string destination;
    float distance;
    float cost;
    int number_of_tickets;
public:
    train(int a, string b, string c, float d,int e) {
        train_no = a;
        arrival = b;
        destination = c;
        distance = d;
        cost = 10.5 * d;
        number_of_tickets=e;
    }
    void set_train_no(int a) {
        train_no = a;
    }
    int get_train_no() {
        return train_no;
    }
    void set_arrival(string b) {
        arrival = b;
    }
    string get_arrival() {
        return arrival;
    }
    void set_destination(string c) {
        destination = c;
    }
    string get_destination() {
        return destination;
    }
    float get_distance() {
        return distance;
    }
    void set_distance(float d) {
        distance = d;
        cost = 10.5 * d;
    }
    float get_cost() {
        return cost;
    }
    void set_number_of_tickets(int a){
        number_of_tickets = a;
    }
    int get_number_of_tickets(){
        return number_of_tickets;
    }
};

class ticket {
    private :
    int PNR_Number;
    string start_point;
    string end_point;
    string mode_of_payment;
    string name;
    public : 
    ticket(int a,string b,string c,string d,string e){
        PNR_Number=a;
        start_point=b;
        end_point=c;
        mode_of_payment=d;
        name = e;
    }
    void set_new_starting_point(string a){
        start_point=a;
    }
    string get_start_point(){
        return start_point;
    }
    void set_new_end_point(string a){
        end_point=a;
    }
    string get_end_point(){
        return end_point;
    }
    void set_mode_of_payment(string a){
        mode_of_payment=a;
    }
    string return_mode_of_payment(){
        return mode_of_payment;
    }
    void set_new_name(string a){
        name=a;
    }
    string return_name(){
        return name;
    }
    void print_ticket(){
        cout << "---------------------------------------------------------------------------------\n";
        cout << "PNR Number : " << PNR_Number << "\n";
        cout << "Name : " << name << "\n";
        cout << "Mode of payment : " << mode_of_payment << "\n";
        cout << "Starting point : " << start_point << "\n";
        cout << "Ending point : " << end_point << "\n";
        cout << "---------------------------------------------------------------------------------\n";
    }
};

bool isValidPassword(const std::string& password) {
    if (password.length() < 12) {
        return false;
    }
    char firstChar = password[0];
    if (!std::isupper(firstChar)) {
        return false;
    }

    bool has_digit = false, has_special_char = false;

    for (char c : password) {
        if (std::isdigit(c)) {
            has_digit = true;
        }
        if (std::ispunct(c)) {
            has_special_char = true;
        }
    }

    return has_digit && has_special_char;
}

int random_number_generator() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int random_number = 100000 + rand() % 900000;
    return random_number;
}

void creating_new_credentials(std::list<credentials>* a) {
    if (!a) {
        std::cerr << "Invalid list pointer.\n" << std::endl;
        return;
    }
    std::list<credentials> b = *a;
    std::string username_01;
    std::string userpassword_01;
    std::cout << "Please enter your new username: ";
    std::cin >> username_01;
    std::cout << "\n";
    std::cout << "You have 3 chances to enter a new password with the following conditions:\n"<< "1) The first letter of the password should be capital\n"<< "2) It should have at least one number\n"<< "3) It should have at least one special character\n"<< "4) It should have a length of 12 or more characters\n";
    int i = 0;
    while (i < 3) {
        std::cout << "\nPlease enter the new password: ";
        std::cin >> userpassword_01;
        if (isValidPassword(userpassword_01)) {
            b.push_back(credentials(username_01, userpassword_01));
            *a = b;
            return;
        } else {
            std::cout << "Password Invalid !!!\n";
            i = i + 1;
        }
    }
    std::cout << "All 3 attempts are over. Please try again later.\n";
}
void adding_new_place(list<string> *a){
    string new_place;
    list<string> b = *a;
    cout << "Enter the new place : ";
    cin >> new_place;
    cout << "\n";
    b.push_back(new_place);
    (*a)=b;
}
void show_all_places(list <string> a){
    for (auto& aa : a){
        cout << aa << "\n";
    }
}

void access_ticket_by_PNR(const list<int>& list_of_pnr_numbers) {
    int PNR;
    cout << "Enter PNR Number: ";
    cin >> PNR;
    cout << "\n";
    bool found = false;
    for (auto& ticket : list_of_pnr_numbers) {
        if (ticket == PNR) {
            found = true;
            cout << "Ticket found with PNR Number: " << PNR << "\n";
            break;
        }
    }
    if (!found) {
        cout << "Ticket not found with PNR Number: " << PNR << "\n";
    }
}

void book_tickets_for_train(list<train>& list_of_trains, list<int>& list_of_pnr_numbers) {
    int train_number, tickets;
    cout << "Enter Train Number: ";
    cin >> train_number;
    cout << "\n";
    bool found = false;
    for (auto& train : list_of_trains) {
        if (train.get_train_no() == train_number) {
            found = true;
            cout << "Train found with Train Number: " << train_number << "\n";
            cout << "Available Tickets: " << train.get_number_of_tickets() << "\n";
            cout << "Enter number of tickets to book: ";
            cin >> tickets;
            if (tickets <= train.get_number_of_tickets()) {
                // Decrease available tickets
                train.set_number_of_tickets(train.get_number_of_tickets() - tickets);
                int new_pnr = random_number_generator();
                list_of_pnr_numbers.push_back(new_pnr);
                cout << "Tickets booked successfully. Your PNR Number is " << new_pnr << "\n";
            } else {
                cout << "Tickets not available.\n";
            }
            break;
        }
    }
    if (!found) {
        cout << "Train not found with Train Number: " << train_number << "\n";
    }
}
void print_all_admins(list<credentials> a) {
    for (const auto& admin : a) {
        cout << "Admin Username: " << admin.getname() << "\n";
    }
}

int main() {
    int mode;
    list<credentials> admin_list_of_credentials = {};
    list<credentials> user_list_of_credentials = {};
    list<string> places = {};
    list<train> list_of_trains = {};
    credentials default_credentials("host", "root");
    list<int> list_of_pnr_numbers={};
    ticket t1 (123456,"a","b","c","d");
    t1.print_ticket();
    admin_list_of_credentials.push_back(default_credentials);
    list_of_trains.push_back(train(101, "CityA", "CityB", 500.0, 100)); // Example Train
    bool loop=true;
    while (loop){
        cout << "               Railway reservation system               " << "\n";
        cout << " Enter 0 to terminate the program\n Enter 1 for administrator mode \n Enter 2 for user mode \n Enter the mode : ";
        cin >> mode;
        cout << "\n";
        switch (mode) {
        case 0 :
            cout <<"Program termination complete";
            loop=false;
            break;
        case 1:
            {
                string username, userpassword;
                cout << "Administrator mode activated \n";
                cout << "Entering the credentials....\n";
                bool validAdmin = false;
                while (!validAdmin) {
                    cout << "Enter your admin username : ";
                    cin >> username;
                    cout << "\n";
                    for (auto& admin : admin_list_of_credentials) {
                        if (admin.getname() == username) {
                            validAdmin = true;
                            cout << "Enter your password : ";
                            cin >> userpassword;
                            cout << "\n";
                            if (admin.getpassword() == userpassword) {
                                cout << "Valid password\nEntering into the account.....\n";
                                cout << "0-Logout of this admin account\n1-Create new admin credentials\n2-Create new user credentials\n3-Add new place (destination or arrival)\n4-Access PNR Number\n5-Access the train\n6-Show all the admin credentials(available for root holder only)\n7-Show all the user credentials (available for root holder only)\n8-Show the list of all places\n";
                                int amode;
                                cin >> amode;
                                switch (amode)
                                {
                                case 0 :
                                    cout << "Logout Successful\n";
                                    break;
                                case 1:
                                    creating_new_credentials(&admin_list_of_credentials);
                                    break;
                                case 2:
                                    creating_new_credentials(&user_list_of_credentials);
                                    break;
                                case 3:
                                    adding_new_place(&places);
                                    break;
                                case 4:
                                    access_ticket_by_PNR(list_of_pnr_numbers);
                                    break;
                                case 5:
                                    book_tickets_for_train(list_of_trains, list_of_pnr_numbers);
                                    break;
                                case 6:
                                    if ((username=="host")&&(userpassword=="root")){
                                        cout << "Here is the list of admins : \n";
                                        print_all_admins(admin_list_of_credentials);
                                    }
                                    else{
                                        cout << "You don't have the necessary credentials";
                                    }
                                    break;
                                case 7:
                                    //code
                                    break;
                                case 8 :
                                    show_all_places(places);
                                    break;
                                default:
                                    cout << "Invalid mode";
                                    break;
                                }
                            }
                            else {
                                cout << "Invalid password\n";
                            }
                            break;
                        }
                    }
                    if (!validAdmin) {
                        cout << "Invalid username. Please try again.\n";
                        continue; 
                    }
                }
            }
            break;
        case 2:
            cout << "User mode activated \n";
            cout << "1-Book tickets for a train\n2-Check PNR status\n";
            int umode;
            cin >> umode;
            switch (umode) {
            case 1:
                book_tickets_for_train(list_of_trains, list_of_pnr_numbers);
                break;
            case 2:
                access_ticket_by_PNR(list_of_pnr_numbers);
                break;
            default:
                cout << "Invalid option\n";
                break;
            }
            break;
        default:
            cout << "Invalid mode \n";
            break;
        }
    }
    return 0;
}
