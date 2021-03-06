// PayOffConstructible.h

#ifndef PAYOFF_CONSTRUCTIBLE_H
#define PAYOFF_CONSTRUCTIBLE_H

#include <iostream>
#include <PayOff3.h>
#include <PayOffFactory.h>
#include <string>

template <class T>
class PayOffHelper
{
public:

    PayOffHelper(std::string);
    static PayOff* Create(double);
};

template <class T>
PayOff* PayOffHelper<T>::Create(double Strike)
{
	return new T(Strike);
}

template <class T>
PayOffHelper<T>::PayOffHelper(std::string id)
{
	PayOffFactory& thePayOffFactory = PayOffFactory::Instance();
    thePayOffFactory.RegisterPayOff(id,PayOffHelper<T>::Create);
}	  

#endif

