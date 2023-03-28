#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Queries_HT.h"

int main(int argc, const char* argv[])
{
    //char c = 'A';



    //Queries_HT* HT = new Queries_HT(50000);
    //string s1 = "TTCTATTCTACAACA\0", s2 = "TTCTATTCTACAACA\0";
    //cout << s1.compare(s2) << endl;
    //HT->readFragments("../human_reads_trimmed/human_reads_trimmed.fa");
    ////HT->readFragments("human_reads_trimmed_medium.fa");
    //HT->readHumanGenomes("human.txt");
    //HT->print();
    //if (c == 'A') {
    //    HT->search();
    //}
    //
    //return 0;





        if (argc < 5) {
            cout << "Please enter Queries file path, Genome file path, Hash Table Length and part to be executed" << endl;
            return 0;
        }

        string queriesFilePath = argv[1], genomeFilePath = argv[2];
        char* end;
        long long int count = strtoll(argv[3], &end, 10);
        char c = argv[4][0];

        Queries_HT* HT = new Queries_HT(count);
        string s1 = "TTCTATTCTACAACA\0", s2 = "TTCTATTCTACAACA\0";
        cout << s1.compare(s2) << endl;
        HT->readFragments(queriesFilePath);
        HT->readHumanGenomes(genomeFilePath);
        HT->print();

        
        if (c == 'B') {
            HT->search();
        }
        return 0;
}