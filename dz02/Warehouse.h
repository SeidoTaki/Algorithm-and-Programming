#pragma once
#include "Product.h"
#include <string>
#include <stdexcept>
using namespace std;
enum WarehouseType {
    CENTER,
    WEST,
    EAST
};



class Warehouse {
private:
    string m_id;
    WarehouseType m_type;
    double m_longitudeW;
    double m_latitudeW;
    int m_maxCapacity;
    int m_currentStock;
    product* list;
    int m_amount;
    
  
    static int nextIdNumber;

    string generate_id();

public:
   
    Warehouse();
    Warehouse(WarehouseType t, double lon, double lat, int maxCap, int n);
    Warehouse(const Warehouse& other);
    ~Warehouse();

    string getId() const;
    WarehouseType get_type() const;
    double get_longitudeW() const;
    double get_latitudeW() const;
    int get_maxCapacity() const;
    int get_currentStock() const;
    const product* get_products() const;
    int get_amount() const;

    void set_type(WarehouseType t);
    void set_longitude(double lon);
    void set_latitude(double lat);
    void set_maxCapacity(int maxCap);
    void set_amount(int amount);

    void add_product(const product& product);
    int search_by_name();
    void remove_product();
    void print_info() const;

    double Get_d(product& ) const;
    
    void menu(int &opc);
};

