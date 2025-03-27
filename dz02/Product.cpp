#include "Product.h"
#include <iostream>
using namespace std;

product::product (): m_seed("0"), m_name("0"), m_price(0), m_longitudeTP(0.0), m_latitudeTP(0.0){}
product::product (string seed, string name, int price, double lon, double lat) : m_seed(seed), m_name(name), m_price(price), m_longitudeTP(lon), m_latitudeTP(lat) {}
product::product (const product& P) : m_seed(P.m_seed), m_name(P.m_name), m_price(P.m_price),m_longitudeTP(P.m_longitudeTP),
m_latitudeTP(P.m_latitudeTP) {}

void product::set_seed(string seed){
    string i = to_string((0+rand()%(9-0+1))*1000);
    string j = to_string(0 + rand() % (999999 - 0 + 1));
    string k = to_string(460);
    seed = k + i + j;
    m_seed = seed;
}
void product::set_name(string name){
    cout<<"Назовите свой продукт(предел символов: 50)"<<endl;
    cin>>name;
    int count=0;
    for (int t : name) count+=1;
    while (count > 50) {
        cout<<"Превышен допустимый предел символов"<<endl;
        cout<<"введите название заново"<<endl;
        cin>>name;
        m_name = name;
    }     
}
void product::set_price(int price){
    cout<<"Введите цену продукта"<<endl;
    cin>>price;
    m_price = price;
}
void product::set_quantity(int quantity){
    m_quantity = quantity;
}
void product::set_longitudeTP(double lon) {
    cin >> lon;
    while (lon < 19 || lon > 169) {
        cout << "Введенные значения не соответсвуют требованиям" << endl << "Введите значения повторно" << endl;}
    m_longitudeTP = lon;
}

void product::set_latitudeTP(double lat) {
    cin >> lat;
    while (lat < 41 || lat > 82) {
        cout << "Введенные значения не соответсвуют требованиям" << endl << "Введите значения повторно" << endl;}
    m_latitudeTP = lat;
}

    string product::get_seed() const { return m_seed; }
    string product::get_name() const { return m_name; }
    int  product::get_price() const { return m_price; }
    int product::get_quantity() const { return m_quantity; }
    double product::get_longitudeTP() const { return m_longitudeTP; }
    double product::get_latitudeTP() const { return m_latitudeTP; }

    void product::print_seed() const {cout << m_seed << endl;}
    void product::print_name() const {cout << m_name << endl;}
    void product::print_price() const {cout << m_price << endl;}
    void product::print_quantity() const {cout << m_quantity << endl;}
    void product::print_longitudeTP() const {cout << m_longitudeTP << endl;}
    void product::print_latitudeTP() const {cout << m_latitudeTP << endl;}