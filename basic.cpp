#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// contains character and number of
class DataRec {
public:

    char symbol;

    long freq;

    DataRec() = default;

    DataRec(char symbol) {
        this->symbol = symbol;
    }

    DataRec(char symbol, char freq) {
        this->symbol = symbol;
        this->freq = freq;
    }

};

void count(char s, vector<DataRec> &data) {
    for (int j = 0; j < data.size(); ++j) {

        if (s == data.at(j).symbol) {
            data.at(j).freq++;
            break;
        }
    }
}

void printSymbols(vector<DataRec> &data) {
    for (auto x : data) {
        if (x.freq == 0) continue;

        cout << "'" << x.symbol << "' occured " << x.freq << (x.freq == 1 ? " time.\n" : " times.\n");
    }
}

const char *const FILE_NAME = R"(C:\Users\V\TextStats\plik.txt)";

int main() {

    // open file
    fstream my_file;
    my_file.open(FILE_NAME, ios::in);
    if (!my_file) {
        cout << "File could not be open!\n";
        return -1;
    } else {
        cout << "File opened successfully!\n";
    }

    vector<DataRec> data;

    data.reserve(256);

    // filling vector with ascii symbols
    for (int i = 0; i < 256; i++) {
        data.emplace_back((char) i, 0);
    }

    char ch;
    while (my_file >> noskipws >> ch) {
        count(ch, data);
    }

    my_file.close(); // close file after reading data

    printSymbols(data);

    return 0;
}
