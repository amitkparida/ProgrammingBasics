
// Chain of Responsibility:
// 1. Used when there are interdependent modules and each of them performs a specific task or part of some task.
// 2. For such cases, a chain of modules is createdand each module knows the next module in chain.
// 3. If the request cannot be performed by one module then it passes the control to next module.
// 4. This keeps going on till a correct handler is found to handle the request.


// EXAMPLE: (ATM)
// https://www.youtube.com/watch?v=uIDfCzAAU6c
// In an ATM, we have 500 Rs bills, 100 Rs bills, 2000 Rs currency bill, they all are placed in different slots.
// 
// If someone puts a request of 500 Rs bill, then ATM checks the slots one by oneand if one module is not to dispense for 500, 
// then it passes to next module to let that module check if he can fulfill the requestand so onand ultimately at 500 slot, 
// it stopsand that module performs the real processing(i.e.to dispense the cash).

#include<iostream>
using namespace std;

#define CASH_DISPENSE	1
#define INVALID_REQUEST	0

#define BILL_500		500
#define BILL_1000		1000
#define BILL_2000		2000

class ATMModule {
protected:
	int m_nReqType;
	ATMModule* pNext;

public:
	ATMModule(int nReqType) {
		m_nReqType = nReqType;
	}

	void SetNextSlot(ATMModule* pNext)
	{
		this->pNext = pNext;
	}

	virtual int Run(int nCurrency) = 0;
};

class Slot_500 :public ATMModule {
public:
	Slot_500() : ATMModule(BILL_500) {
		pNext = NULL;
	}

	int Run(int nCurrency) override {
		if (m_nReqType == nCurrency) {
			cout << "Slot_500 is the right slot" << endl;
			return CASH_DISPENSE;
		}
		else {
			cout << "Slot_500 is not the right slot. Moving to next Slot_1000." << endl;
			if (pNext) {
				return pNext->Run(nCurrency);
			}
			else {
				cout << "Invalid Request." << endl;
				return INVALID_REQUEST;
			}
		}
	}
};

class Slot_1000 :public ATMModule {
public:
	Slot_1000() : ATMModule(BILL_1000) {
		pNext = NULL;
	}

	int Run(int nCurrency) override {
		if (m_nReqType == nCurrency) {
			cout << "Slot_1000 is the right slot." << endl;
			return CASH_DISPENSE;
		}
		else {
			cout << "Slot_1000 is not the right slot. Moving to next Slot_2000." << endl;
			if (pNext) {
				return pNext->Run(nCurrency);
			}
			else {
				cout << "Invalid Request." << endl;
				return INVALID_REQUEST;
			}
		}
	}
};

class Slot_2000 :public ATMModule {
public:
	Slot_2000() : ATMModule(BILL_2000) {
		pNext = NULL;
	}

	int Run(int nCurrency) override {
		if (m_nReqType == nCurrency) {
			cout << "Slot_2000 is the right slot." << endl;
			return CASH_DISPENSE;
		}
		else {
			cout << "Slot_2000 is not the right slot." << endl;
			if (pNext) {
				return pNext->Run(nCurrency);
			}
			else {
				cout << "Invalid Request." << endl;
				return INVALID_REQUEST;
			}
		}
	}
};

int main() {
	ATMModule* p1 = new Slot_500;
	ATMModule* p2 = new Slot_1000;
	ATMModule* p3 = new Slot_2000;

	p1->SetNextSlot(p2);
	p2->SetNextSlot(p3);

	p1->Run(3000);

	return 0;
}




// ==================================================================================


/*
// Another EXAMPLE: (Interview process)
// https://www.youtube.com/watch?v=2Vh34iOzrt4&list=PLJhxHp6j1l-8_kjEL2hVJDs0_4eJbHtWH&index=8

#include<iostream>
using namespace std;

class Candidate {
public:
	string qualification;		//BE, B.Tech, M.Tech etc.
	string technologyKnown;		//C#, .NET, C++
	string expertiseOnDomain;	//Beginner, Moderate, Expert
	int salaryExpectation;		//expected salary
	bool interviewQualified;

	Candidate(string qualificn, string technology, string domain, int salary, bool isQualified) :
		qualification(qualificn), 
		technologyKnown(technology), 
		expertiseOnDomain(domain), 
		salaryExpectation(salary), 
		interviewQualified(isQualified) {
	}
};

class IInterviewHandler {
public:
	IInterviewHandler* _next = nullptr;
	Candidate* _candidate = nullptr;
	virtual void ExecuteBefore() = 0;
	virtual void ExecuteAfter() = 0;
};

class ScreeningRound : public IInterviewHandler {
public:
	ScreeningRound(Candidate* candidate) {
		_candidate = candidate;
	}

	void ExecuteBefore() {
		if (_candidate->qualification == "MCA") {
			_candidate->interviewQualified = true;
			cout << "Screening Round qualified!" << endl;
		}
		else {
			_candidate->interviewQualified = false;
			cout << "Screening Round not qualified!" << endl;
		}
	}

	void ExecuteAfter() {
		if (_candidate->interviewQualified) {
			cout << "Submitting Screening ROund Feedback documents" << endl;
		}
	}
};

class TechnicalRound : public IInterviewHandler {
public:
	TechnicalRound(Candidate* candidate) {
		_candidate = candidate;
	}

	void ExecuteBefore() {
		if (_candidate->technologyKnown == "C++") {
			_candidate->interviewQualified = true;
			cout << "Technical Round qualified!" << endl;
		}
		else {
			_candidate->interviewQualified = false;
			cout << "Technical Round not qualified!" << endl;
		}
	}

	void ExecuteAfter() {
		if (_candidate->interviewQualified) {
			cout << "Submitting Technical Round Feedback documents" << endl;
		}
	}
};

class ManagerRound : public IInterviewHandler {
public:
	ManagerRound(Candidate* candidate) {
		_candidate = candidate;
	}

	void ExecuteBefore() {
		if (_candidate->expertiseOnDomain == "Expert") {
			_candidate->interviewQualified = true;
			cout << "Manager Round qualified!" << endl;
		}
		else {
			_candidate->interviewQualified = false;
			cout << "Manager Round not qualified!" << endl;
		}
	}

	void ExecuteAfter() {
		if (_candidate->interviewQualified) {
			cout << "Submitting Manager Round Feedback documents" << endl;
		}
	}
};

class HRRound : public IInterviewHandler {
public:
	HRRound(Candidate* candidate) {
		_candidate = candidate;
	}

	void ExecuteBefore() {
		if (_candidate->salaryExpectation <= 3000000) {
			_candidate->interviewQualified = true;
			cout << "HR Round qualified!" << endl;
		}
		else {
			_candidate->interviewQualified = false;
			cout << "HR Round not qualified!" << endl;
		}
	}

	void ExecuteAfter() {
		if (_candidate->interviewQualified) {
			cout << "Submitting HR Round Feedback documents" << endl;
		}
	}

};

class InterviewClass {
	IInterviewHandler* _rootHandler = nullptr;
	IInterviewHandler* _currentRound = nullptr;

	void Execute(IInterviewHandler* handler) {
		handler->ExecuteBefore();
		if (handler->_candidate->interviewQualified && handler->_next != nullptr) {
			Execute(handler->_next);
		}
		handler->ExecuteAfter();
	}

public:
	void RegisterInterviews(IInterviewHandler* handler) {
		if (_rootHandler == nullptr) {
			_rootHandler = handler;
			_currentRound = handler;
		}
		else {
			_currentRound->_next = handler;
			_currentRound = _currentRound->_next;
		}
	}

	void ProceedWithInterview() {
		Execute(_rootHandler);
	}
};

int main() {
	Candidate candidate{ "MCA", "C++", "Expert", 2500000, false };

	InterviewClass* hc = new InterviewClass;
	hc->RegisterInterviews(new ScreeningRound(&candidate));
	hc->RegisterInterviews(new TechnicalRound(&candidate));
	hc->RegisterInterviews(new ManagerRound(&candidate));
	hc->RegisterInterviews(new HRRound(&candidate));

	hc->ProceedWithInterview();
}
*/