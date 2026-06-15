// File Handling 
/*
    In C++, file handling is managed using the <fstream> library, which provides three main classes:

    ifstream: For reading from files (input).

    ofstream: For writing to files (output).

    fstream: For both reading and writing.
*/
/*
========================== Text Files & Writing Files ===============================
Text files store data as readable characters (like a standard .txt file). 
Writing to a text file is very similar to using 
std::cout, but instead of printing to the screen, you direct the data stream into a file using ofstream.
*/
/*
#include <iostream>
#include <fstream> // Required for file handling

int main() {
    // Create an output file stream object and open "example.txt"
    std::ofstream outFile("example.txt");

    // Check if the file opened successfully
    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return 1;
    }

    // Writing text to the file using the stream insertion operator (<<)
    outFile << "Hello, World!\n";
    outFile << "Welcome to C++ File Handling.\n";
    outFile << 42 << "\n"; // You can write numbers just like in cout

    // Close the file explicitly (good practice)
    outFile.close(); 

    std::cout << "Data successfully written to text file." << std::endl;
    return 0;
}
*/
/*
Explanation:

    std::ofstream outFile("example.txt");: This line creates the file example.txt in your project directory. If the file already exists, 
    this will overwrite its contents by default.

    outFile.is_open(): Always verify if the file was successfully created or opened (e.g., it might fail if you don't have write permissions).

    outFile.close(): While C++ automatically closes files when the object goes out of scope, explicitly closing it frees up system resources immediately.
*/

// ============================== Reading Files ========================================
/*
#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Create an input file stream object
    std::ifstream inFile("example.txt");

    if (!inFile.is_open()) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return 1;
    }

    std::string line;
    // std::getline reads the file line-by-line until it hits the end of the file (EOF)
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }

    inFile.close();
    return 0;
}
*/
/*
Explanation
std::ifstream inFile("example.txt");: Opens the file for reading. If the file doesn't exist, is_open() will return false.

std::getline(inFile, line): This function reads an entire line from inFile and stores it in the line string. 
The while loop automatically stops when it reaches the End-Of-File (EOF).
*/

// ================================= Binary Files ==========================================

/*
Unlike text files, binary files do not store data as human-readable text. Instead, they write the raw byte representation of the data exactly as it sits in the computer's memory (RAM). 
This makes them faster, more compact, and ideal for custom data structures, images, or audio.

To handle binary files, you must add the std::ios::binary flag when opening them, and use the .write() and .read() methods.
*/
/*
#include <iostream>
#include <fstream>

int main() {
    int writeData[3] = {10, 20, 30};
    
    // --- WRITING BINARY ---
    // Open file with binary flag
    std::ofstream outBin("data.bin", std::ios::binary);
    
    // .write() requires a char pointer (char*) and the size of data in bytes
    outBin.write(reinterpret_cast<char*>(writeData), sizeof(writeData));
    outBin.close();

    // --- READING BINARY ---
    int readData[3];
    std::ifstream inBin("data.bin", std::ios::binary);
    
    // .read() works similarly to .write()
    inBin.read(reinterpret_cast<char*>(readData), sizeof(readData));
    inBin.close();

    // Print the read data to verify
    std::cout << "Binary Data Read: " << readData[0] << ", " << readData[1] << ", " << readData[2] << std::endl;

    return 0;
}
*/
/*
Explanation
std::ios::binary: This flag tells the operating system not to translate special characters (like newline characters \n), preserving the exact byte structure.

reinterpret_cast<char*>: The .write() and .read() functions only understand raw bytes, so they expect a character pointer (char*). 
We use reinterpret_cast to force the compiler to treat our integer array pointer as a raw byte stream pointer.

sizeof(writeData): Specifies exactly how many bytes to transfer from memory to the disk.
*/


// ============================== Serialization Basics ==============================

// Serialization is the process of converting complex data objects (like a custom struct or class) into a format that can be easily stored (in a file) or transmitted over a network. 
// Deserialization is the reverse process—reconstructing the object from the stored data.

/*
#include <iostream>
#include <fstream>

// A custom structure representing a Player in a game
struct Player {
    int id;
    int score;
    double health;
};

int main() {
    // 1. Create a player object with some data
    Player player1 = {101, 1500, 98.5};

    // 2. SERIALIZATION: Save the object to a file
    std::ofstream outFile("player.dat", std::ios::binary);
    if (outFile.is_open()) {
        // Grab the raw memory address of player1 and write its entire size to disk
        outFile.write(reinterpret_cast<char*>(&player1), sizeof(Player));
        outFile.close();
        std::cout << "Player state serialized successfully.\n";
    }

    // 3. DESERIALIZATION: Load the object back from the file
    Player loadedPlayer; // Empty object to hold incoming data
    
    std::ifstream inFile("player.dat", std::ios::binary);
    if (inFile.is_open()) {
        // Read the saved bytes directly into the memory layout of loadedPlayer
        inFile.read(reinterpret_cast<char*>(&loadedPlayer), sizeof(Player));
        inFile.close();
        std::cout << "Player state deserialized successfully.\n";
    }

    // Verify the data was loaded correctly
    std::cout << "--- Loaded Player Stats ---\n";
    std::cout << "ID: " << loadedPlayer.id << "\n";
    std::cout << "Score: " << loadedPlayer.score << "\n";
    std::cout << "Health: " << loadedPlayer.health << "%\n";

    return 0;
}
*/

