#include <iostream>
#include <fstream>

class FileHandler {
public:
   FileHandler(const std::string& filename) : file(filename) {}
   
   ~FileHandler() { 
       if (file.is_open()) file.close(); 
       std::cout << ""File closed.\n""; 
   }

private:
   std::ofstream file;
};

int main() {
   FileHandler fh(""example.txt"");
   // File will be automatically closed when fh goes out of scope
   return 0;
}
