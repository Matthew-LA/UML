 /***********************************************
 Author:Matthew Lorette Anaya
 Date: 09/27/2020
 Purpose: transforms zipcodes to barcodes and vice versa
 Sources of Help: internet
 Time Spent: 4 hours
 ***********************************************/
/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation. This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
 All programming assignments in this class are to be done by the student alone. No outside help is permitted except the instructor and
 approved tutors.
I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
 Date: 09/27/2020
 Name: Matthew Lorette Anaya
*/

#include <iostream>
#include <string>

using namespace std;

class ZipCode{
public:
    ZipCode(int num){
        zipcode = num;
    }
    ZipCode(string bar){
        test(bar);
        zipcode = toZipCode(bar);
    }
    
    int getZipCode(){
        return zipcode;
    }
    string getBarCode(){
        return toBarCode(zipcode);
    }
    
private:
    int zipcode;
    int toZipCode(string bar);
    string toBarCode(int num);
    int getSum(string temp);
    void test(string bad_zips);
    
};

int main(int argc, char * argv[]) {
    ZipCode zip(99504),
    zip2("100101010011100001100110001"),
    zip3(12345),
    zip4(67890);
    
    cout << zip.getZipCode() << "'s bar code is '"
    << zip.getBarCode() << "'" << endl;
    cout << zip2.getZipCode() << "'s bar code is '"
    << zip2.getBarCode() << "'" << endl;
    cout << zip3.getZipCode() << "'s bar code is '"
    << zip3.getBarCode() << "'" << endl;
    cout << zip4.getZipCode() << "'s bar code is '"
    << zip4.getBarCode() << "'" << endl;
    
    cout << endl;
    
    // Test a range of values by first constructing a zip code
    // with an integer, then retrieving the bar code and using
    // that to construct another ZipCode.
    int zip_int = 0;
    for (int i = 0; i < 25; i++)
    {
        // Make an aribrary 5-digit zip code integer, and use it
        // to construct a ZipCode
        int five_digit_zip = (zip_int * zip_int) % 100000;
        ZipCode z1(five_digit_zip);
        
        // Construct a second ZipCode from the first's bar code
        string z1_barcode = z1.getBarCode();
        ZipCode z2(z1_barcode);
        
        cout.width(3);
        cout << (i + 1) << ": ";
        cout.width(5);
        cout << z2.getZipCode() << " has code '"
        << z1_barcode << "'";
        
        if ((z1_barcode == z2.getBarCode()) &&
            (z1.getZipCode() == z2.getZipCode()) &&
            (z2.getZipCode() == five_digit_zip))
        {
            cout << " [OK]" << endl;
        }
        else
        {
            cout << " [ERR]" << endl;
        }
        
        // Increment the test value arbitrarily
        zip_int += (233 + zip_int % 7);
    }
    cout << endl;
    
    // Test some error conditions. This test assumes that
    // ZipCode will simply set its value to a flag that indicates
    // an error, and will not exit the program.
    int BAD_ZIP_COUNT = 2;
    string bad_zips[][2] = {
        { "100101010011100001100110000", "bad start/end character" },
        { "100101010011100001100110021", "bad digit" },
    };
    for (int i = 0; i < BAD_ZIP_COUNT; i++)
    {
        cout << "Testing: " << bad_zips[i][1] << " " << bad_zips[i][0] << endl;
        ZipCode test(bad_zips[i][0]);
        cout << endl;
    }
    
    cout << "Enter a character to quit." << endl;
    char c;
    cin >> c;
     
    return 0;
}

//transform barcode to zip code
int ZipCode::toZipCode(string bar){
    int sum =0;
    string  temp1 = bar.substr(1, 5),
            temp2 = bar.substr(6, 5),
            temp3 = bar.substr(11, 5),
            temp4 = bar.substr(16, 5),
            temp5 = bar.substr(21, 5);
    sum += getSum(temp1) * 10000;
    sum += getSum(temp2) * 1000;
    sum += getSum(temp3) * 100;
    sum += getSum(temp4) * 10;
    sum += getSum(temp5);
    
    return sum;
}

//transform zip code to barcode
string ZipCode::toBarCode(int num){
    
    int arr[5];
    int i;
    string barcode = "1";
    
    arr[0] = (num - (num % 10000)) /10000;
    arr[1] = (num % 10000) /1000;
    arr[2] = (num % 1000) /100;
    arr[3] = (num % 100) / 10;
    arr[4] = (num % 10);
    
    for(i = 0; i< 5; i++){
        switch(arr[i]){
            case 0:
                barcode += string("11000");
                break;
            case 1:
                barcode += string("00011");
                break;
            case 2:
                barcode += string("00101");
                break;
            case 3:
                barcode += string ("00110");
                break;
            case 4:
                barcode += string("01001");
                break;
            case 5:
                barcode += string("01010");
                break;
            case 6:
                barcode += string("01100");
                break;
            case 7:
                barcode += string("10001");
                break;
            case 8:
                barcode += string("10010");
                break;
            case 9:
                barcode += string("10100");
                break;
        }
    }
    barcode += string("1");
    return barcode;
}

//get sum of the barcode bitflags to be used to transform barcode to zip code
int ZipCode::getSum(string temp){
    int sum = 0;
    
    if(temp.at(0) == '1')
        sum += 7;
    
    if(temp.at(1) == '1')
        sum += 4;
    
    if(temp.at(2) == '1')
        sum += 2;
    
    if(temp.at(3) == '1')
        sum += 1;
    
    if(temp.at(4) == '1')
           sum += 0;
    
    if(sum == 11)
        sum = 0;
    
    
    
    return sum;
}
//test for valid barcodes
 void ZipCode::test(string bad_zips){
    int i;
    
    if (bad_zips.at(0) < '1' || bad_zips.at(26) < '1'){
        cout << "Wrong start/end character in the barcode!" << endl;
    }
    for(i = 0; i < bad_zips.length(); i++){
        if(bad_zips.at(i) > '1'){
            cout << "Wrong barcode! A barcode can only contain '0' and '1'." << endl;
        }
    }
 }

