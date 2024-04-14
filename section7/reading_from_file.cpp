//#include <bits/stdc++.h>
//
//using namespace std;
//
//vector<vector<int> > vec;
//
//int main() {
//
//    int delimiter = 99999;
//
//    fstream file_data{"D:\\Projects\\0Test\\0c++\\CS316\\section7\\data.dat", ios::in | ios::out | ios::binary};
//
//    vector<int> rec;
//    int val;
//
//    while (!file_data.eof()) {
//        file_data.read(reinterpret_cast<char *>(&val), sizeof(int));
//        if (val == delimiter) {
//            vec.push_back(rec);
//            rec.clear();
//        } else {
//            rec.push_back(val);
//        }
//    }
//
//    for (int i = 0; i < vec.size(); i++) {
//        for (int j = 0; j < vec[i].size(); j++) {
//            cout << vec[i][j] << " ";
//        }
//        cout << endl;
//    }
//}