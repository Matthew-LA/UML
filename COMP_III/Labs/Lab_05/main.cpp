#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ComplexNumber{
public:
    //Constructors
    ComplexNumber(): real(0), imaginary(0) {}
    ComplexNumber(double realInput, double imaginaryInput): real(realInput), imaginary(imaginaryInput) {}
    
    //Accessors
    double getRealPart() const { return real; }
    double getImaginaryPart() const { return imaginary; }
    
    //Mutators
    void setRealPart(double input) { real = input; }
    void setImaginaryPart(double input) { imaginary = input; }
    
    //Friend functions
    friend ostream& operator<<(ostream& out, ComplexNumber& compNum);
    
private:
    double real;
    double imaginary;
};

const ComplexNumber operator+(const ComplexNumber& num1, const ComplexNumber& num2);
const ComplexNumber operator-(const ComplexNumber& num1, const ComplexNumber& num2);
const ComplexNumber operator*(const ComplexNumber& num1, const ComplexNumber& num2);
const ComplexNumber operator/(const ComplexNumber& num1, const ComplexNumber& num2);
const ComplexNumber operator!(const ComplexNumber& num1);

ostream& operator<<(ostream& out, ComplexNumber& compNum);

int main (int argc, char* argv[]){
    ComplexNumber c1, c2(1.0, 2.0), c3(3.0, 4.0);
    
    cout << "Value of c1 (default constructor): " << endl;
    cout << "c1.Re == " << c1.getRealPart() << ", c1.() == " << c1.getImaginaryPart() << endl;
    cout << "Value of c2 (value constructor): " << endl;
    cout << "c2.Re() == " << c2.getRealPart() << ", c2.Im() == " << c2.getImaginaryPart() << endl << endl;
    
    c1 = c2 + c3;
    cout << "c2 + c3 " << c2 << " + " << c3 << " == " << c1 << endl;
    
    c1 = c2 - c3;
    cout << "c2 - c3 " << c2 << " - " << c3 << " == " << c1 << endl;
    
    c1 = c2 * c3;
    cout << "c2 * c3 " << c2 << " * " << c3 << " == " << c1 << endl;
    
    c1 = c2 / c3;
    cout << "c2 / c3 " <<  c2 << " / " << c3 << " == " << c1 << endl;
    
    c1 = (c2/c3) + (c2*c3);
    cout << "(c2/c3) + (c2*c3) == " << c1 << endl;
    
    c1 = !c2;
    cout << "Conjugate of c2 (" << c2 << ") == " << c1 << endl << endl;
    
    vector<ComplexNumber> vc;
    for (int i = 0; i < 10; i++) {
        vc.push_back(ComplexNumber(i, 2*i));
    }
    
    cout << "Vector output using indexed for-loop:\n";
    for (int i = 0; i < 10; i++) {
        cout << vc[i] << endl;
    }
    
    cout << "\nVector output using an iterator in for-loop:\n";
    // Type of it is actually std::vector<int>::iterator
    for (auto it = vc.begin(); it != vc.end(); ++it) {
        cout << *it << endl;
    }
    
    return 0;
}

const ComplexNumber operator+(const ComplexNumber& num1, const ComplexNumber& num2)
{
    return ComplexNumber(num1.getRealPart() + num2.getRealPart(), num1.getImaginaryPart() + num2.getImaginaryPart());
}

const ComplexNumber operator-(const ComplexNumber& num1, const ComplexNumber& num2)
{
    return ComplexNumber(num1.getRealPart() - num2.getRealPart(), num1.getImaginaryPart() - num2.getImaginaryPart());
}

const ComplexNumber operator*(const ComplexNumber& num1, const ComplexNumber& num2)
{
    return ComplexNumber(num1.getRealPart() * num2.getRealPart() - num1.getImaginaryPart() * num2.getImaginaryPart(),
                         num1.getImaginaryPart() * num2.getRealPart() + num1.getRealPart() * num2.getImaginaryPart());
}

const ComplexNumber operator/(const ComplexNumber& num1, const ComplexNumber& num2)
{
    double den = num2.getRealPart() * num2.getRealPart() + num2.getImaginaryPart() * num2.getImaginaryPart();
    return ComplexNumber((num1.getRealPart() * num2.getRealPart() + num1.getImaginaryPart() * num2.getImaginaryPart()) / den,
                        (num1.getImaginaryPart() * num2.getRealPart() - num1.getRealPart() * num2.getImaginaryPart()) / den);
     
    
}

const ComplexNumber operator!(const ComplexNumber& num1)
{
    return ComplexNumber(num1.getRealPart(), -num1.getImaginaryPart());
}

ostream& operator<<(ostream& out, ComplexNumber& compNum) {
    out << compNum.real << "+" << compNum.imaginary << "i";
    return out;
}
