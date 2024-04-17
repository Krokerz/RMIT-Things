#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "csvreader.h"

std::ostream& operator<<(std::ostream &out, std::vector<std::string> &vect);

int main() {
    std::string filename;
    CSVReader csvr = CSVReader();

    std::cout << "Please insert the csv filename: ";

    getline(std::cin, filename);

    if (!csvr.readCSV(filename + ".csv")) {
        std::cout << "\noopsies, somethin went wrong lol" <<std::endl;
        return EXIT_FAILURE;
    }

    // getRow() test
    std::vector<std::string> getR0 = csvr.getRow("0");
    std::vector<std::string> getR1 = csvr.getRow("1");
    std::vector<std::string> getR2 = csvr.getRow("2");
    std::vector<std::string> getRpineapple = csvr.getRow("pineapple");
    std::vector<std::string> getR86128729 = csvr.getRow("86128729");
    std::vector<std::string> getRneg1 = csvr.getRow("-1");

    std::cout << "Get Row (0):" << '\n' << getR0 << '\n' << std::endl;
    std::cout << "Get Row (1):" << '\n' << getR1 << '\n' << std::endl;
    std::cout << "Get Row (2):" << '\n' << getR2 << '\n' << std::endl;
    std::cout << "Get Row (pineapple):" << '\n' << getRpineapple << '\n' << std::endl;
    std::cout << "Get Row (86128729):" << '\n' << getR86128729 << '\n' << std::endl;
    std::cout << "Get Row (-1):" << '\n' << getRneg1 << '\n' << std::endl;

    // getColumn() test
    std::vector<std::string> getCid = csvr.getColumn("id");
    std::vector<std::string> getCpotato = csvr.getColumn("potato");
    std::vector<std::string> getClemon = csvr.getColumn("lemon");
    std::vector<std::string> getCorange = csvr.getColumn("orange");
    std::vector<std::string> getCx3 = csvr.getColumn("x3");
    std::vector<std::string> getC86128729 = csvr.getColumn("86128729");
    std::vector<std::string> getCneg1 = csvr.getColumn("-1");

    std::cout << "Get Column (id):" << '\n' << getCid << '\n' << std::endl;
    std::cout << "Get Column (potato):" << '\n' << getCpotato << '\n' << std::endl;
    std::cout << "Get Column (lemon):" << '\n' << getClemon << '\n' << std::endl;
    std::cout << "Get Column (orange):" << '\n' << getCorange << '\n' << std::endl;
    std::cout << "Get Column (x3):" << '\n' << getCx3 << '\n' << std::endl;
    std::cout << "Get Column (86128729):" << '\n' << getC86128729 << '\n' << std::endl;
    std::cout << "Get Column (-1):" << '\n' << getCneg1 << '\n' << std::endl;

    // setValue() test
    std::string x;
    std::string y;
    std::string data;

    std::cout << "Insert index of x-axis:" << std::endl;
    getline(std::cin, x);

    std::cout << "Insert index of y-axis:" << std::endl;
    getline(std::cin, y);

    std::cout << "Insert the new data:" << std::endl;
    getline(std::cin, data);

    if (!csvr.setValue(x, y, data)) {
        std::cout << "woops, somethin went brokie :3" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "\nResult of Overriden Data:" << std::endl;
    std::cout << csvr << std::endl;

    // insert operator test
    std::cout << "Insert a new row:" << std::endl;
    getline(std::cin, data);

    int count = 0;

    for (char i : data) {
        if (i == ',') {
            count++;
        }
    }

    if (count != csvr.getColAmount() - 1) {
        std::cout << "*LOUD INCORRECT BUZZER*" << std::endl;
        return EXIT_FAILURE;
    }

    std::istringstream iss(data);

    iss >> csvr;

    std::cout << "\nWhat do you want to call the new csv file?" << std::endl;

    std::string newName;
    getline(std::cin, newName);

    if (!csvr.saveToCSV(newName)) {
        std::cout << "whoooooooppppss, u gotta do the entire thing again lmao gg xd" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "File has been created! :D" << std::endl;

    return EXIT_SUCCESS;
}

std::ostream& operator<<(std::ostream &out, std::vector<std::string> &vect) {
    out << vect.at(0);

    for (unsigned int i = 1; i < vect.size(); i++) {
        out << ',' << vect.at(i);
    }

    return out;
}