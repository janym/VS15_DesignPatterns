#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

class TimeImp {
public:
	TimeImp(int hr, int min) {
		hr_ = hr;
		min_ = min;
	}
	virtual void tell() {
		cout << "time is " << setw(2) << hr_ << ":" << min_ << endl;
	}
protected:
	int hr_, min_;
};

class CivilianTimeImp : public TimeImp {
public:
	CivilianTimeImp(int hr, int min, int pm) : TimeImp(hr, min) {
		if (pm)
			strcpy_s(whichM_, " PM");
		else
			strcpy_s(whichM_, " AM");
	}

	void tell() {
		cout << "time is " << hr_ << ":" << min_ << whichM_ << endl;
	}
protected:
	char whichM_[4];
};

class ZuluTimeImp : public TimeImp {
public:
	ZuluTimeImp(int hr, int min, int zone) : TimeImp(hr, min) {
		if (zone == 5)
			strcpy_s(zone_, " Eastern Standard Time");
		else if (zone == 6)
			strcpy_s(zone_, " Central Standard Time");
	}

	void tell() {
		cout << "time is " << setw(2) << hr_ << ":" << min_ << endl;
	}
protected:
	char zone_[30];
};

class Time {
public:
	Time() {}
	Time(int hr, int min) {
		imp_ = new TimeImp(hr, min);
	}
	virtual void tell() {
		imp_->tell();
	}
protected:
	TimeImp *imp_;
};

class CivilianTime : public Time {
public:
	CivilianTime(int hr, int min, int pm) {
		imp_ = new CivilianTimeImp(hr, min, pm);
	}
};

class ZuluTime : public Time {
public:
	ZuluTime(int hr, int min, int zone) {
		imp_ = new ZuluTimeImp(hr, min, zone);
	}
};

int main() {
	Time *times[3];
	times[0] = new Time(14, 30);
	times[1] = new CivilianTime(2, 30, 1);
	times[2] = new ZuluTime(14, 30, 5);
	for (int i = 0; i < 3; i++)
		times[i]->tell();
	system("pause");
}