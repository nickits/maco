/*
 * Copyright (C) 2011 Nicki, Bulgaria.
 *
 * See the LICENSE file for terms of use.
*/


#ifndef PAYMENT_H
#define PAYMENT_H

#include "defines.h"

enum PaymentType{
	Credit,
	Debit
};

enum PaymentMethod{
	Cash,
	CreditCard,
	DebitCard,
	BankOrder,
	OnDelivery
};

class Payment
{
public:
	double value;
	double vat;
	time_t paymentDate;
	PaymentType type;
	PaymentMethod method;
	Sales sales;

	
	template<class Action> 
	void persist(Action& a)
	{
		dbo::field(a, value, "value");
		dbo::field(a, vat, "vat");
		dbo::field(a, paymentDate, "paymentDate");
		dbo::field(a, type, "type");
		dbo::field(a, method, "method");
		dbo::hasMany(a, sales, dbo::ManyToOne, "payment");
	}

};

DBO_EXTERN_TEMPLATES(Payment);

#endif // PAYMENT_H
