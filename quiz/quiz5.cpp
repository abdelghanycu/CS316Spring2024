#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > all_data;
int delimiter = 555;

void load_file() {
    all_data.clear();
    fstream data_file{"data.dat", ios::in | ios::out | ios::binary};
    int val;
    vector<int> vec;
    while(!data_file.eof()) {
        data_file.read(reinterpret_cast<char *>(&val), sizeof(int));
        if(val == delimiter) {
            all_data.push_back(vec);
            vec.clear();
        }else {
            vec.push_back(val);
        }
    }
    data_file.close();
}

// Group 1 Question 1
void max_element() {

    load_file();

    fstream output_file{"output_max_element.dat", ios::in | ios::out | ios::binary};

    for(int i = 0; i < all_data.size(); i++) {
        int max_element = all_data[i][0];
        for(int j = 1; j < all_data[i].size(); j++) {
            max_element = max(max_element, all_data[i][j]);
        }
        output_file.write(reinterpret_cast<const char *>(&max_element), sizeof(int));
    }

    output_file.close();
}

// Group 1 Question 2
void file_with_size_prefixed() {
    load_file();

    fstream new_file{"new_file_size_prefixed.dat", ios::in | ios::out | ios::binary};

    for(int i = 0; i < all_data.size(); i++) {
        int sz = all_data[i].size();
        new_file.write(reinterpret_cast<const char *>(&sz), sizeof(int));
        for(int j = 1; j < all_data[i].size(); j++) {
            new_file.write(reinterpret_cast<const char *>(&all_data[i][j]), sizeof(int));
        }
    }

    new_file.close();
}

// Group 2 Question 1
void sets_size() {

    load_file();

    fstream output_file{"sets_size.dat", ios::in | ios::out | ios::binary};

    for(int i = 0; i < all_data.size(); i++) {
        int sz = all_data[i].size();
        output_file.write(reinterpret_cast<const char *>(&sz), sizeof(int));
    }

    output_file.close();
}

// Group 2 Question 2
void fixed_file() {
    load_file();

    fstream new_file{"new_fixed_file.dat", ios::in | ios::out | ios::binary};

    for(int i = 0; i < all_data.size(); i++) {
        for(int j = 0; j < all_data[i].size(); j++) {
            new_file.write(reinterpret_cast<const char *>(&all_data[i][j]), sizeof(int));
        }
        int remaining_elements = 10 - all_data[i].size();
        int value = -1;
        for(int j = 0; j < remaining_elements; j++) {
            new_file.write(reinterpret_cast<const char *>(&value), sizeof(int));
        }
    }

    new_file.close();
}