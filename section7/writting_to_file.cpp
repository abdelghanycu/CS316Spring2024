//#include <bits/stdc++.h>
//using namespace std;
//
//vector<vector<int> > vec;
//
//int main(){
//
//    int delimiter = 99999;
//
//    int n, m;
//    cin >> n;
//    while(n--) {
//        cin >> m;
//        vector<int> rec(m);
//        for(int i = 0; i < m; i++) {
//            cin >> rec[i];
//        }
//        vec.push_back(rec);
//    }
//
//    fstream file_data{"D:\\Projects\\0Test\\0c++\\CS316\\section7\\data.dat", ios::in | ios::out | ios::binary};
//
//    for(int i = 0; i < vec.size(); i++) {
//        for(int j = 0; j < vec[i].size(); j++) {
//            file_data.write(reinterpret_cast<const char *>(&vec[i][j]), sizeof(int));
//        }
//        file_data.write(reinterpret_cast<const char *>(&delimiter), sizeof(int));
//    }
//}