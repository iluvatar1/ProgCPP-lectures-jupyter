#include <valarray>
#include <iostream>

// parameters
const double T0 = 0.0;
const double TF = 10.0;
const double DT = 0.1;
const double G = 9.81;
const double B = 2.45;

// state data struct
using state_t = std::valarray<double>;

// function declarations
void print_system(double t, const state_t & s);
void euler(double t, state_t & s);
void deriv(double t, const state_t & s, state_t & dsdt);

int main(int argc, char **argv)
{
    // state vector
    state_t s(2);

    // initial conditions
    s[0] = 2.0; 
    s[1] = 10.0;
    print_system(0.0, s);

    // time evolution
    for (double t = T0; t <= TF; t += DT) {
        // do one euler step
        euler(t, s);
        // print
        print_system(t+DT, s);
    }

    return 0;
}

void print_system(double t, const state_t & s)
{
    std::cout << t << "\t" << s[0] << "\t" << s[1] << "\n";
}

void euler(double t, state_t & s)
{
    state_t dsdt(s.size());
    deriv(t, s, dsdt);
    // asumimos valarray
    s = s + DT*dsdt;
}

void deriv(double t, const state_t & s, state_t & dsdt)
{
    dsdt[0] = s[1];
    dsdt[1] = -G - B*s[1];
}
