#pragma once
#include<iostream>
#include<iomanip>
using namespace std;

class TimeHMS {
	int hour, min, sec;
public:
	TimeHMS(int h, int m, int s) : hour(h), min(m), sec(s) {}
	TimeHMS(int d = 0) { convert(d); }
	~TimeHMS() {}
	void convert(int total) {
		hour = total / (60 * 60);
		total %= (60 * 60);
		min = total / 60;
		sec = total % 60;
	}

	TimeHMS operator + (TimeHMS t) {
		return TimeHMS((hour + t.hour) * 3600 + (min + t.min) * 60 + (sec + t.sec));
	}
	TimeHMS operator - (TimeHMS t) {
		return TimeHMS((hour - t.hour) * 3600+ (min - t.min) * 60+ (sec - t.sec));
	}
	bool operator == (TimeHMS t) {
		return bool(hour*3600 + min * 60 + sec == t.hour * 3600 + t.min * 60 + t.sec);
	}
	TimeHMS operator ++() {
		hour++;
		return *this;
	}
	TimeHMS operator --() {
		hour--;
		return *this;
	}
	TimeHMS operator ++(int) {
		sec++;
		return TimeHMS(hour * 3600 + min * 60 + sec - 1);
	}
	TimeHMS operator --(int) {
		sec--;
		return TimeHMS(hour * 3600 + min * 60 + sec + 1);
	}

	int totalsec() {
		return hour * 3600 + min * 60 + sec;
	}
	operator int() {
		return totalsec();
	}
	operator double() {
		return hour + min / 60.0 + sec / 3600.0;
	}

	int& operator[](int index) {
		if (index == 0)
			return hour;
		else if (index == 1)
			return min;
		else if (index == 2)
			return sec;
	}

	TimeHMS operator * (double N) {
		return TimeHMS((hour * 3600 * N) + (min * 60 * N) + sec * N);
	}

	friend TimeHMS operator * (double N, const TimeHMS& t) {
		return TimeHMS((t.hour * 3600 * N) + (t.min * 60 * N) + t.sec * N);
	}


	friend ostream& operator<< (ostream& os, const TimeHMS& t) {
		os << fixed << setfill('0') << setw(2) << t.hour << ":" << setw(2) << t.min << ":" << setw(2) << t.sec << endl;
		return os;
	}
	friend istream& operator >> (istream& is, TimeHMS& t) {
		int total;
		is >> total;
		t.convert(total);
		return is;
	}
};


int main(void) {
	TimeHMS t1(10000), t2, t3(11, 22, 33), t4(100), t5(100), t6(3660), t7(3666), t8, t9(1800+3600);

	cout << "t2 : ";
	cin >> t2; // 10
	cout << "t1+t2 : " << t1 + t2; // 1
	t8 = t1 + t2;
	cout << "t8 = t1 + t2 ==> " << t8 << endl;
	cout << "t1-t2 : " << t1 - t2; // 2

	if (t4 == t5) // 3
		cout << "t4 == t5 is true" << endl;
	else
		cout << "t4 == t5 is false" << endl;
	if (t1 == t5)
		cout << "t1 == t5 is true" << endl;
	else
		cout << "t1 == t5 is false" << endl;

	cout << "++t6(3660) : " << ++t6; // 4
	cout << "t6++ : " << t6++;
	cout << "t6 : " << t6;

	cout << "--t7(3666) : " << --t7; // 5
	cout << "t7-- : " << t7--;
	cout << "t7 : " << t7;

	cout << "t7[0] - hour : " << t7[0] << "  " << "t7[1] - min : " << t7[1] << "  " << "t7[2] - sec : " << t7[2] << endl; //6

	cout << "(int)t7 : " << (int)t7 << endl; // 7

	cout << "(double)t9(1800+3600) : " << (double)t9 << endl; // 8

	cout << "t7 * 2.0 : " << 2.0 * t7 << endl; // 9
	cout << "2.0 * t7 : " << t7 * 2.0 << endl;


	return 0;
}