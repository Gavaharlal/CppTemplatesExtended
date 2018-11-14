
#include <cstddef>
#include <string>
#include <iostream>
#include "Array.cpp"

using namespace std;

template<typename Tx>
struct X {
    X() {
        this->x_ = new Tx();
        *this->x_ = 1;
    }

    X(const X &inX) {
        this->x_ = new Tx();
        *this->x_ = *inX.x_;
    }

    ~X() { delete this->x_; }

    friend std::ostream &operator<<(std::ostream &s, const X &obj) {
        s << *(obj.x_);
        return s;
    }

    void set(Tx i) {
        *(this->x_) = i;
    }

    Tx get() {
        return *x_;
    }

private:
    X &operator=(const X &inX) = delete;

    Tx *x_;
};


/******************************T E S T *********************/
void test0();

void test1();

void test2();

void test3();

void test4();

void test5();

void test6();

void test7();

bool minimal(int a, int b) {
    return a < b;
}

bool minimal(X<double> a, X<double> b) {
    return a.get() < b.get();
}

class Greater {
public:
    bool operator()(X<double> a, X<double> b) {
        return a.get() < b.get();
    }

    bool operator()(int a, int b) {
        return a < b;
    }
};

void test8() {
    cout << endl << "**********Test 8(MINIMUM)***************" << endl;

    {
        cout << endl << "*****INT(func/class)**********" << endl;
        Array<int> array(5, -1);
        Greater g;
        array[0] = 2;
        array[1] = 5;
        array[2] = 4;
        array[3] = 1;
        array[4] = 3;
        cout << minimum(array, minimal) << endl;
        cout << minimum(array, g) << endl;
    }

    {
        cout << endl << "*****INT||**********" << endl;
        Array<int> ints(3);
        Greater g;
        ints[0] = 10;
        ints[1] = 2;
        ints[2] = 15;
        cout << minimum(ints, minimal) << endl;
        cout << minimum(ints, g) << endl;
    }
    {
        cout << endl << "*****MyType<double>(func/class)**********" << endl;
        X<double> x;
        x.set(2.3);
        Array<X<double>> array(7, x);
        array[5].set(-0.2);
        Greater g;
        cout << minimum(array, minimal) << endl;
        cout << minimum(array, g) << endl;
    }


}

void test9() {
    cout << endl << "**********Test 9(FLATTEN)***************" << endl;

    {
        cout << endl << "*****INT[][][][1,2,3]**********" << endl;
        int n = 3;
        Array<int> inner(static_cast<size_t>(n));
        for (int i = 0; i < n; ++i) {
            inner[i] = i + 1;
        }
        Array<Array<int>> lvl2(2, inner);
        Array<Array<Array<int>>> lvl3(2, lvl2);
        Array<Array<Array<Array<int>>>> array(2, lvl3);
        flatten(array, cout);
    }
}

int main(int c, char **v) {
    setlocale(LC_ALL, "");
    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();

    return 0;
}

void test0() {
    cout << endl << "*****Test 0(primitives)**********" << endl;
    {
        cout << endl << "*****CHAR**********" << endl;
        Array<char> ar(size_t(5), '0');
        Array<char> x(size_t(4), '4');
        ar = x;
        ar.print();

        Array<char> x2(size_t(6), '6');
        ar = x2;
        ar.print();
    }
    cout << endl;
    {
        cout << endl << "*****STRING**********" << endl;
        Array<string> cr(size_t(5), "0");
        Array<string> cx(size_t(4), "4");
        cr = cx;
        cr.print();

        Array<string> cx2(size_t(6), "6");
        cr = cx2;
        cr.print();
    }
    cout << endl;
    {
        cout << endl << "*****INT**********" << endl;
        Array<int> ir(size_t(5), 0);
        Array<int> ix(size_t(4), 4);
        ir = ix;
        ir.print();

        Array<int> ix2(size_t(6), 6);
        ir = ix2;
        ir.print();
    }
    cout << endl;
    {
        cout << endl << "*****DOUBLE**********" << endl;
        Array<double> dr(size_t(5), 0.0);
        Array<double> dx(size_t(4), 4.0);
        dr = dx;
        dx.print();

        Array<double> ix2(size_t(6), 6.0);
        dr = ix2;
        dr.print();
    }
    cout << endl;
}


void test1() {
    {
        cout << endl << "*****Test 1(assigment)**********" << endl;
        Array<char> ar(size_t(100), '0');
        Array<char> x(size_t(0), '1');
        ar = x;
        ar.print();
    }
    {
        cout << "*****STRING**********" << endl;
        Array<string> cr(size_t(100), "Str0");
        Array<string> cx(size_t(0), "Str1");
        cr = cx;
        cr.print();

        Array<string> cx2(size_t(2), "Str3");
        cr = cx2;
        cr.print();
    }
    {
        cout << "*****INT**********" << endl;
        Array<int> cr(size_t(100), 0);
        Array<int> cx(size_t(0), 15);
        cr = cx;
        cr.print();

        Array<int> cx2(size_t(2), 55);
        cr = cx2;
        cr.print();
    }
}

void test2() {
    cout << endl << "*****Test 2(copy constructor)**********" << endl;
    {
        cout << "*****CHAR**********" << endl;
        Array<char> x(size_t(3), '3');
        Array<char> ar(x);
        ar.print();
    }
    {
        cout << "*****STRING**********" << endl;
        Array<string> x(size_t(3), "333");
        Array<string> ar(x);
        ar.print();
    }
}

void test3() {
    cout << endl << "*****Test 3(Empty)**********" << endl;
    {
        cout << "*****CHAR**********" << endl;
        Array<char> ar(size_t(0), '0');
        ar = ar;
        ar.print();
    }
    {
        cout << "*****STRING**********" << endl;
        Array<string> ar(size_t(0), "0");
        ar = ar;
        ar.print();
    }
}

void test4() {
    cout << endl << "*****Test 4(assigment A=A) **********" << endl;
    {
        Array<char> ar(size_t(4), '0');
        ar = ar;
        ar.print();
    }
}

void test5() {
    cout << endl << "*****Test 5(out bound)**********" << endl;
    {
        cout << "*****more**********" << endl;
        Array<char> ar(size_t(4), '0');
        cout << ar[10] << endl;
    }
    {
        cout << "*****less**********" << endl;
        Array<char> ar(size_t(4), '0');
        cout << ar[-10] << endl;
    }
}

void test6() {
    cout << endl << "*****Test 6(pointer)**********" << endl;
    {
        cout << "*****CHAR(copy)**********" << endl;
        Array<char> *ar = new Array<char>(size_t(4), '4');
        ar->print();
        delete ar;
    }
    {
        cout << "*****CHAR(=)**********" << endl;
        Array<char> *ar = new Array<char>(size_t(5), '5');
        ar->print();
        Array<char> *xr = ar;
        xr->print();
        delete ar;
    }
}

void test7() {
    cout << endl << "*****Test 7(X-object)**********" << endl;
    {
        cout << "***** X<INT> **********" << endl;
        X<int> x;
        x.set(4);
        auto *ar = new Array<X<int>>(size_t(4), x);
        ar->print();
        delete ar;
    }
    {
        cout << "***** X<CHAR> (new, =, copy) **********" << endl;
        X<char> x;
        x.set('c');
        auto *ar = new Array<X<char>>(size_t(4), x);
        ar->print();
        Array<X<char>> *xr = ar;
        xr->print();
        Array<X<char>> y(*xr);
        y.print();
        delete ar;
    }
}