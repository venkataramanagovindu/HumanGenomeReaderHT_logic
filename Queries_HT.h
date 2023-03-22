
#include <string>
using namespace std;

class Queries_HT
{
	private:
		char* genomeArray;
		long long int totalGenomeLength = 0;
		long long int m = 0;

	public:
		struct Node {
			string data;
			Node *Next;
		};

		Node** HashTable;	
		Queries_HT(int size);
		long long int getRadixHash(string key);
		void readFragments(string fragmentFilePath);
		void readHumanGenomes(string genomeFilePath);
		void insert(string key);
};

 