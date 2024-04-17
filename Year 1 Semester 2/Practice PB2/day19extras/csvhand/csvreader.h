#ifndef CSVREADER_H
#define CSVREADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class CSVReader {
    private:
        std::string filename;
        std::vector< std::vector<std::string> > content;
        
    public:
        bool readCSV(std::string filename);
        unsigned int getRowAmount();
        unsigned int getColAmount();
        std::vector<std::string> getRow(std::string id);
        std::vector<std::string> getColumn(std::string id);
        bool setValue(std::string row, std::string column, std::string newData);
        bool saveToCSV(std::string filename);

        friend std::ostream& operator<<(std::ostream &out, CSVReader &csvr);
        friend std::istream& operator>>(std::istream &in, CSVReader &csvr);
};

#endif