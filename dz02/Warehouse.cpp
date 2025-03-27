#include "Warehouse.h"
#include "Product.h"
#include <iostream>
#include <iomanip>


int Warehouse::nextIdNumber = 100;

string Warehouse::generate_id() {
    string newId = "W" + to_string(nextIdNumber++);
    return newId;
}
//Конструкторы и деструктор
Warehouse::Warehouse() : m_type(WarehouseType::CENTER), m_longitudeW(0.0), m_latitudeW(0.0),
                        m_maxCapacity(1000), m_currentStock(0), m_amount(0) {
    m_id = generate_id();
    this->list = nullptr;
}

Warehouse::Warehouse(WarehouseType t, double lon, double lat, int maxCap, int n) : m_type(t), m_longitudeW(lon), m_latitudeW(lat),
 m_maxCapacity(maxCap), m_currentStock(0), m_amount(n){
    m_id = generate_id();
    this->list = new product[m_amount];
}

Warehouse::Warehouse(const Warehouse& other)
    : m_id(other.m_id), m_type(other.m_type), m_longitudeW(other.m_longitudeW),
      m_latitudeW(other.m_latitudeW), m_maxCapacity(other.m_maxCapacity),
      m_currentStock(other.m_currentStock), list(other.list), m_amount(other.m_amount) {
        this->list = new product[other.m_amount];  
        for(int i=0; i<other.m_amount; i++){
            this->list[i] = other.list[i];
    }
}

Warehouse::~Warehouse(){
    delete[] list;
}
//Геттинги
string Warehouse::getId() const { return m_id; }
WarehouseType Warehouse::get_type() const { return m_type; }
double Warehouse::get_longitudeW() const { return m_longitudeW; }
double Warehouse::get_latitudeW() const { return m_latitudeW; }
int Warehouse::get_maxCapacity() const { return m_maxCapacity; }
int Warehouse::get_currentStock() const { return m_currentStock; }
const product*  Warehouse::get_products() const { return list; }
int Warehouse::get_amount() const { return m_amount; }

//Сеттинги
void Warehouse::set_type(WarehouseType t) { m_type = t; }

void Warehouse::set_longitude(double lon) {
    cin >> lon;
    while (lon < 19 || lon > 169) {
        cout << "Введенные значения не соответсвуют требованиям" << endl << "Введите значения повторно" << endl;}
    m_longitudeW = lon;
}

void Warehouse::set_latitude(double lat) {
    cin >> lat;
    while (lat < 41 || lat > 82) {
        cout << "Введенные значения не соответсвуют требованиям" << endl << "Введите значения повторно" << endl;}
    m_latitudeW = lat;
}

void Warehouse::set_maxCapacity(int cap) {
    cin>>cap;
    while (cap <= 0) {
        cout << "Введенные значения не соответсвуют требованиям" << endl << "Введите значения повторно" << endl;}
    m_maxCapacity = cap;
}
void Warehouse::set_amount(int amount){
    m_amount = amount;
}
//Расстояние Манхеттена
double Warehouse::Get_d(product& product) const{
    double d;
    return d = abs(get_latitudeW() - product.get_latitudeTP()) + abs(get_longitudeW() - product.get_longitudeTP());
}


// Добавление продукта
void Warehouse::add_product(const product& product) {
    while (m_currentStock + product.get_quantity() > m_maxCapacity) {
        cout << "Склад переполнен" << endl << "уменьшите количество продукта" << endl;
    }
    m_amount++;
    list[m_amount] = product;
    m_currentStock += product.get_quantity();
}
// Поиск продукта
int Warehouse::search_by_name(){
    int pos;
    string name;
    cout<<"Поиск названия: "; cin>>name;

    for(int i=0; i<get_amount(); i++){
        if(list[i].get_name() == name){
            pos = i;
            return pos;
        }
        else cout<<"Продукт не найден"<<endl;
    }
}
// Список продуктов на складе 
void Warehouse::print_info() const {
    
    for (int i = 0; i < get_amount(); i++) {
        std::cout << "  - " << list[i].get_name() << ": " << list[i].get_quantity() << "\n";
    }
}
//Удаление продуктов
void Warehouse::remove_product(){
    int pos;
    pos = search_by_name();

    if(pos!= -1){
        for(int i = pos; i < get_amount()-1; i++)
            list[i] = list[i+1];        
            m_amount--;
            set_amount(m_amount);
        cout<<"Product deleted!"<<endl;
    }else{
        cout<<"Producr not found!"<<endl;
    }
}


//Меню
void Warehouse::menu(int &opc){
    cout<<left;
    cout<<"--------------------"<<endl;
    cout<<"MENU OF Warehouse"<<endl;
    cout<<"--------------------"<<endl;
    cout<<"[1]. add_product"<<endl;
    cout<<"[2]. print_info"<<endl;
    cout<<"[3]. search_by_name"<<endl;
    cout<<"[4]. remove_product"<<endl;
    cout<<"[5]. Get_d"<<endl;
    cout<<"[6]. Exit"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"Enter option: "; cin>>opc;
}