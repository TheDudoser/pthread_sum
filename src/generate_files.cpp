#include <iostream>
#include <fstream>
#include <sstream>
#include "generate_files.h"
#include "pthreads_summator_lib.h"

void populateFile(std::string name_file, int seed) {
    srand(seed);
    std::ofstream myfile;
    std::string line;
    myfile.open (name_file);
    for(int index = 0; index < 500; index++) {
        for (int i = 0; i < 500; ++i) {
            myfile << (rand() % 1000) << ' ';
        }
        myfile << std::endl;
    }
    myfile.close();
}

void create_files(std::stringstream &ss) {
    srand(time(NULL));
    int seed[N];
    for (int i = 0; i < 10; ++i) {
        seed[i] = rand() & 10000;
    }
    for (int i = 1; i <= 10; i++) {
        ss << "..\\Files\\" << i << ".txt";
        populateFile(ss.str(), seed[i]);
        ss.str(std::string());
    }
}

