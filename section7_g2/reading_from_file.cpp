//#include <bits/stdc++.h>
//
//using namespace std;
//
//vector<vector<int> > vec;
//
//int main() {
//
//    int delimiter = 999999;
//
//    fstream file{"D:\\Projects\\0Test\\0c++\\CS316\\section7_g2\\data.dat", ios::in | ios::out | ios::binary};
//
//    vector<int> rec;
//    int val;
//
//    while(!file.eof()) {
//        file.read(reinterpret_cast<char*>(&val), sizeof(int));
//        if(val != delimiter) {
//            rec.push_back(val);
//        }else {
//            vec.push_back(rec);
//            rec.clear();
//        }
//    }
//
//    file.close();
//
//    for (int i = 0; i < vec.size(); i++) {
//        for (int j = 0; j < vec[i].size(); j++) {
//            cout << vec[i][j] << " ";
//        }
//        cout << endl;
//    }
//}