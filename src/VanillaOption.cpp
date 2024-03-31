#ifndef INCLUDE_SRC_VANILLAOPTION_CPP_
#define INCLUDE_SRC_VANILLAOPTION_CPP_
#include <cmath>

#include "VanillaOption.h"

VanillaOption::VanillaOption()
{
    init();
}

VanillaOption::VanillaOption(const double _K,
                             const double _r,
                             const double _T,
                             const double _S,
                             const double _sigma)
{
    K     = _K;
    r     = _r;
    T     = _T;
    S     = _S;
    sigma = _sigma;
}

VanillaOption::VanillaOption(const VanillaOption& rhs)
{
    copy(rhs);
}

VanillaOption& VanillaOption::operator=(const VanillaOption& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    copy(rhs);
    return *this;
}

double VanillaOption::calc_call_price() const
{
    double sigma_sqrt_T = sigma * sqrt(T);
    double d_1          = (log(S / K) + (r + sigma * sigma * 0.5) * T) / sigma_sqrt_T;
    double d_2          = d_1 - sigma_sqrt_T;
    return S * N(d_1) - K * exp(-r * T) * N(d_2);
}

double VanillaOption::calc_put_price() const
{
    double sigma_sqrt_T = sigma * sqrt(T);
    double d_1          = (log(S / K) + (r + sigma * sigma * 0.5) * T) / sigma_sqrt_T;
    double d_2          = d_1 - sigma_sqrt_T;
    return K * exp(-r * T) * N(-d_2) - S * N(-d_1);
}

void VanillaOption::init()
{
    K     = 0.0;
    r     = 0.0;
    T     = 0.0;
    S     = 0.0;
    sigma = 0.0;
}

void VanillaOption::copy(const VanillaOption& rhs)
{
    K     = rhs.getK();
    r     = rhs.getr();
    T     = rhs.getT();
    S     = rhs.getS();
    sigma = rhs.getsigma();
}

#endif  // INCLUDE_SRC_VANILLAOPTION_CPP_
