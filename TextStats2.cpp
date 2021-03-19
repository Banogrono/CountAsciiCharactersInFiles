

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// contains character and number of
class DataRec {
public:

    char symbol{};
    unsigned int runLen{};
    long freq{};

    DataRec() = default;

    explicit DataRec(char symbol) {
        this->symbol = symbol;
        this->freq = 1;
        this->runLen = 1;
    }

    DataRec(char symbol, char freq) {
        this->symbol = symbol;
        this->freq = freq;
        this->runLen = 1;
    }

    bool operator==(const DataRec &dataRec) {
        return (dataRec.runLen == this->runLen) && (dataRec.symbol == this->symbol);
    }

    bool operator<(const DataRec &dataRec) {
        return static_cast<long>(dataRec.symbol) < static_cast<long>(this->symbol) &&
               static_cast<long>(dataRec.runLen) < static_cast<long>(this->runLen);
    }
};

// counts symbols
void count(char ch, char l_ch, vector<DataRec> &data) {
    for (auto &elem : data) {
        if (ch == elem.symbol) {
            if (l_ch == ch) {
                elem.runLen++;
            } else {
                elem.freq++;
            }
            break;
        }
    }
}

// prints symbols
void print_symbols(vector<DataRec> &data) {
    for (auto x : data) {
        if (x.freq == 0) continue;

        cout << "'" << x.symbol << "' occured " << x.freq << (x.freq == 1 ? " time.\n" : " times.\n");
    }
}

// saves to file
void save_to_file(const std::string &filename, vector<DataRec> &data) {
    std::fstream file;
    file.open(filename, std::ios::out);

    if (file.is_open()) {
        std::string c;
        for (auto elem : data) {
            if (elem.freq == 0) continue;

            c = elem.symbol;
            switch (c.at(0)) {
                case '\n':
                    c = "LF";
                    break;
                case '\t':
                    c = "TB";
                    break;
                case ' ':
                    c = "SP";
                    break;
                case '\r':
                    c = "CR";
                    break;
                default:
                    break;
            }
            file << "0x" << std::hex << std::uppercase << static_cast<int>(c.at(0)) <<
                 std::dec << "," << c << "," << elem.runLen << ":" << elem.freq << "\n";
        }
        file.close();
        std::cout << "Successfully saved to: " << filename << "!" << std::endl;
    } else
        printf("E: Could not open file.");
}

char *OPEN_FILE_NAME = "file.txt";    // DEFAULT NAME OF FILE TO OPEN
string SAVE_FILE_NAME = "output.csv"; // DEFAULT NAME OF FILE TO SAVE

int main(int argc, char *argv[]) {

    bool print_enable = false; // print symbol stats

    // parsing command line arguments

    try {
        if (argc != 1) {
            if (argc == 2) {
                print_enable = true;
            } else {
                if (argc == 3) {
                    OPEN_FILE_NAME = argv[1];
                    SAVE_FILE_NAME = argv[2];
                } else {
                    print_enable = true;
                    OPEN_FILE_NAME = argv[2];
                    SAVE_FILE_NAME = argv[3];
                }
            }
        }
    } catch (exception e) {
        cout << "E: Too many, too few or wrong order of arguments.";
    }

    // opening the file
    fstream my_file;
    my_file.open(OPEN_FILE_NAME, ios::in);
    if (!my_file) {
        cout << "File could not be open!\n";
        return -1;
    } else {
        cout << "File opened successfully!\n";
    }

    vector<DataRec> data;

    data.reserve(256); // making space for 256 ascii symbols

    // filling vector with ascii symbols
    for (int i = 0; i < 256; i++) {
        data.emplace_back((char) i, 0);
    }

    char ch; // newly read char
    char l_ch; // last read char

    // reading file
    while (my_file >> noskipws >> ch) {
        count(ch, l_ch, data);
        l_ch = ch;
    }

    my_file.close(); // close file after reading data

    if (print_enable) print_symbols(data); // prints stats if print_enable == true

    save_to_file(SAVE_FILE_NAME, data); // saves output to file

    return 0;
}
