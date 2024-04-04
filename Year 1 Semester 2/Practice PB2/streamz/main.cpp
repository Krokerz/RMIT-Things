#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>

double calc_mean(std::vector<double>);
double calc_stddev(std::vector<double>, double);

int main() {
    std::ifstream Fin;
    std::ofstream Fout;
    std::string ifilename;
    std::string ofilename;
    std::string input;

    std::cout << '\n' << "Please insert input filename (e! to exit): ";
    std::cin >> ifilename;

    if (ifilename == "e!") {
        std::cout << "Exited" << std::endl;
        return EXIT_SUCCESS;
    }

    ifilename += ".input";

    Fin.open(ifilename);

    if (!Fin) {
        std::cout << "Somethings wrong with the input file bruh" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << '\n' << "Please insert output filename (e! to exit): ";
    std::cin >> ofilename;

    if (ofilename == "e!") {
        std::cout << "Exited" << std::endl;
        return EXIT_SUCCESS;
    }

    ofilename += ".txt";

    Fout.open(ofilename);

    std::cout << std::endl;

    if (ifilename == "q1.input") {
        int row = 0;
        
        while (getline(Fin, input)) {
            std::istringstream iss(input);

            std::vector<double> temp;
            double temp2;

            while (iss >> temp2) {
                temp.push_back(temp2);
            }

            Fout << row << ": " << calc_mean(temp) << " +- " << calc_stddev(temp, calc_mean(temp)) << std::endl;

            row++;
        }
    }
    else {
        std::vector<std::vector<std::string>> out;

        while (getline(Fin, input)) {
            std::istringstream iss(input);

            std::vector<std::string> temp;
            std::string temp2;

            while (iss >> temp2) {
                if (temp2.find(",") != std::string::npos) {
                    temp2.pop_back();
                }

                temp.push_back(temp2);
            }

            out.push_back(temp);
        }

        for (unsigned int i = 1; i < out.size(); i++) {
            std::vector<double> tempVec;

            for (unsigned int j = 1; j < out.at(i).size(); j++) {
                tempVec.push_back(std::stod(out.at(j).at(i)));
            }

            Fout << out.at(0).at(i) << ": " << calc_mean(tempVec) << " +- " << calc_stddev(tempVec, calc_mean(tempVec)) << std::endl;
        }
    }

    Fin.close();
    Fout.close();
}

double calc_mean(std::vector<double> data) {
    double mean = 0.0;
    double sum = 0.0;
    int num = 0;

    for (auto n : data) {
        sum += n;
        num ++;
    }

    if (num > 0) { mean = sum/num; }

    return mean;
}

double calc_stddev(std::vector<double> data, double mean) {
    double stddev = 0.0;
    double sum = 0.0;
    int num = 0;

    for (auto n : data) {
        sum += (n-mean)*(n-mean);
        num ++;
    }

    if (num > 0) { stddev = sqrt(sum/num); }

    return stddev;
}