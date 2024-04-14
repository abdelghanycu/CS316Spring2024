//#include <bits/stdc++.h>
//using namespace std;
//
//vector<vector<int> > vec;
//
//int main(){
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
//    int delimiter = 999999;
//
//    fstream file{"D:\\Projects\\0Test\\0c++\\CS316\\section7_g2\\data.dat", ios::in | ios::out | ios::binary};
//
//    for(int i = 0; i < vec.size(); i++) {
//        int sz = vec[i].size();
//        file.write(reinterpret_cast<const char *>(&sz), sizeof(int));
//        for(int j = 0; j < vec[i].size(); j++) {
//            file.write(reinterpret_cast<const char *>(&vec[i][j]), sizeof(int));
//        }
//    }
//
//    file.close();
//}