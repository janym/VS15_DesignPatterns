#include <iostream>
using namespace std;

class A {
public:
	virtual void do_it() {
		cout << "A";
	}
};

class A_X : public A {
public:
	void do_it() {
		A::do_it();
		A_X::do_X;
	}
private:
	void do_X() {
		cout << "X";
	}
};

class A_Y : public A {
public:
	void do_it() {
		A::do_it();
		A_Y::do_Y;
	}
protected:
	void do_Y() {
		cout << "Y";
	}
};

class A_Z : public A {
public:
	void do_it() {
		A::do_it();
		do_Z();
	}
protected:
	void do_Z() {
		cout << "Z";
	}
};

class A_XY : public A_X, public A_Y {
public:
	void do_it() {
		A_X::do_it();
		A_Y::do_it();
	}
};

class A_XYZ : public A_X, public A_Y, public A_Z {
public:
	void do_it() {
		A_X::do_X();
		A_Y::do_Y();
		A_Z::do_Z();
	}
};