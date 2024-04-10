#ifndef INCLUDE_INCLUDES_VANILLAOPTION_H_
#define INCLUDE_INCLUDES_VANILLAOPTION_H_

class VanillaOption
{
public:
    VanillaOption();  // default constructor
    VanillaOption(const double _K,
                  const double _r,
                  const double _T,
                  const double _S,
                  const double _sigma);  // parameter constructor
    VanillaOption(const VanillaOption& rhs);  // copy constructor
    virtual ~VanillaOption();  // default virtual destructor

public:
    VanillaOption& operator=(const VanillaOption& rhs);  // copy assignment

public:  // getters
    double getK() const;
    double getr() const;
    double getT() const;
    double getS() const;
    double getsigma() const;

private:  // european vanilla helpers
    double N(const double x) const;
    double calc_call_price() const;
    double calc_put_price() const;

private:  // setter helpers
    void copy(const VanillaOption& rhs);
    void init();

private:  // member vars
    double K;
    double r;
    double T;
    double S;
    double sigma;
};

#endif  // INCLUDE_INCLUDES_VANILLAOPTION_H_
