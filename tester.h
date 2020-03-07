//
// Created by daniele lubrano on 06/03/2020.
//

#ifndef PROGETTO_ASD_PROBLEMA_1_TESTER_H
#define PROGETTO_ASD_PROBLEMA_1_TESTER_H
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;


class tester {
    string random_string( size_t length )
    {
        auto randchar = []() -> char
        {
            const char charset[] =
                    "0123456789"
                    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                    "abcdefghijklmnopqrstuvwxyz";
            const size_t max_index = (sizeof(charset) - 1);
            return charset[ rand() % max_index ];
        };
        std::string str(length,0);
        std::generate_n( str.begin(), length, randchar );
        return str;
    }

public:

    void create(){
        srand(time(NULL));
        int b = rand() % 9000;
        int t = rand() % 9000+1000;
        int c=0;

        fstream file;
        file.open("../tester.txt",std::ofstream::out | std::ofstream::trunc);

        while(c<t){
            b = rand() % 2000;
            file<<b<<","<<this->random_string(10)<<endl;
            c++;
        }

        file.close();

    }


};


#endif //PROGETTO_ASD_PROBLEMA_1_TESTER_H
