#pragma once
#include <iostream>
using namespace std;

enum CategoryType {
	Phone,
	Laptop,
	TV
};

class Product {
	CategoryType _category;
	string _name;
	int _price;

	void SetCategory(CategoryType type) { _category = type; };
	void SetName(string name) { _name = name; };
	void SetPrice(int price) {
		if (price > 100000 || price < 0) {
			throw exception("Incorrect price");
		}
		_price = price;
	}

public:
	CategoryType GetCategory() { return _category; };
	string GetName() { return _name; };
	int GetPrice() { return _price; };

	Product(CategoryType type = Phone, string name = "Xiaomi", int price = 20000) {
		SetCategory(type);
		SetName(name);
		SetPrice(price);
	}
};

class DiscountBase {
	CategoryType _category;
	void SetCategory(CategoryType type) { _category = type; };

public:
	CategoryType GetCategory() { return _category; };
	int virtual Calculate(Product* product) = 0;

protected:
	DiscountBase(CategoryType type) {
		SetCategory(type);
	}
};

class PercentDiscount : public DiscountBase {
	int _percent;

public:
	void SetPercent(int percent) { _percent = percent; };
	int GetPercent() { return _percent; };

	PercentDiscount(CategoryType type, int percent) : DiscountBase(type) {
		SetPercent(percent);
	}
	int Calculate(Product* product) override {
		if (GetCategory() == product->GetCategory()) {
			return ((100 - GetPercent()) * product->GetPrice() / 100);
		}
		return product->GetPrice();
	}
};

class CerteficateDiscount : public DiscountBase {
	int _amount;

public:
	void SetAmount(int amount) {
		if (amount < 0 || amount > 10000) {
			throw exception("Incorrect amount");
		}
		_amount = amount;
	}
	int GetAmount() { return _amount; };

	CerteficateDiscount(CategoryType type, int amount) : DiscountBase(type) {
		SetAmount(amount);
	}

	int Calculate(Product* product) override {
		
		if (GetCategory() == product->GetCategory()) {
			int amount = GetAmount();
			if (GetAmount() > product->GetPrice()) {
				SetAmount(GetAmount() - product->GetPrice());
				return (amount - product->GetPrice());
			}
			SetAmount(0);
			return (product->GetPrice() - amount);
		}
		return product->GetPrice();
	}
};

void ShowCheckWithDiscount(DiscountBase* discount, Product* products, int productsCount) {
	int localPrice;
	int price = 0;
	for (int i = 0; i < productsCount; i++) {
		cout << products[i].GetName() << " " << " Old cost: " << products[i].GetPrice();
		localPrice = discount->Calculate(&products[i]);
		price += localPrice;
		cout << " " << " New Price: " << localPrice << endl;
	}
	cout << "Full cost with discount: " << price;
}