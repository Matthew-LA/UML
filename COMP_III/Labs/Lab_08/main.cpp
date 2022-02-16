#include <iostream>
#include <string>

// using declarations
using std::ostream;
using std::cout;
using std::endl;
using std::string;

class PayKind { // base class - no member variables
public:
  void output(ostream& out) const { out << *this; }
  friend ostream& operator<< (ostream&, const PayKind&);
};

class EmployeeKind {
public:
  EmployeeKind() {}
};

class PartTime : public EmployeeKind {
public:
  PartTime() :_maxHours(0) {}
  PartTime(unsigned);
  void setMax(unsigned);
  unsigned getMax() const;
  
private:
  unsigned _maxHours;
};

class PerCourse : public PayKind {
private:
  unsigned _feePerCourse;
  
public:
  PerCourse() :_feePerCourse(0) {}
  explicit PerCourse(unsigned);
  unsigned getfee() const;
  void setfee(unsigned);
};

class Salaried : public PayKind { // derived class
public:
  // constructors/destructor
  Salaried() : _annualSalary(0) {}
  Salaried(unsigned salary) : _annualSalary(salary) {}
  ~Salaried() { cout << "Salaried destructor called\n"; }
  
  // accessor functions
  unsigned getSalary() const { return _annualSalary; }
  void output(ostream& out) const { out << *this; }
  friend ostream& operator<< (ostream&, const Salaried&);
  
private:
  unsigned _annualSalary;
};

class Hourly : public PayKind { // derived class
public:
  // constructors/destructor
  Hourly() : _hourlyRate(0) {}
  Hourly(unsigned hourlyRate) : _hourlyRate(hourlyRate) {}
  ~Hourly() { cout << "Hourly destructor called\n"; }
  
  // accessor functions
  unsigned getHourlyRate() const { return _hourlyRate; }
  void output(ostream& out) const { out << *this; }
  friend ostream& operator<< (ostream&, const Hourly&);

private:
  unsigned _hourlyRate;
};

ostream& operator<< (ostream& out, const PayKind& p) {
  out << "Paykind (no member variables)\n" << endl;
  return out;
}

ostream& operator<< (ostream& out, const Salaried& s) {
  out << "Salary:\t\t" << s.getSalary() << endl;
  return out;
}

ostream& operator<< (ostream& out, const Hourly& s) {
  out << "Hourly Rate:\t" << s.getHourlyRate() << endl;
  return out;
}


class UMLPerson { // base class
public:
  // constructors and destructor
  UMLPerson() : _firstName("NoName"), _lastName("NoName"), _address("NoAddress"), _IDNumber_(0) {}
  UMLPerson(string firstName, string lastName, string address, unsigned _IDNumber) :
    _firstName(firstName), _lastName(lastName), _address(address), _IDNumber_(_IDNumber) {}
  UMLPerson(const UMLPerson&); // copy constructor
  ~UMLPerson();
  
  // accessor functions
  string getFirstName() const { return _firstName; }
  string getLastName() const { return _lastName; }
  string getAddress() const { return _address; }
  unsigned get_IDNumber() const { return _IDNumber_; }
  
  void output(ostream& out) const { out << *this; }
  
  friend ostream& operator<< (ostream&, const UMLPerson&);
  
private:
  string _firstName;
  string _lastName;
  string _address;
  unsigned _IDNumber_;
};

class Student : public UMLPerson { // derived class
public:
  // constructors and destructor
  Student() : UMLPerson() { _GPA = 0.0; _smajor = "Undeclared"; _advisorName = "NoName"; }
  
  Student(string firstName, string lastName, string address, unsigned _IDNumber,
      double GPA, string smajor, string advisorName);
  
  Student(const Student&); // copy constructor
  
  ~Student();
  
  void output(ostream& out) const { out << *this; }

  // accessor functions
  double getGPA() const { return _GPA; }
  string getSmajor() const { return _smajor; }
  string getAdvisorName() const { return _advisorName; }
  
  friend ostream& operator<< (ostream&, const Student&);
  
private:
  double _GPA;
  string _smajor;
  string _advisorName;
};

class Undergrad : public Student { // derived class
public:
  // constructors and destructor
  Undergrad() : Student() { _classRank = "NoRank"; }
  
  Undergrad(string firstName, string lastName, string address, unsigned _IDNumber,
        double GPA, string smajor, string advisorName, string classRank);
  
  Undergrad(const Undergrad&); // copy constructor
  
  ~Undergrad();
  
  void output(ostream& out) const { out << *this; }
  
  // accessor functions
  string getClassRank() const { return _classRank; }
  
  friend ostream& operator<< (ostream&, const Undergrad&);
  
private:
  string _classRank; // freshman, sophomore, junior, or senior
};


class Grader : public Undergrad, public Hourly, public PartTime { // derived class
public:
  // constructors and destructor
  Grader() : Undergrad(), PartTime() { _classNumber = "NoClassNumber"; }
  
  Grader(string firstName, string lastName, string address, unsigned _IDNumber,
     double GPA, string smajor, string advisorName, string classRank,
     string classNumber, unsigned hourlyRate);
  
  Grader(const Grader&); // copy constructor
  
  ~Grader();

  void output(ostream& out) const { out << *this; }
  
  // accessor functions
  string getClassNumber() const { return _classNumber; }
  
  friend ostream& operator<< (ostream&, const Grader&);
  
private:
  string _classNumber; // e.g., COMP.2010
};


class Employee : public UMLPerson { // derived class
public:
  // constructors and destructor
  Employee() : UMLPerson() { _SSN = "NoSSN"; }
  
  Employee(string firstName, string lastName, string address, unsigned _IDNumber,
       string SSN);

  //        Employee(const Employee&); // copy constructor
  
  ~Employee() { cout << "Employee destructor called\n"; }
  
  void output(ostream& out) const { out << *this; }
  
  // accessor functions
  string getSSN() const { return _SSN; }
  
  friend ostream& operator<< (ostream&, const Employee&);
  
private:
  string _SSN;
};

class Faculty : public Employee { // derived class
public:
  // constructors and destructor
  Faculty() : Employee() { _department = "NoDepartment"; }

  Faculty(string firstName, string lastName, string address, unsigned _IDNumber,
      string SSN, string department);
  
  //        Faculty(const Faculty&); // copy constructor
  
  ~Faculty() { cout << "Faculty destructor called for " << getFirstName() + " " + getLastName() << endl; }
  
  void output(ostream& out) const { out << *this; }
  
  // accessor functions
  string getDepartment() const { return _department; }
  
  friend ostream& operator<< (ostream&, const Faculty&);
  
private:
  string _department;
};


class NTT : public Faculty, public Salaried { // derived class
public:
  // constructors and destructor
  NTT() : Faculty(), Salaried() { _rank = "NoRank"; }
  
  NTT(string firstName, string lastName, string address, unsigned _IDNumber,
      string SSN, string department, string rank, unsigned salary);
  
  //        NTT(const Faculty&); // copy constructor
  
  ~NTT() { cout << "NTT destructor called for " << getFirstName() + " " + getLastName() << endl; }
  
  void output(ostream& out) const { out << *this; }
  
  // accessor functions
  string getRank() const { return _rank; }
  
  friend ostream& operator<< (ostream&, const NTT&);
  
private:
  string _rank; // lecturer or senior lecturer
};

class Adjunct : public Faculty, public PerCourse, public PartTime {
public:
  Adjunct() :Faculty(), PerCourse(), PartTime(), _maxCourses(0) {}
  Adjunct(string, string, string, unsigned, string, string, unsigned, unsigned, unsigned);
  unsigned getAdj() const;
  void setAdj(unsigned);
  friend ostream& operator<< (ostream&, Adjunct&);
private:
  unsigned _maxCourses;
};

UMLPerson::UMLPerson(const UMLPerson& p) {
  // make an independent copy of any dynamic member variables of UMLPerson here
  _firstName = p._firstName;
  _lastName = p._lastName;
  _address = p._address;
  _IDNumber_ = p._IDNumber_;
  cout << "UMLPerson copy constructor called for \"" << _firstName << " " << _lastName << "\"\n";
}

UMLPerson::~UMLPerson() {
  // delete any dynamic data members for UMLPerson here
  cout << "UMLPerson destructor called for \"" << _firstName << " " << _lastName << "\"\n";
}

Student::Student(string firstName, string lastName, string address, unsigned _IDNumber,
         double GPA, string smajor, string advisorName)
  : UMLPerson(firstName, lastName, address, _IDNumber) {
  _GPA = GPA;
  _smajor = smajor;
  _advisorName = advisorName;
}

Student::Student(const Student& s) : UMLPerson(s) {
  // make an independent copy of any dynamic member variables of Student here
  _GPA = s._GPA;
  _smajor = s._smajor;
  _advisorName = s._advisorName;
  
  cout << "Student copy constructor called for \""
       << s.getFirstName() << " " << s.getLastName() << "\"\n";
}

Student::~Student() {
  // delete any dynamic data members for Student here
  cout << "Student destructor called for \"" << getFirstName() << " " << getLastName() << "\"\n";
}

Undergrad::Undergrad(string firstName, string lastName, string address, unsigned _IDNumber,
             double GPA, string smajor, string advisorName, string classRank)
  : Student(firstName, lastName, address, _IDNumber, GPA, smajor, advisorName) {
  _classRank = classRank;
}

Undergrad::Undergrad(const Undergrad& u) : Student(u) {
  // make an independent copy of any dynamic member variables of Student here
  _classRank = u._classRank;
  cout << "Undergrad copy constructor called for \""
       << u.getFirstName() << " " << u.getLastName() << "\"\n";
}

Undergrad::~Undergrad() {
  // delete any dynamic data members for Student here
  cout << "Undergrad destructor called for \"" << getFirstName() << " " << getLastName() << "\"\n";
}

Grader::Grader(string firstName, string lastName, string address, unsigned _IDNumber,
           double GPA, string smajor, string advisorName, string classRank,
           string classNumber, unsigned hourlyRate)
  : Undergrad(firstName, lastName, address, _IDNumber, GPA, smajor, advisorName, classRank),
    Hourly(hourlyRate) {
  _classNumber = classNumber;
    }

Grader::Grader(const Grader& g) : Undergrad(g), Hourly(g) {
  // make an independent copy of any dynamic member variables of Student here
  _classNumber = g._classNumber;
  
  cout << "Grader copy constructor called for \""
       << g.getFirstName() << " " << g.getLastName() << "\"\n";
}

Grader::~Grader() {
  // delete any dynamic data members for Student here
  cout << "Grader destructor called for \"" << getFirstName() << " " << getLastName() << "\"\n";
}

Employee::Employee(string firstName, string lastName, string address, unsigned _IDNumber,
           string SSN)
  : UMLPerson(firstName, lastName, address, _IDNumber)
{
  _SSN = SSN;
}

Faculty::Faculty(string firstName, string lastName, string address, unsigned _IDNumber,
         string SSN, string department)
  : Employee(firstName, lastName, address, _IDNumber, SSN)
{
  _department = department;
}

NTT::NTT(string firstName, string lastName, string address, unsigned _IDNumber,
     string SSN, string department, string rank, unsigned salary)
  : Faculty(firstName, lastName, address, _IDNumber, SSN, department), Salaried(salary)
{
  _rank = rank;
}

ostream& operator<< (ostream& out, const UMLPerson& p) {
  out << "First Name:\t" << p._firstName << endl
      << "Last Name:\t" << p._lastName << endl
      << "Address:\t" << p._address << endl
      << "ID Number:\t" << p._IDNumber_ << endl;
  
  return out;
}

ostream& operator<< (ostream& out, const Student& s) {
  s.UMLPerson::output(out); // display the UMLPerson variables
  
  out << "GPA:\t\t" << s.getGPA() << endl
      << "Major:\t\t" << s.getSmajor() << endl
      << "Advisor Name:\t" << s.getAdvisorName() << endl;
  
  return out;
}

ostream& operator<< (ostream& out, const Undergrad& u) {
  u.Student::output(out); // display the Student variables
  
  out << "Class Rank:\t" << u.getClassRank() << endl;
  
  return out;
}

ostream& operator<< (ostream& out, const Grader& u) {
  u.Undergrad::output(out); // display the Student variables
  
  out << "Class Number:\t" << u.getClassNumber() << endl;
  
  u.Hourly::output(out); // display the Hourly variables
  
  return out;
}

ostream& operator<< (ostream& out, const Employee& e) {
  e.UMLPerson::output(out); // display the UMLPerson variables
  
  out << "SSN:\t\t" << e.getSSN() << endl;
  
  return out;
}

ostream& operator<< (ostream& out, const Faculty& f) {
  f.Employee::output(out); // display the Employee variables
  
  out << "Department:\t" << f.getDepartment() << endl;
  
  return out;
}

ostream& operator<< (ostream& out, const NTT& n) {
  n.Faculty::output(out); // display the Faculty variables
  
  out << "Rank:\t\t" << n.getRank() << endl;
  
  n.Salaried::output(out); // display the Salary variables
  
  return out;
}

PerCourse::PerCourse(unsigned x) {
  _feePerCourse = x;
}

unsigned PerCourse::getfee() const {
  return _feePerCourse;
}

void PerCourse::setfee(unsigned y) {
  _feePerCourse = y;
}

PartTime::PartTime(unsigned x) :_maxHours(x) {}

void PartTime::setMax(unsigned y) {
  _maxHours = y;
}

unsigned PartTime::getMax() const {
    return _maxHours;
}

Adjunct::Adjunct(string fn, string ln, string add, unsigned id, string ssn, string dep, unsigned fee, unsigned hours, unsigned x): Faculty(fn, ln, add, id, ssn, dep), PerCourse(fee), PartTime(hours) {
  _maxCourses = x;
}
unsigned Adjunct::getAdj() const {
  return _maxCourses;
}
void Adjunct::setAdj(unsigned y) {
  _maxCourses = y;
}

ostream& operator<< (ostream& out, Adjunct& obj) {
  obj.Faculty::output(out);
  obj.PayKind::output(out);
  out << "Max Courses: " << obj._maxCourses << endl;
  return out;
}

int main(void) {
  Adjunct a;
  cout << "Adjunct():\n" << a << endl;
  UMLPerson p;
  cout << "UMLPerson():\n" << p << endl;
  
  Student s;
  cout << "Student():\n" << s << endl;
  
  Undergrad u;
  cout << "Undergrad():\n" << u << endl;
  
  Grader g;
  cout << "Grader():\n" << g << endl;
  
  Adjunct a2("Rutvik" , "Tarikere", "27 Peetson Road", 37263946, "000-00-0001", "Computer Science", 1040, 3, 5);
  cout << "Adjunct():\n" << a2 << endl;
  
  Undergrad s1("Sally", "Brown", "110 Canal Street", 12345678, 4.0, "CS", "Tom Wilkes", "senior");
  Undergrad s2("Jimmy", "Smith", "99 Canal Street", 87654321, 3.0, "CS", "Tom Wilkes", "freshman");
  
  cout << "Undergrad s1(Sally...):\n" << s1 << endl;
  cout << "Undergrad s2(Jimmy...):\n" << s2 << endl;
  
  Grader g1("John", "Doe", "89 Canal Street", 54329876, 3.5, "CS", "Tom Wilkes", "junior",
        "COMP.2010", 25.00);
  cout << "Grader g1(John...):\n" << g1 << endl;
  
  Grader g2(g1); // invoke copy constructor
  cout << "Grader g2(copy of g1 - John...):\n" << g2 << endl;
  
  NTT n1("Tom", "Wilkes", "Foo Street", 52901256, "123-45-6789", "Computer Science", "Assistant Teaching Professor", 12345);
  cout << "NTT Faculty n1(Tom...):\n" << n1 << endl;
  
  return 0;
}
