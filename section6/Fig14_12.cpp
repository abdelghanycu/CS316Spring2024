//#include <bits/stdc++.h>
//#include "ClientData.h" // ClientData class definition
//
//using namespace std;
//
//void outputLine(ostream &, const ClientData &); // prototype
//
//
//int main() {
//    ifstream inCredit{"D:\\\\Projects\\\\0Test\\\\0c++\\\\CS316\\\\credit.dat", ios::in | ios::binary};
//
//    // exit program if ifstream cannot open file
//    if (!inCredit) {
//        cerr << "File could not be opened." << endl;
//        exit(EXIT_FAILURE);
//    }
//
//    // output column heads
//    cout << left << setw(10) << "Account" << setw(16) << "Last Name"
//         << setw(11) << "First Name" << setw(10) << right << "Balance\n";
//
//    ClientData client; // create record
//    client.setAccountNumber(79);
//
//    inCredit.seekg((client.getAccountNumber() - 1) * sizeof(ClientData));
//
//    // read first record from file
//    inCredit.read(reinterpret_cast<char*>(&client), sizeof(ClientData));
//
//    outputLine(cout, client);
//
//
//    // read all records from file
////    while (inCredit) {
////        // display record
////        if (client.getAccountNumber() != 0) {
////            outputLine(cout, client);
////        }
////
////        // read next from file
////        inCredit.read(reinterpret_cast<char*>(&client), sizeof(ClientData));
////    }
//}
//
//// display single record
//void outputLine(ostream &output, const ClientData &record) {
//    output << left << setw(10) << record.getAccountNumber()
//           << setw(16) << record.getLastName()
//           << setw(11) << record.getFirstName()
//           << setw(10) << setprecision(2) << right << fixed
//           << showpoint << record.getBalance() << endl;
//}