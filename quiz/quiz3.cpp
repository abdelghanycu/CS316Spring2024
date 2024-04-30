//#include <bits/stdc++.h>
//
//using namespace std;
//
//class person {
//public:
//    person();
//    person(string, string, int, int);
//    string get_last_name();
//    void set_last_name(string);
//    string get_first_name();
//    void set_first_name(string);
//    int get_age();
//    void set_age(int);
//    int get_id();
//    void set_id(int);
//private:
//    char last_name[15];
//    char first_name[15];
//    int age;
//    int id;
//};
//
//// group 1 question 1
//person get_old(int x, int y) {
//    fstream data_file{"data.dat", ios::in | ios::out | ios::binary};
//
//    person p, tmp;
//    p.set_age(-1);
//
//    data_file.seekg(x * sizeof (person));
//    for(int i = x; i <= y; i++) {
//        data_file.read(reinterpret_cast<char *>(&tmp), sizeof(int));
//        if(tmp.get_age() > p.get_age()){
//            p = tmp;
//        }
//    }
//
//    data_file.close();
//
//    return p;
//}
//
//// group 1 question 2
//person update_last_name(int id, string name) {
//    fstream data_file{"data.dat", ios::in | ios::out | ios::binary};
//
//    person p;
//
//    data_file.seekg(id * sizeof (person));
//    data_file.read(reinterpret_cast<char *>(&p), sizeof(person));
//
//    p.set_last_name(name);
//
//    data_file.seekp(id * sizeof (person));
//    data_file.write(reinterpret_cast<const char *>(&p), sizeof(person));
//
//    data_file.close();
//
//    return p;
//}
//
//// group 2 question 1
//bool find_person(int x, int y, string last_name) {
//    fstream data_file{"data.dat", ios::in | ios::out | ios::binary};
//
//    person p;
//
//    data_file.seekg(x * sizeof (person));
//    for(int i = x; i <= y; i++) {
//        data_file.read(reinterpret_cast<char *>(&p), sizeof(int));
//        if(last_name != p.get_last_name()) { // this check may be wrong, need to loop on each char
//            return true;
//        }
//    }
//
//    data_file.close();
//
//    return false;
//}
//
//// group 2 question 2
//person update_first_name(int id, string name) {
//    fstream data_file{"data.dat", ios::in | ios::out | ios::binary};
//
//    person p;
//
//    data_file.seekg(id * sizeof (person));
//    data_file.read(reinterpret_cast<char *>(&p), sizeof(person));
//
//    p.set_first_name(name);
//
//    data_file.seekp(id * sizeof (person));
//    data_file.write(reinterpret_cast<const char *>(&p), sizeof(person));
//
//    data_file.close();
//
//    return p;
//}