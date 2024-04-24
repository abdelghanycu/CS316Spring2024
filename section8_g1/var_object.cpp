//#include <bits/stdc++.h>
//
//using namespace std;
//
//vector<vector<int> > vec;
//
//pair<int, int> get_best_fit_position() {
//    fstream index_file{"D:\\Projects\\0Test\\0c++\\CS316\\section8_g1\\index.dat", ios::in | ios::out | ios::binary};
//    vector<pair<int, int> > v;
//    int offset, sz, deleted;
//    while(!index_file.eof()) {
//        index_file.read(reinterpret_cast<char*>(&offset), sizeof(int));
//        index_file.read(reinterpret_cast<char*>(&sz), sizeof(int));
//        index_file.read(reinterpret_cast<char*>(&deleted), sizeof(int));
//        if(deleted) {
//            v.push_back(make_pair(sz, offset));
//        }
//    }
//    index_file.close();
//    sort(v.begin(), v.end());
//
//    if(v.size()) return v[0];
//    return make_pair(-1 , -1);
//}
//
//void record_to_delete(int idx) {
//    int deleted = 1;
//    fstream index_file{"D:\\Projects\\0Test\\0c++\\CS316\\section8_g1\\index.dat", ios::in | ios::out | ios::binary};
//    index_file.seekp((idx - 1) * (3 * sizeof(int)) + (2 * sizeof(int)));
//    index_file.write(reinterpret_cast<const char *>(&deleted), sizeof(int));
//    index_file.close();
//}
//
//void record_to_be_add(int idx, int sz) {
//    int deleted = 0;
//    fstream index_file{"D:\\Projects\\0Test\\0c++\\CS316\\section8_g1\\index.dat", ios::in | ios::out | ios::binary};
//    index_file.seekp((idx - 1) * (3 * sizeof(int)) + sizeof (int));
//    index_file.write(reinterpret_cast<const char *>(&sz), sizeof(int));
//    index_file.write(reinterpret_cast<const char *>(&deleted), sizeof(int));
//    index_file.close();
//}
//
//void insert_into_index(int offset, vector<int> rec) {
//    fstream data_file{"D:\\Projects\\0Test\\0c++\\CS316\\section8_g1\\data.dat", ios::in | ios::out | ios::binary};
//    data_file.seekp(offset * sizeof (int));
//    for (int i = 0; i < rec.size(); i++) {
//        data_file.write(reinterpret_cast<const char *>(&rec[i]), sizeof(int));
//    }
//}
//
//void add_end_of_file(vector<int> rec) {
//
//}
//
//void add_to_index_new_fregment(int offset, int sz) {
//    int deleted = 1;
//    fstream index_file{"D:\\Projects\\0Test\\0c++\\CS316\\section8_g1\\index.dat", ios::in | ios::out | ios::binary | ios::app};
//    index_file.write(reinterpret_cast<const char *>(&offset), sizeof(int));
//    index_file.write(reinterpret_cast<const char *>(&sz), sizeof(int));
//    index_file.write(reinterpret_cast<const char *>(&deleted), sizeof(int));
//    index_file.close();
//}
//
//void insert_by_first_fit(vector<int> rec) {
//    fstream index_file{"D:\\Projects\\0Test\\0c++\\CS316\\section8_g1\\index.dat", ios::in | ios::out | ios::binary};
//    int offset, sz, deleted;
//    int idx = 1;
//    while (!index_file.eof()) {
//        index_file.read(reinterpret_cast<char *>(&offset), sizeof(int));
//        index_file.read(reinterpret_cast<char *>(&sz), sizeof(int));
//        index_file.read(reinterpret_cast<char *>(&deleted), sizeof(int));
//        if (sz >= rec.size() && deleted) {
//            record_to_be_add(idx, rec.size());
//            insert_into_index(offset, rec);
//            if(sz > rec.size()) {
//                add_to_index_new_fregment(offset + rec.size(), sz - rec.size());
//            }
//            return;
//        }
//        idx++;
//    }
//    index_file.close();
//
//    add_end_of_file(rec);
//}
//
//int main() {
//
////    int n, m;
////    cin >> n;
////    for (int k = 0; k < n; k++) {
////        cin >> m;
////        vector<int> rec(m);
////        for (int i = 0; i < m; i++) {
////            cin >> rec[i];
////        }
////        vec.push_back(rec);
////    }
//
////    fstream data_file{"D:\\Projects\\0Test\\0c++\\CS316\\section8_g1\\data.dat", ios::in | ios::out | ios::binary};
////    fstream index_file{"D:\\Projects\\0Test\\0c++\\CS316\\section8_g1\\index.dat", ios::in | ios::out | ios::binary};
////
////    int offset = 0, deleted = 0;
////    for(int i = 0; i < vec.size(); i++) {
////
////        int sz = vec[i].size();
////
////        index_file.write(reinterpret_cast<const char *>(&offset), sizeof(int));
////        index_file.write(reinterpret_cast<const char *>(&sz), sizeof(int));
////        index_file.write(reinterpret_cast<const char *>(&deleted), sizeof(int));
////
////        for(int j = 0; j < vec[i].size(); j++) {
////            data_file.write(reinterpret_cast<const char *>(&vec[i][j]), sizeof(int));
////        }
////
////        offset += sz;
////    }
////    data_file.close();
////    index_file.close();
//
//    record_to_delete(2);
//
//    vector<int> rec;
//    rec.push_back(11);
//    rec.push_back(22);
//    rec.push_back(33);
//
//
//    insert_by_first_fit(rec);
//}
