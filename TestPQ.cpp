#include "DHeap.h"
#include <time.h>
#include "SkewHeap.h"
#include "Leftist.h"

//Insert limit elements of the file fin into heap.
void insertNext(PQ & pq, ifstream & fin, int limit = 0)
{
	if (limit == 0)
		limit = numeric_limits<int>::max();
	string word;
	int ct;
	while (!fin.eof() && pq.size < limit){
		fin >> word >> ct;
		pq.insert(ItemType(word, ct));
	}
}

int main()
{
	clock_t start = clock();
	int const DELETE_CT = 4;
	int const PRINTSIZE = 5;
	int const HOWMANY = 10;  // How many values to read from each file.  If HOWMANY = 0, read all values.
	// SkewHeap pq1("SkewHeap PQ1");
	// LeftistHeap pq1("Leftist PQ1");
	/*DHeap pq1("D Heap 1", 6000);
	DHeap pq2("D Heap 2", 6000);
	DHeap pq3("D Heap 3", 6000);
	DHeap pq4("D Heap 4", 6000);
	DHeap pq5("D Heap 5", 6000);
	DHeap pq6("D Heap 6", 6000);*/

	/*SkewHeap pq1("SkewHeap PQ1");
	SkewHeap pq2("SkewHeap PQ2");
	SkewHeap pq3("SkewHeap PQ3");
	SkewHeap pq4("SkewHeap PQ4");
	SkewHeap pq5("SkewHeap PQ5");
	SkewHeap pq6("SkewHeap PQ6");*/

	Leftist pq1("LeftistHeap PQ1");
	Leftist pq2("LeftistHeap PQ2");
	Leftist pq3("LeftistHeap PQ3");
	Leftist pq4("LeftistHeap PQ4");
	Leftist pq5("LeftistHeapPQ5");
	Leftist pq6("LeftistHeapPQ6");
	
	ifstream fin;
	fin.open("Prog5In.txt");
	assert(fin);
	insertNext(pq1, fin, HOWMANY);
	insertNext(pq2, fin, HOWMANY);
	insertNext(pq3, fin, HOWMANY);
	insertNext(pq4, fin, HOWMANY);
	insertNext(pq5, fin, HOWMANY);
	insertNext(pq6, fin);
	cout << pq1.toString(PRINTSIZE);
	cout << endl;
	ofstream fout;
	fout.open("prog5out.txt");
	cout << pq1.toString(PRINTSIZE);
	for (int ct = 0; ct < DELETE_CT && !pq1.isEmpty(); ct++){
		ItemType big = pq1.deleteMax();
		fout << " ** DELETED " << big.toString() << endl;
		cout << " ** DELETED " << big.toString() << endl;
		//cout << pq1.toString(PRINTSIZE);
	};
	for (int ct = 0; ct < DELETE_CT && !pq2.isEmpty(); ct++) {
		ItemType big = pq2.deleteMax();
		fout << " ** DELETED " << big.toString() << endl;
		cout << " ** DELETED " << big.toString() << endl;
	};
	cout << "Before merge \n" << pq1.toString(PRINTSIZE) << endl;
	fout << "Before merge \n" << pq1.toString(PRINTSIZE) << endl;
	cout << "Before merge \n" << pq2.toString(PRINTSIZE) << endl;
	fout << "Before merge \n" << pq2.toString(PRINTSIZE) << endl;
	pq1.merge(&pq2);
	cout << "After merge \n" << pq1.toString(PRINTSIZE) << endl;
	fout << "After merge \n" << pq1.toString(PRINTSIZE) << endl;
	cout << "After merge \n" << pq2.toString(PRINTSIZE) << endl;
	fout << "After merge \n" << pq2.toString(PRINTSIZE) << endl;
	pq3.merge(&pq4);
	cout << "After merge 3 and 4 \n" << pq3.toString(PRINTSIZE) << endl;
	pq5.merge(&pq6);
	cout << "After merge 5 and 6 \n" << pq5.toString(PRINTSIZE) << endl;
	pq1.merge(&pq3);
	cout << "After merge 1 and 3\n" << pq1.toString(PRINTSIZE) << endl;
	pq1.merge(&pq5);
	cout << "After merge 1 and 5\n" << pq1.toString(PRINTSIZE) << endl;
	clock_t time = clock() - start;
	cout << "Elapsed time = " << ((float)time) / CLOCKS_PER_SEC << endl;
	fout << "Elapsed time = " << ((float)time) / CLOCKS_PER_SEC << endl;
	fout.close();
	cin.get();
	return 0;
}


