#include <iostream>
#include <fstream>
using namespace std; 

void write_file(string name) {
    // Create and open a text file
    ofstream MyFile("name.txt");
    // Write to the file
    MyFile << "Hello\n";
    MyFile << name;
    // Close the file
    MyFile.close();
}

void read_file() {
    // Create a text string, which is used to output the text file
    string myText;
    // Read from the text file
    ifstream MyReadFile("name.txt");
    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {
        // Output the text from the file
        cout << myText << endl;
    }
    // Close the file
    MyReadFile.close(); 
}
int main() {
    string name;
    cout << "What is your name?" << endl;
    cin >> name;
    write_file(name);
    read_file();
} 