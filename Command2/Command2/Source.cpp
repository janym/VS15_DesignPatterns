#include <iostream>
#include <string>
using namespace std;

class Person;

class Command {
	Person *object;
	void(Person:: *method)();
public:
	Command(Person *obj = 0, void(Person:: *meth)() = 0) {
		object = obj;
		method = meth;
	}
	void execute() {
		(object->*method)();
	}
};

class Person {
	string name;
	Command cmd;
public:
	Person(string n, Command c) :cmd(c) {
		name = n;
	}
	void talk() {
		cout << name << " is talking" << endl;
		cmd.execute();
	}
	void passOn() {
		cout << name << " is passing on" << endl;
		cmd.execute();
	}
	void gossip() {
		cout << name << " is gossiping" << endl;
		cmd.execute();
	}
	void listen() {
		cout << name << " is listening" << endl;
	}
};

int main() {
	Person wilma("Wilma", Command());
	Person betty("Betty", Command(&wilma, &Person::listen));
	Person barney("Barney", Command(&betty, &Person::gossip));
	Person fred("Fred", Command(&barney, &Person::passOn));
	fred.talk();
	system("pause");
}