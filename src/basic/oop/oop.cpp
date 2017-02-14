//
// Created by zhuanxu on 17/2/14.
//


#include <iostream>
using namespace std;

namespace jj01 { // 转换函数
    class Fraction {
    public:
        // non-explicit one argument constructor
        explicit Fraction(int num, int den = 1) :
                m_numerator(num), m_denominator(den) {
//            std::cout << m_numerator << ' ' << m_denominator << std::endl;
        }

        operator double() const {
            return (double)m_numerator / m_denominator;
        }

        Fraction operator+(const Fraction &f) {
//            std::cout << "operator+(): " << f.m_numerator << ' ' << f.m_denominator << std::endl;
            return Fraction(m_numerator * f.m_denominator +   f.m_numerator * m_denominator,m_denominator * f.m_denominator);
        }

        int getNum() const {
            return m_numerator;
        }

        int getDen() const {
            return m_denominator;
        }

    private:
        int m_numerator;    //
        int m_denominator;  //
    };
    // 重载
    ostream &operator<<(ostream &os, const Fraction &f) {
//        os << f.getNum() << " " << f.getDen() << endl;
        os << (double)f.getNum()/f.getDen();
        return os;
    }

    void test_conversion_functions()
    {
        cout << "test_conversion_functions()" << endl;

        Fraction f1(3,5);
        cout << f1 << endl;
        double d = 4 + f1;		//4.6
        cout << d << endl;

        //! Fraction d2 = f + 4;	 //ambiguous

        Fraction d1(4);

        Fraction f2(1,4);
        Fraction f3 = f2 + f1;
        cout << f2 <<  " + " << f1 << " = "<< (f2 + f1) <<endl; //
//        cout << f3.getDen() << " " << f3.getNum() << endl;
    }
}
//-------------------------------------------------------------

int main() {
    jj01::test_conversion_functions();
}