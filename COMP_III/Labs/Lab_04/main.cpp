#include <iostream>
#include <string>

using namespace std;


// ***** Add your Date class definition and driver program at the end of this file
// (at about line 107). *****

// The Month class provided below is a "helper" class for your Date class.
// Note that although both classes are defined in this single compilation unit (file),
// we are not nesting the Month class in the Date class or vice versa.

class Month {
    friend class Date;

    friend ostream& operator<< (ostream&, Month);

private:
    enum EMonth { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };

    Month() : _month(Jan) {} // default constructor
    Month(int im) : _month(static_cast<EMonth>(im)) {} // value constructor

    void setMonth(string m) { _month = StringToEMonth(m); } // mutator functions
    void setMonth(int im) { _month = static_cast<EMonth>(im); }

    /* Private helper member functions */
    EMonth StringToEMonth(string);
    int MonthToInt() { return static_cast<int>(_month); }
    string MonthToString();
    string MonthToString2();

    EMonth _month;
};

/* Definitions of helper member functions for class Month */

Month::EMonth Month::StringToEMonth(string m) {
    if (m == "Jan") return Jan;
    else if (m == "Feb") return Feb;
    else if (m == "Mar") return Mar;
    else if (m == "Apr") return Apr;
    else if (m == "May") return May;
    else if (m == "Jun") return Jun;
    else if (m == "Jul") return Jul;
    else if (m == "Aug") return Aug;
    else if (m == "Sep") return Sep;
    else if (m == "Oct") return Oct;
    else if (m == "Nov") return Nov;
    else if (m == "Dec") return Dec;
    else {
        cerr << "Month::StringToMonth: Invalid input month \"" << m << "\"\n";
        exit(1);
    }
}

string Month::MonthToString() {
    switch (_month) {
    case Jan: return "Jan";
    case Feb: return "Feb";
    case Mar: return "Mar";
    case Apr: return "Apr";
    case May: return "May";
    case Jun: return "Jun";
    case Jul: return "Jul";
    case Aug: return "Aug";
    case Sep: return "Sep";
    case Oct: return "Oct";
    case Nov: return "Nov";
    case Dec: return "Dec";
    default:
        cerr << "MonthToString: invalid input month \'" << _month << "\'\n";
        exit(1);
    }
}

string Month::MonthToString2() {
    switch (_month) {
    case Jan: return "January";
    case Feb: return "February";
    case Mar: return "March";
    case Apr: return "April";
    case May: return "May";
    case Jun: return "June";
    case Jul: return "July";
    case Aug: return "August";
    case Sep: return "September";
    case Oct: return "October";
    case Nov: return "November";
    case Dec: return "December";
    default:
        cerr << "MonthToString: invalid input month \'" << _month << "\'\n";
        exit(1);
    }
}

/* Definition of friend function operator<< */

ostream& operator<< (ostream& out, Month m) {
    out << m.MonthToString2();
    return out;
}


// ***** Add your Date class definition and driver program below. *****
class Date {
public:
    Date();
    Date(int initMonth, int initDay, int initYear);
    Date(string monthName, int initDay, int initYear);
    ostream& outputDateAsInt(ostream& out);
    ostream& outputDateAsString(ostream& out);
    friend ostream& operator<<(ostream& in, Date date);
    friend const Date operator++(Date &d);
    void setMonth(int month_value);
private:
    Month month;
    int day;
    int year;
};

istream& operator<<(istream& in, Date date);

Date::Date() {
    day = 1;
    year = 2018;
    month = Month();
}

Date::Date(int initMonth, int initDay, int initYear) {
    day = initDay;
    year = initYear;
    month = Month(initMonth);
}

Date::Date(string monthName, int initDay, int initYear) {
    day = initDay;
    year = initYear;
    this->month = Month();
    this->month.setMonth(monthName);
}

ostream& Date::outputDateAsInt(ostream& out) {
    out << month.MonthToInt() << '/' << day << '/' << year;
    return out;
}

ostream& Date::outputDateAsString(ostream& out) {
    out << month.MonthToString()<< " " << day << ", " << year;
    return out;
}

int main(const int argc, const char* argv[]) {
    Date d1 = Date(),
         d2 = Date(2, 1, 2018),
         d3 = Date("Mar", 1, 2018),
         d4 = Date(12, 31, 2018);
    cout << " With the following declarations: "<< endl
        << "\tDate d1, d2(2, 1, 2018), d3(\"Mar\", 1, 2018); " << endl
        << "...and using operator<< :\" " << endl;
    cout << "d1 == " << d1 << endl;
    cout << "d2 == " << d2 << endl;
    cout << "d3 == " << d3 << endl <<endl;
    
    d3.setMonth(4);
    cout << "After d3.setMonth(4):" << endl;
    cout << "d3 == " << d3 << endl << endl;
    
    cout << "With the following declaration:" << endl << "\tDate d4(12, 31, 2018);" << endl;
    cout << "d4.outputDateAsInt(cout) outputs ";
    d4.outputDateAsInt(cout);
    cout << endl;
    cout << "d4.outputDateAsString(cout) outputs ";
    d4.outputDateAsString(cout);
    cout << endl << endl;
    
    ++d4;
    cout << "++d4 == " << d4 << endl;

    return 0;
}

ostream& operator<<(ostream& out, Date date) {
    out << date.month << " " << date.day << ", " << date.year;
    return out;
    
}

const Date operator++(Date &d){
    d.year += 1;
    return d;
}


void Date::setMonth(int month_value) {
    month = Month(month_value);
}
