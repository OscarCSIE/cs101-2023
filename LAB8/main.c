#include <iostream>
using namespace std;

class Fueltank{
private:
    int m_FueltankCapacity;
    int m_Gas_Grade;
    
public:
    Fueltank(int FuelTankCapacity = 3000, int Gas = 98){
        m_FueltankCapacity = FuelTankCapacity;
        m_Gas_Grade = Gas;
    }
    
    int fuel_up(int v, int gas){
        if(v > m_FueltankCapacity){
            cout<<"Error: FuelTankCapacity : "<<m_FueltankCapacity<<" but fuel up : "<<v<<endl;
        }
        if(gas != m_Gas_Grade){
            cout<<"Error: Gas_grade: "<<gas<<" Correct Gas_Grade: "<<m_Gas_Grade<<endl;
        }
        if(v == m_FueltankCapacity && gas == m_Gas_Grade){
            cout<<"fuel_up: "<<v<<" Gas_grade: "<<gas<<endl;
        }
        return v;
    }
    
    int set_Gas_grade(int Gas_grade){
        m_Gas_Grade = Gas_grade;
        return m_Gas_Grade;
    }
    
    int get_Gas_grade(){
        return m_Gas_Grade;
    }
};

class Car{
public:
    Fueltank m_Fueltank;
    int m_Maxseating;
    int price;
    int base;
    string m_brand;
    string m_model;
    int m_year;
    
public:
    Car(string x, string y, int z, int s){
        m_brand = x;
        m_model = y;
        m_year = z;
        m_Maxseating = s;
    }
    int get_Gas_grade(){
       return m_Fueltank.get_Gas_grade(); 
    }
    int set_Gas_grade(int gas = 98){
        cout<<"Set_Gas_grade : "<<gas<<endl;
        return m_Fueltank.set_Gas_grade(gas);
    }
    int fuel_up(int v, int gas = 98){
        return m_Fueltank.fuel_up(v, gas);
    }
};


class BMW_Car : public Car{
    private:
    string m_DriveMode;
    
    public:
    BMW_Car(string y, int z, int s) : Car("BMW", y, z, s){
        cout<<"Constructing BMW_Car\n";
        m_DriveMode = "Rear-Wheel";
    }
    string get_DriveMode(){
        return m_DriveMode;
    }
};

class AUDI_Car : public Car{
    private:
    string m_DriveMode;
    
    public:
    AUDI_Car(string y, int z, int s) : Car("AUDI", y, z, s){
        cout<<"Constructing AUDI_Car\n";
        m_DriveMode = "Front-Wheel";
    }
    string get_DriveMode(){
        return m_DriveMode;
    }
    string get_brand(){
        return m_brand;
    }
};

class BENZ_Car : public Car{
    private:
    string m_DriveMode;
    
    public:
    BENZ_Car(string y, int z, int s) : Car("BENZ", y, z, s){
        cout<<"Constructing BENZ_Car\n";
        m_DriveMode = "Front-Wheel";
    }
    string get_DriveMode(){
        return m_DriveMode;
    }
};

int main(){
    AUDI_Car car_2 ("A1", 2021, 2);
    cout<<car_2.get_brand()<<" : Gas_grade = "<<car_2.get_Gas_grade()<<endl;
    car_2.set_Gas_grade(95);
    cout<<car_2.get_brand()<<" : Gas_Grade = "<<car_2.get_Gas_grade()<<endl;
    car_2.fuel_up(3000, 95);
    
    return 0;
}
