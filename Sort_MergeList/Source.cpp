#include <iostream>
#include <ctime>
using namespace std;
class Sort_MergeList {
	int *mas;//array values
	int *masL;//array keys
	int *nas;//for the sort_mergeList
	int n;//determinate
	int s, t, p, q;
public:
	Sort_MergeList(int *mas, int n) {
		this->n = n;
		this->mas = new int[n + 1];
		this->nas = new int[n];
		this->masL = new int[n + 2];
		for (int i = 0; i < n; i++) {
			this->mas[i + 1] = mas[i];
		}
		podgotovochka();
	}
	void podgotovochka() {
		*(masL + 0) = 1;
		*(masL + n - 1) = *(masL + n) = 0;
		*(masL + n + 1) = 2;
		for (int i = 1; i < n - 1; i++) {
			*(masL + i) = -(i + 2);
		}
	}
	int sort_goto() {
		goto l2;
	l3:	//L3
		if (*(mas + p) > *(mas + q)) {
			goto l6;
		}
		//L4
		if (*(masL + s) <= 0 && p <= 0) {
			*(masL + s) = p;
		}
		if (*(masL + s) <= 0 && p >= 0) {
			*(masL + s) = -1 * p;
		}
		if (*(masL + s) >= 0 && p <= 0) {
			*(masL + s) = -1 * p;
		}
		if (*(masL + s) >= 0 && p >= 0) {
			*(masL + s) = p;
		}
		s = p;
		p = *(masL + p);
		if (p > 0) {
			goto l3;
		}
		//L5
		*(masL + s) = q;
		s = t;
		do {
			t = q;
			q = *(masL + q);
		} while (q > 0);
		goto l8;
	l6:	//L6
		if (*(masL + s) <= 0 && q <= 0) {
			*(masL + s) = q;
		}
		if (*(masL + s) <= 0 && q >= 0) {
			*(masL + s) = -1 * q;
		}
		if (*(masL + s) >= 0 && q <= 0) {
			*(masL + s) = -1 * q;
		}
		if (*(masL + s) >= 0 && q >= 0) {
			*(masL + s) = q;
		}
		s = q;
		q = *(masL + q);
		if (q > 0) {
			goto l3;
		}
		//L7
		*(masL + s) = p;
		s = t;
		do {
			t = p;
			p = *(masL + p);
		} while (p > 0);
	l8:	//L8
		p = -1 * p;
		q = -1 * q;
		if (q == 0) {
			if (*(masL + s) <= 0 && p <= 0) {
				*(masL + s) = p;
			}
			if (*(masL + s) <= 0 && p >= 0) {
				*(masL + s) = -1 * p;
			}
			if (*(masL + s) >= 0 && p <= 0) {
				*(masL + s) = -1 * p;
			}
			if (*(masL + s) >= 0 && p >= 0) {
				*(masL + s) = p;
			}
			*(masL + t) = 0;
		}
		else {
			goto l3;
		}
	l2:	//L2
		s = 0;
		t = n + 1;
		p = *(masL + s);
		q = *(masL + t);
		//outputL(); cout << endl;
		if (q == 0) {
			return 0;
		}
		goto l3;
	}

	int sort() {
		int e = 2;
		int h = 0;
		int k;
		while (true) {
			//outputL(); cout << endl;
			k = 0;
			for (int i = 0; i < n; i++) {
				if (k>=0&&k<=n) {
					if (masL[k] > 0 && masL[k]<=n) {
						cout << mas[masL[k]] << " ";
					}
				}
				if (k>=0&& k<=n) {
					k = masL[k];
				}
			}
			cout << endl;
			switch (e) {
			case 3:	//L3
				if (*(mas + p) > *(mas + q)) {
					e = 6;
				}
				else {
					e = 4;
				}
				break;
			case 4:	//L4
				if (*(masL + s) <= 0 && p <= 0) {
					*(masL + s) = p;
				}
				if (*(masL + s) <= 0 && p >= 0) {
					*(masL + s) = -1 * p;
				}
				if (*(masL + s) >= 0 && p <= 0) {
					*(masL + s) = -1 * p;
				}
				if (*(masL + s) >= 0 && p >= 0) {
					*(masL + s) = p;
				}
				s = p;
				p = *(masL + p);
				if (p > 0) {
					e = 3;
				}
				else {
					e = 5;
				}
				break;
			case 5:	//L5
				*(masL + s) = q;
				s = t;
				do {
					t = q;
					q = *(masL + q);
				} while (q > 0);
				e = 8;
				break;
			case 6:	//L6
				if (*(masL + s) <= 0 && q <= 0) {
					*(masL + s) = q;
				}
				if (*(masL + s) <= 0 && q >= 0) {
					*(masL + s) = -1 * q;
				}
				if (*(masL + s) >= 0 && q <= 0) {
					*(masL + s) = -1 * q;
				}
				if (*(masL + s) >= 0 && q >= 0) {
					*(masL + s) = q;
				}
				s = q;
				q = *(masL + q);
				if (q > 0) {
					e = 3;
				}
				else {
					e = 7;
				}
				break;
			case 7://L7
				*(masL + s) = p;
				s = t;
				do {
					t = p;
					p = *(masL + p);
				} while (p > 0);
				e = 8;
				break;
			case 8:	//L8
				p = -1 * p;
				q = -1 * q;
				if (q == 0) {
					if (*(masL + s) <= 0 && p <= 0) {
						*(masL + s) = p;
					}
					if (*(masL + s) <= 0 && p >= 0) {
						*(masL + s) = -1 * p;
					}
					if (*(masL + s) >= 0 && p <= 0) {
						*(masL + s) = -1 * p;
					}
					if (*(masL + s) >= 0 && p >= 0) {
						*(masL + s) = p;
					}
					*(masL + t) = 0;
					e = 2;
				}
				else {
					e=3;
				}
				break;
			case 2:	//L2
				s = 0;
				t = n + 1;
				p = *(masL + s);
				q = *(masL + t);
				if (q == 0) {
					return 0;
				}
				else {
					e = 3;
				}
				break;
			}
		}
	
	}

	void sort_mergeList() {
		sort();
		int *mas1 = new int[n];
		for (int i = 0; i < n; i++) {
			mas1[i+1] = mas[i+1];
		}
		int h = 0;
		for (int i = 0; i < n; i++) {
			if (masL[h]!=0) {
				mas[i] = mas1[masL[h]];
			}
			h = masL[h];
		}
	}
	void output() {
		cout << "-\t";
		for (int i = 0; i < n; i++) {
			cout << mas[i+1] << "\t ";
		}
		cout << "-\t";
	}
	void output_sort() {
		cout << "-\t";
		for (int i = 0; i < n; i++) {
			cout << mas[i] << "\t ";
		}
		cout << "-\t";
	}
	void outputL() {
		for (int i = 0; i < n + 2; i++) {
			cout << *(masL + i) << "\t ";
		}
	}
	~Sort_MergeList() {
		delete[] mas; 
		delete[] masL;
		delete[] nas;
	}
};
int main(){
	setlocale(0, "");
	srand(unsigned int(time(0)));
	int *mas, n;
	cout << "Введите количество элементов: ";
	//n = 16;
	//int mas[16] = { 503,87,512,61,908,170,897,275,653,426,154,509,612,677,765,703 };
	cin >> n;
	mas = new int[n];
	for (int i = 0; i < n; i++) {
		mas[i] = rand();
	}
	Sort_MergeList array(mas,n);
	cout << "Вывод массива: " << endl;
	array.output(); cout << endl;
	//array.outputL(); cout << endl;
	array.sort_mergeList();
	cout << "\n\nВывод отсортированного массива: " << endl;
	array.output_sort(); cout << "\n\n\n\n";
	//array.outputL();
	system("pause");
	return 0;
}