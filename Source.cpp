#include <iostream>
using namespace std;

int main1(){
	int i=880;
	int j=121;
    while (j != 0) {
		int temp = i;
		i = j;
		j = temp%j;
		cout << i << ", " << j << endl;
	}
	cin.get();
	return 0;
}
