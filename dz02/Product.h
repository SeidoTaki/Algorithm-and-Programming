#pragma once
#include <string>
using namespace std;
class product{
    private:
        string m_seed;
        string m_name;
        int m_price;
        int m_quantity;
        double m_longitudeTP;
        double m_latitudeTP;
    public:
        product ();
        product (string, string, int, double, double);
        product (const product& P);

        void set_seed(string seed);
        void set_name(string name);
        void set_price(int price);
        void set_quantity(int quantity);
        void set_longitudeTP(double lon);
        void set_latitudeTP(double lat);

        string get_seed() const; 
        string get_name() const;
        int get_price() const;
        int get_quantity() const;
        double get_longitudeTP() const;
        double get_latitudeTP() const;

        void print_seed() const;
        void print_name() const;
        void print_price()  const;
        void print_quantity() const;
        void print_longitudeTP() const;
        void print_latitudeTP() const;
}; 