#include <assert.h>
#include <iostream>

using namespace std;

enum class suit : short
{
    SPADE,
    HEART,
    DIAMOND,
    CLUB
};

class pips
{
public:
    pips(int val) : v(val) { assert(v > 0 && v < 14); }
    friend ostream &operator<<(ostream &out, const pips &p);

private:
    int v;
};

class card
{
public:
    card():s(suit::SPADE),v(1){};
    card(suit s, pips v):s(s),v(v){};
    friend ostream &operator<<(ostream& out, const card &c);

    suit get_suit(){return s;}
    pips get_pips(){return v;}

private:
    suit s;
    pips v;
};


ostream &operator<<(ostream &out, const suit &s) {
    switch (s) {
        case suit::SPADE:
            out << "SPADE";
            break;
        case suit::HEART:
            out << "HEART";
            break;
        case suit::DIAMOND:
            out << "DIAMOND";
            break;
        case suit::CLUB:
            out << "CLUB";
            break;
    }
    return out;
}

ostream &operator<<(ostream &out, const card &c) {
    out << c.v << c.s;
    return out;
}