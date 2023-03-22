
#include <iostream>
#include <string.h>
#include <fstream>

#include "Queries_HT.h"

using namespace std;

Queries_HT::Queries_HT(int size) {
	HashTable = new Node*[size];
    m = size;

	for (long long index = 0; index < size; index++)
		HashTable[index] = NULL;
}

long long int Queries_HT::getRadixHash(string key) {
	int value = 0, base = 5;
    int queryFragmentSize = 16;
    long long int radix = 0;

	for (int i = 0; i < queryFragmentSize; i++) {
		switch (key[i]) {
		case 'A':
            value = 0;
			break;
		case 'C':
            value = 1;
			break;
		case 'G':
            value = 2;
			break;
		case 'T':
            value = 3;
			break;
		default:
            value = 4;
			break;
		}
		radix += value * pow(base, (queryFragmentSize - i - 1));
	}
	return radix % m;
}

void Queries_HT::readFragments(string fragmentFilePath) {
    long long int queriesLineCount = 0;
    string line;

    /* Time function returns the time since the
    Epoch(jan 1 1970). Returned time is in seconds. */
    time_t start, end;
    std::time(&start);
    std::ios_base::sync_with_stdio(false);

    /* Creating input filestream */
    ifstream file(fragmentFilePath);
    while (getline(file, line))
        queriesLineCount++;

    file.close();

    /* Creating input filestream */
    ifstream fin(fragmentFilePath);

    char c;

    int genomeQueryIdx = 0;
    for (int i = 0; i < queriesLineCount; i++)
    {
        getline(fin, line);
        if (i % 2 == 0)
            continue;

        long long int index = this->getRadixHash(line);



        if ( this->HashTable[index]->data.empty())
        {
            this->HashTable[index]->data = line;
        }
        else
        {
            Node* newNode = new Node;
            newNode->data = line;
            newNode->Next = this->HashTable[index];
            this->HashTable[index] = newNode;
        }

        //int j = 0;
        //for (; j < 32; j++) {
        //    this->genomeQueries[genomeQueryIdx][j] = line[j];
        //}
        //this->genomeQueries[genomeQueryIdx][j] = '\0';
        //genomeQueryIdx++;
    }

    time(&end);

    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    cout << "Time taken to read the queries file : " << fixed
        << time_taken;
    cout << " sec " << endl;

    cout << "Numbers of lines in the file : " << queriesLineCount << endl;
}

void Queries_HT::readHumanGenomes(string genomeFilePath) {
    // read file char by char
    char ch;
    fstream fin(genomeFilePath, fstream::in);
    char* headerCharArray;

    /* Time function returns the time since the
    Epoch(jan 1 1970). Returned time is in seconds. */
    time_t start, end;
    std::time(&start);
    std::ios_base::sync_with_stdio(false);

    // Calculating the size of the file
    fin.seekg(0, std::ios::end);
    long long size = fin.tellg();
    fin.seekg(0, std::ios::beg);

    // Dynamically allocating memory for the array
    genomeArray = new char[size];
    bool isHeader = false;
    long long int charArridx = 0;
    long long int headerCharidx = 0;
    //long long int genomeLength = 0;

    while (fin >> noskipws >> ch) {

        // 62 = >
        if (ch == 62) {
            isHeader = true;

            /*totalGenomeLength += genomeLength;
            genomeLength = 0;*/
        }

        if (isHeader) {
            if (ch == 10) {
                isHeader = false;
            }
        }
        else if (ch != 10)
        {
            genomeArray[charArridx++] = ch;
            totalGenomeLength++;
        }
    }
    fin.close();

    genomeArray[charArridx] = '\0';

    std::ios_base::sync_with_stdio(false);
    time(&end);

    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    cout << "Time taken to read the genome file : " << fixed
        << time_taken;
    cout << " sec " << endl;
}


