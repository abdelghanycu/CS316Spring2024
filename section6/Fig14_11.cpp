//#include <iostream>
//#include <fstream>
//#include <cstdlib>
//#include "ClientData.h" // ClientData class definition
//
//using namespace std;
//
//int main() {
//    fstream outCredit{"D:\\Projects\\0Test\\0c++\\CS316\\credit.dat", ios::in | ios::out | ios::binary};
//
//    // exit program if fstream cannot open file
//    if (!outCredit) {
//        cerr << "File could not be opened." << endl;
//        exit(EXIT_FAILURE);
//    }
//
//    cout << "Enter account number (1 to 100, 0 to end input)\n? ";
//
//    int accountNumber;
//    string lastName;
//    string firstName;
//    double balance;
//
//    cin >> accountNumber; // read account number
//
//    // user enters information, which is copied into file
//    while (accountNumber > 0 && accountNumber <= 100) {
//        // user enters last name, first name and balance
//        cout << "Enter lastname, firstname and balance\n? ";
//        cin >> lastName;
//        cin >> firstName;
//        cin >> balance;
//
//        // create ClientData object
//        ClientData client{accountNumber, lastName, firstName, balance};
//
//        // seek position in file of user-specified record
//        outCredit.seekp(
//                (client.getAccountNumber() - 1) * sizeof(ClientData));
//
//        // write user-specified information in file
//        outCredit.write(
//                reinterpret_cast<const char *>(&client), sizeof(ClientData));
//
//        // enable user to enter another account
//        cout << "Enter account number\n? ";
//        cin >> accountNumber;
//    }
//}