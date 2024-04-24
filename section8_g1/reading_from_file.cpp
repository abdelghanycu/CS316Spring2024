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
//    fstream data_file{"D:\\Projects\\0Test\\0c++\\CS316\\section8_g1\\data.dat", ios::in | ios::out | ios::binary};
//    fstream index_file{"D:\\Projects\\0Test\\0c++\\CS316\\section8_g1\\index.dat", ios::in | ios::out | ios::binary};
//
//    vector<int> rec;
//    int offset, sz, val, deleted;
//
//    while(!index_file.eof()) {
//        index_file.read(reinterpret_cast<char*>(&offset), sizeof(int));
//        index_file.read(reinterpret_cast<char*>(&sz), sizeof(int));
//        index_file.read(reinterpret_cast<char*>(&deleted), sizeof(int));
////        cout << offset << " " << sz << " " << deleted << endl;
//        data_file.seekg(offset * sizeof(int));
//        for(int i = 0; i < sz; i++) {
//            data_file.read(reinterpret_cast<char*>(&val), sizeof(int));
//            rec.push_back(val);
//        }
//        if(!deleted) {
//            vec.push_back(rec);
//        }
//        rec.clear();
//    }
//
//    data_file.close();
//    index_file.close();
//
//    for (int i = 0; i < vec.size(); i++) {
//        for (int j = 0; j < vec[i].size(); j++) {
//            cout << vec[i][j] << " ";
//        }
//        cout << endl;
//    }
//}