#include <iostream>
#include <vector>
#include <string>

int main() {
   int num_strings;
   std::vector<std::string> strVector;
   std::vector<std::string *> ptrVector;
   
   std::cin >> num_strings;
   
   for (int i = 0; i < num_strings; i++) {
      std::string temp;
      std::cin >> temp;
      
      std::string *str = new std::string(temp);
      
      strVector.push_back(temp);
      
      std::cout << strVector.at(i) << ": " << &strVector.at(i) << std::endl;
      std::cout << "str: " << str << " | " << *str << std::endl;
      std::cout << std::endl;
      
      ptrVector.push_back(&strVector.at(i)); // Doesn't work
      // ptrVector.push_back(str); // Works
   }
   
   std::cout << std::endl;
   
   std::cout << "Address and Value in strVector:" << std::endl;
   for (int i = 0; i < num_strings; i++) {
      std::cout << strVector.at(i) << ": " << &strVector.at(i) << std::endl;
   }
   
   std::cout << std::endl;
   
   // Pointer assigning that works
   // for (int i = 0; i < num_strings; i++) {
   //    ptrVector.push_back(&strVector.at(i));
   // }
   
   std::cout << "Address in ptrVector:" << std::endl;
   for (std::string *i : ptrVector) {
      std::cout << i << std::endl;
   }
   
   return EXIT_SUCCESS;
}