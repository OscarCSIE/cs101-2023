#include <iostream>

using namespace std;

class Car{
    public:
    string m_brand;
    string m_model;
    int m_year;
    int m_Maxseating;
    Car(string x, string y, int z, int s){
        m_brand = x;
        m_model = y;
        m_year = z;
        m_Maxseating = s;
    }
    int get_m_maxseating(){
        return m_Maxseating;
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
    BMW_Car car_1 ("X5", 2023, 6);
    cout<<car_1.m_brand<<" : ";
    cout<<"Drive Mode = "<<car_1.get_DriveMode()<<endl;
    AUDI_Car car_2 ("X5", 2023, 6);
    cout<<car_2.m_brand<<" : ";
    cout<<"Drive Mode = "<<car_2.get_DriveMode()<<endl;
    BENZ_Car car_3 ("X5", 2023, 6);
    cout<<car_3.m_brand<<" : ";
    cout<<"Drive Mode = "<<car_3.get_DriveMode()<<endl;
    return 0;
}
