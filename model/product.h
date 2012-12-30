/*
 * Copyright (C) 2011 Nicki, Bulgaria.
 *
 * See the LICENSE file for terms of use.
*/


#ifndef PRODUCT_H
#define PRODUCT_H

#include "defines.h"

class Product
{
public:
	std::string name;
	std::string description;
	std::string shortDescription;
	std::string idNumber;
	dbo::ptr<Image> image;
	dbo::ptr<Video> video;
	bool active;
	bool activeWeb;
	bool isDeleted;
	time_t createDate;
	time_t updateDate;
	time_t lastDeliveryDate;
	time_t lastSaleDate;
	time_t publishDate;
	double count;
	double deliveryPrice;
	double salePrice;
	dbo::ptr<Category> category;
	dbo::ptr<Collection> collection;
	Images images;
	Videos videos;
	OwnerProducts ownerProducts;
	ProductCharacteristics productCharacteristics;
	SaleDetails saleDetails;

	template<class Action> 
	void persist(Action& a)
	{
		dbo::field(a, name, "name");
		dbo::field(a, description, "description");
		dbo::field(a, shortDescription, "shortDescription");
		dbo::field(a, idNumber, "idNumber");
		dbo::belongsTo(a, image, "image");
		dbo::belongsTo(a, video, "video");
		dbo::field(a, active, "active");
		dbo::field(a, activeWeb, "activeWeb");
		dbo::field(a, isDeleted, "isDeleted");
		dbo::field(a, createDate, "createDate");
		dbo::field(a, updateDate, "updateDate");
		dbo::field(a, lastDeliveryDate, "lastDeliveryDate");
		dbo::field(a, lastSaleDate, "lastSaleDate");
		dbo::field(a, publishDate, "publishDate");
		dbo::field(a, count, "count");
		dbo::field(a, deliveryPrice, "deliveryPrice");
		dbo::field(a, salePrice, "salePrice");
		dbo::belongsTo(a, category, "category");
		dbo::belongsTo(a, collection, "collection");
		dbo::hasMany(a, images, dbo::ManyToOne, "product");
		dbo::hasMany(a, videos, dbo::ManyToOne, "product");
		dbo::hasMany(a, ownerProducts, dbo::ManyToOne, "product");
		dbo::hasMany(a, productCharacteristics, dbo::ManyToOne, "product");
		dbo::hasMany(a, saleDetails, dbo::ManyToOne, "product");
	}
};

DBO_EXTERN_TEMPLATES(Product);

#endif // PRODUCT_H
