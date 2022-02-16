#include <iostream>
using namespace std;

class Mass
{
public:
   
    void setMassAvoirdupoisPounds(double num){
        massDrams = num * 256.0;
    }
    
    void setMassTroyPounds(double num){
        massDrams = num * 96.0;
    }
    
    void setMassMetricGrams(double num){
        massDrams = num / 1.7718451953125;
    }
    
    
    double getMassAvoirdupoisPounds(void){
        return massDrams / 256.0;
    }
    
    double getMassTroyPounds(void){
        return massDrams / 96.0;
    }
    
    double getMassMetricGrams(void){
        return massDrams * 1.7718451953125;
    }
    
private:
        double massDrams;
};

void convert_apounds();
void convert_tpounds();
void convert_grams();
int get_mode(int &);


int main(void) {
    
    int mode;

    while (get_mode(mode))
    {
        switch (mode)
        {
            case 1:
                convert_apounds();
                break;
            case 2:
                convert_tpounds();
                break;
            case 3:
                convert_grams();
                break;
        }
    }
    
    
    return 0;
}

void convert_apounds()
{
    double apounds;
    Mass mass;
    do
    {
        cout << "Please enter a Mass in Avoirdupois pounds: ";
        cin >> apounds;
    } while (apounds < 0);
    mass.setMassAvoirdupoisPounds(apounds);
    cout << "Mass in Avoirdupois pounds is: " << mass.getMassAvoirdupoisPounds() << endl;
    cout << "Mass in Troy pounds is: " << mass.getMassTroyPounds() << endl;
    cout << "Mass in Grams is: " << mass.getMassMetricGrams() << endl;
    return;
}

void convert_tpounds()
{
    double tpounds;
    Mass mass;
    cout << "Enter a Mass in Troy pounds: ";
    cin >> tpounds;
    mass.setMassTroyPounds(tpounds);
    cout << "Mass in Troy pounds is: " << mass.getMassTroyPounds() << endl;
    cout << "Mass in Avoirdupois pounds is: " << mass.getMassAvoirdupoisPounds() << endl;
    cout << "Mass in Grams is: " << mass.getMassMetricGrams() << endl;
    return;
}
void convert_grams()
{
    double grams;
    Mass mass;
      
    do{
        cout << "Please enter a mass in grams: ";
        cin >> grams;
    }while(grams < 0);
    mass.setMassMetricGrams(grams);
        
    cout << "Mass in Avoirdupois pounds is " << mass.getMassAvoirdupoisPounds() << endl;
    cout << "Mass in Troy pounds is " << mass.getMassTroyPounds() << endl;
    cout << "Mass in in grams is " << grams;
        
    return;
        
}
    
int get_mode(int &mode)
{
    cout << "Please enter 1 to use Avoirdupois pounds, 2 to use Troy pounds, 3 to use Grams, or 0 to exit: ";
    cin >> mode;
    return mode;
}
