#include <iostream>
#include <ctime>
#include <cstdlib>

int * x;
int comps;
void swap(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int randint(int a, int b) {
	return a + (rand() % (b - a + 1));
}

void quicksort(int a, int b) {
	if (a >= b) return;
	int p = randint(a,b); // pivot
	swap(x[a], x[p]);//what does this do???
	int m = a;
	int i;
	// in-place partition:
	for (i = a+1; i <= b; i++) {
		comps++;
		if (x[i] < x[a])
			swap(x[++m], x[i]);
	}
	swap(x[a],x[m]);
	quicksort(a, m-1);
	quicksort(m+1, b);
}
int qc(int n){
	if (n<=1) return 0;
	int p = randint(1,n);//pivot
	
	//if (n==1) return 1;
    
	 comps=(n-1)+qc(p-1)+qc(n-p);
	 return comps;

}
#define NN 1000

int main(int argc, char *argv[]) {
	srand(time(0));

	// change the following code
	
	x = new int[NN];

	for (int i=0; i<NN; ++i) {
		x[i] = rand() % NN;
	}
	
	qc(NN);
	for (int i=0; i<NN; ++i) {
		std::cout << x[i] << " ";
	}
	std::cout <<comps<< std::endl;

	delete[] x;
	return 0;
}