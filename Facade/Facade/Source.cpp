#include <iostream>	
using namespace std;

class MisDepartment {
public:
	void submitNetworkRequest() {
		_state = 0;
	}
	bool checkOnStatus() {
		_state++;
		if (_state == Complete)
			return 1;
		return 0;
	}
private:
	enum States {
		Received, DenyAllKnowledge, ReferClientToFacilities,
		FacilitiesHasNotSentPaperwork, ElectricianIsNotDone,
		ElectricianDidItWrong, DispatchTechnician, SignedOff, DoesNotWork,
		FixElectriciansWiring, Complete
	};
	int _state;
};

class ElectricianUnion {
public:
	void submitNetworkRequest() {
		_state = 0;
	}
	bool checkOnStatus() {
		_state++;
		if (_state == Complete)
			return 1;
		return 0;
	}
private:
	enum States {
		Received, DenyAllKnowledge, ReferClientToFacilities,
		FacilitiesHasNotSentPaperwork, ElectricianIsNotDone,
		ElectricianDidItWrong, DispatchTechnician, SignedOff, DoesNotWork,
		FixElectriciansWiring, Complete
	};
	int _state;
};

class FacilitiesDepartment {
public:
	void submitNetworkRequest() {
		_state = 0;
	}
	bool checkOnStatus() {
		_state++;
		if (_state == Complete)
			return 1;
		return 0;
	}
private:
	enum States {
		Received, DenyAllKnowledge, ReferClientToFacilities,
		FacilitiesHasNotSentPaperwork, ElectricianIsNotDone,
		ElectricianDidItWrong, DispatchTechnician, SignedOff, DoesNotWork,
		FixElectriciansWiring, Complete
	};
	int _state;
};

class FacilitiesFacade {
public:
	FacilitiesFacade() {
		_count = 0;
	}
	void submitNetworkRequest() {
		_state = 0;
	}
	bool checkOnStatus() {
		_count++;
		if (_state == Received) {
			_state++;
			_engineer.submitNetworkRequest();
			cout << "submitting to Facilities - " << _count << " phone calls so far" << endl;
		}
		else if (_state == SubmitToEngineer) {
			if (_engineer.checkOnStatus()) {
				_state++;
				_electrician.submitNetworkRequest();
				cout << "submitting to Electrician - " << _count << " phone calls so far" << endl;
			}
		}
		else if (_state == SubmitToElectrician) {
			if (_electrician.checkOnStatus()) {
				_state++;
				_technician.submitNetworkRequest();
				cout << "submited to MIS - " << _count << " phone calls so far" << endl;
			}
		}
		else if (_state == SubmitToTechnician) {
			if (_technician.checkOnStatus())
				return 1;
		}
		return 0;
	}
	int getNumberOfCalls() {
		return _count;
	}
private:
	enum States {
		Received, SubmitToEngineer, SubmitToElectrician, SubmitToTechnician
	};
	int _state;
	int _count;
	FacilitiesDepartment _engineer;
	ElectricianUnion _electrician;
	MisDepartment _technician;
};

int main() {
	FacilitiesFacade facilities;
	facilities.submitNetworkRequest();
	while (!facilities.checkOnStatus())
		;
	cout << "job completed after only " << facilities.getNumberOfCalls() << " phone calls" << endl;
	system("pause");
}