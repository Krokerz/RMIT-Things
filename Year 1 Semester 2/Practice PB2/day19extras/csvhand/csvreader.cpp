#include "csvreader.h"

bool CSVReader::readCSV(std::string filename) {
    std::ifstream Fin;
    std::string temp;

    Fin.open(filename);

    if (!Fin) {
        return false;
    }

    while (getline(Fin, temp)) {
        std::vector<std::string> vect;
        std::string str = "";

        for (unsigned int i = 0; i < temp.size(); i++) {
            if (temp.at(i) == ',') {
                vect.push_back(str);
                str = "";
                continue;
            }

            str += temp.at(i);
        }

        vect.push_back(str);

        content.push_back(vect);
    }

    Fin.close();

    return true;
}

unsigned int CSVReader::getRowAmount() {
    return content.size();
}

unsigned int CSVReader::getColAmount() {
    return content.at(0).size();
}

std::vector<std::string> CSVReader::getRow(std::string id) {
    std::vector<std::string> out(content.at(0).size(), "OUTOFBOUNDS");

    for (unsigned int i = 1; i < content.size(); i++) {
        if (content.at(i).at(0) == id) {
            out = content.at(i);
            break;
        }
    }

    return out;
}

std::vector<std::string> CSVReader::getColumn(std::string id) {
    std::vector<std::string> out(content.size(), "OUTOFBOUNDS");

    for (unsigned int i = 0; i < content.size(); i++) {
        if (content.at(0).at(i) == id) {
            for (unsigned int j = 0; j < content.size(); j++) {
                out.at(j) = content.at(j).at(i);
            }

            break;
        }
    }

    return out;
}

bool CSVReader::setValue(std::string row, std::string column, std::string newData) {
    for (char i : row) {
        if (!isdigit(i)) {
            return false;
        }
    }

    for (char i : column) {
        if (!isdigit(i)) {
            return false;
        }
    }

    int r = stoi(row);
    int c = stoi(column);

    if ((content.size() <= r) || (content.at(0).size() <= c)) {
        return false;
    }

    content.at(r).at(c) = newData;

    return true;
}

bool CSVReader::saveToCSV(std::string filename) {
    std::ofstream Fout;

    Fout.open(filename + ".csv");

    if (!Fout) {
        return false;
    }

    for (std::vector<std::string> i : content) {
        Fout << i.at(0);

        for (unsigned int j = 1; j < i.size(); j++) {
            Fout << ',' << i.at(j);
        }

        Fout << std::endl;
    }

    return true;
}

std::ostream& operator<<(std::ostream &out, CSVReader &csvr) {
    for (std::vector<std::string> i : csvr.content) {
        out << i.at(0);

        for (unsigned int j = 1; j < i.size(); j++) {
            out << ',' << i.at(j);
        }

        out << std::endl;
    }

    return out;
}

std::istream& operator>>(std::istream &in, CSVReader &csvr) {
    std::string temp;

    while (in >> temp) {
        std::vector<std::string> vect;
        std::string str = "";

        for (unsigned int i = 0; i < temp.size(); i++) {
            if (temp.at(i) == ',') {
                vect.push_back(str);
                str = "";
                continue;
            }

            str += temp.at(i);
        }

        vect.push_back(str);

        csvr.content.push_back(vect);
    }

    return in;
}