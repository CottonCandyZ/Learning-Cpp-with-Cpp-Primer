//
// Created by CottonCandyZ on 3/14/22.
//

class Base {
public:
    void pub_men();

protected:
    int prot_men;
private:
    char priv_mem;
};

struct Pub_Derv : public Base {
    int f() { return prot_men; }

    void memfcn(Base &b) { b = *this; }
//    char g() { return priv_mem;}
};

struct Prot_Derv : protected Base {
    int f() { return prot_men; }
    void memfcn(Base &b) { b = *this; }
};


struct Priv_Derv : private Base {
    int f1() const { return prot_men; }
    void memfcn(Base &b) { b = *this; }
};

int main() {
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Base *p = &d1;
//    p = &d2;
//    p = &d3

    return 0;
}