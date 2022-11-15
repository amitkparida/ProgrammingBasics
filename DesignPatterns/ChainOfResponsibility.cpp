
// https://www.youtube.com/watch?v=2Vh34iOzrt4&list=PLJhxHp6j1l-8_kjEL2hVJDs0_4eJbHtWH&index=8

// https://www.youtube.com/watch?v=uIDfCzAAU6c

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