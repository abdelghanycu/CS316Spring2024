#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > vec;

int write_data() {

    int n, m;
    cin >> n;
    for (int k = 0; k < n; k++) {
        cin >> m;
        vector<int> rec(m);
        for (int i = 0; i < m; i++) {
            cin >> rec[i];
        }
        vec.push_back(rec);
    }

    fstream data_file{"D:\\Projects\\0Test\\0c++\\CS316\\section8_g2\\data.dat", ios::in | ios::out | ios::binary};
    fstream index_file{"D:\\Projects\\0Test\\0c++\\CS316\\section8_g2\\index.dat", ios::in | ios::out | ios::binary};

    int offset = 0, deleted = 0;
    for (int i = 0; i < vec.size(); i++) {
        int sz = vec[i].size();
        index_file.write(reinterpret_cast<const char *>(&offset), sizeof(int));
        index_file.write(reinterpret_cast<const char *>(&sz), sizeof(int));
        index_file.write(reinterpret_cast<const char *>(&deleted), sizeof(int));

        for (int j = 0; j < vec[i].size(); j++) {
            data_file.write(reinterpret_cast<const char *>(&vec[i][j]), sizeof(int));
        }
        offset += sz;
    }

    data_file.close();
    index_file.close();
}

void read_data() {
    fstream data_file{"D:\\Projects\\0Test\\0c++\\CS316\\section8_g2\\data.dat", ios::in | ios::out | ios::binary};
    fstream index_file{"D:\\Projects\\0Test\\0c++\\CS316\\section8_g2\\index.dat", ios::in | ios::out | ios::binary};

    vector<vector<int> > vec2;
    vector<int> rec;
    int offset, sz, deleted, val;

    while (!index_file.eof()) {
        index_file.read(reinterpret_cast<char *>(&offset), sizeof(int));
        index_file.read(reinterpret_cast<char *>(&sz), sizeof(int));
        index_file.read(reinterpret_cast<char *>(&deleted), sizeof(int));
        cout << offset << " " << sz << " " << deleted << endl;
        if (!deleted) {
            data_file.seekg(offset * sizeof(int));
            for (int i = 0; i < sz; i++) {
                data_file.read(reinterpret_cast<char *>(&val), sizeof(int));
                rec.push_back(val);
            }
            vec2.push_back(rec);
            rec.clear();
        }
    }

    data_file.close();
    index_file.close();

    for (int i = 0; i < vec2.size(); i++) {
        for (int j = 0; j < vec2[i].size(); j++) {
            cout << vec2[i][j] << " ";
        }
        cout << endl;
    }
}

void delete_index(int idx) {
    int deleted = 1;
    fstream index_file{"D:\\Projects\\0Test\\0c++\\CS316\\section8_g2\\index.dat", ios::in | ios::out | ios::binary};
    index_file.seekp((idx - 1) * (3 * sizeof(int)) + (2 * sizeof(int)));
    index_file.write(reinterpret_cast<const char *>(&deleted), sizeof(int));
    index_file.close();
}

int get_first_fit(int new_sz) {
    fstream index_file{"D:\\Projects\\0Test\\0c++\\CS316\\section8_g2\\index.dat", ios::in | ios::out | ios::binary};
    int offset, sz, deleted;
    bool replace = 0;
    int idx = 0;
    while (!index_file.eof()) {
        idx++;
        index_file.read(reinterpret_cast<char *>(&offset), sizeof(int));
        index_file.read(reinterpret_cast<char *>(&sz), sizeof(int));
        index_file.read(reinterpret_cast<char *>(&deleted), sizeof(int));

        if (deleted && new_sz <= sz) {

            replace = 1;
            deleted = 0;
            index_file.seekp((idx - 1) * (3 * sizeof(int)) + (1 * sizeof(int)));
            index_file.write(reinterpret_cast<const char *>(&new_sz), sizeof(int));
            index_file.write(reinterpret_cast<const char *>(&deleted), sizeof(int));
            break;
        }
    }
    if (replace) {
        return offset;
    } else {
        return offset + sz;
    }
    index_file.close();
}

void insert_first_fit(vector<int> &v) {
    int offset = get_first_fit(v.size());
    fstream data_file{"D:\\Projects\\0Test\\0c++\\CS316\\section8_g2\\data.dat", ios::in | ios::out | ios::binary};
    data_file.seekp(offset * sizeof(int));
    for (int j = 0; j < v.size(); j++) {
        data_file.write(reinterpret_cast<const char *>(&v[j]), sizeof(int));
    }
    data_file.close();
}

pair<int,int> get_best_fit_position(int new_sz){
    vector<pair<int,int> >v;
    fstream index_file{"D:\\Projects\\0Test\\0c++\\CS316\\section8_g2\\index.dat", ios::in | ios::out | ios::binary};
    int offset, sz, deleted;
    while (!index_file.eof()) {
        index_file.read(reinterpret_cast<char *>(&offset), sizeof(int));
        index_file.read(reinterpret_cast<char *>(&sz), sizeof(int));
        index_file.read(reinterpret_cast<char *>(&deleted), sizeof(int));

        if (deleted && new_sz <= sz) {
            v.push_back(make_pair(sz,offset));
        }
    }
    index_file.close();
    sort(v.begin(),v.end());
    if (v.size()){
        return v[0];
    }
    return make_pair(-1,-1);

}

int main() {
    write_data();
//    read_data();
//    cout << "*******************" << endl;
    delete_index(2);
//    read_data();
//    cout << "**************\n";
    vector<int> v;
    v.push_back(11);
    v.push_back(22);
    v.push_back(33);
    insert_first_fit(v);
    read_data();
}