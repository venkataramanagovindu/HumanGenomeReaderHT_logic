#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Queries_HT.h";

int main()
{
    std::cout << "Hello World! v\n";
    Queries_HT* HT = new Queries_HT(10);
    HT->readFragments("human_reads_trimmed_small.fa");
    HT->readHumanGenomes("human_genome_small.txt");
    return 0;
}