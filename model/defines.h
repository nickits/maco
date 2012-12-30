#include <Wt/Dbo/Types>
#include <string>

namespace dbo = Wt::Dbo;

typedef std::map<std::string, void*> MapAny;
typedef std::pair<std::string, void*> PairAny;


#include "product.h"
#include "category.h"
#include "collection.h"
#include "image.h"
#include "video.h"
#include "client.h"
#include "ownerproduct.h"
#include "characteristic.h"
#include "featuredproduct.h"
#include "productcharacteristic.h"
#include "specialoffer.h"
#include "company.h"
#include "shop.h"
#include "sale.h"
#include "payment.h"
#include "saledetail.h"

class Product;
class Client;
class Category;
class Collection;
class Image;
class Video;
class OwnerProduct;
class SpecialOffer;
class FeaturedProduct;
class Characteristic;
class ProductCharacteristic;
class Company;
class Shop;
class Sale;
class Payment;
class SaleDetail;


typedef dbo::collection<dbo::ptr<Product> > Products;
typedef dbo::collection<dbo::ptr<Client> > Clients;
typedef dbo::collection<dbo::ptr<Category> > Categories;
typedef dbo::collection<dbo::ptr<Collection> > Collections;
typedef dbo::collection<dbo::ptr<Image> > Images;
typedef dbo::collection<dbo::ptr<Video> > Videos;
typedef dbo::collection<dbo::ptr<OwnerProduct> > OwnerProducts;
typedef dbo::collection<dbo::ptr<SpecialOffer> > SpecialOffers;
typedef dbo::collection<dbo::ptr<FeaturedProduct> > FeaturedProducts;
typedef dbo::collection<dbo::ptr<Characteristic> > Characteristics;
typedef dbo::collection<dbo::ptr<ProductCharacteristic> > ProductCharacteristics;
typedef dbo::collection<dbo::ptr<Company> > Companies;
typedef dbo::collection<dbo::ptr<Shop> > Shops;
typedef dbo::collection<dbo::ptr<Sale> > Sales;
typedef dbo::collection<dbo::ptr<Payment> > Payments;
typedef dbo::collection<dbo::ptr<SaleDetail> > SaleDetails;


