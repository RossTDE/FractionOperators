#include <iostream>
#include "fraction.h"
using namespace std;

/*����� � ��� �����������*/
/*� ������ ��� � � ������������*/

int main() {
	fraction* one;
	int num, denum;

	cout << "Enter numerator and denomerator: ";
	cin >> num >> denum;

	while (true) {
		try {
			one = new fraction(num, denum);
		} catch (const char* exp) {
			cout << "Error: " << exp << endl;
			cin >> num >> denum;
			continue;
		}
		break;
	}

	return 0;
}