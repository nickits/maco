#ifndef CONTENT1_H
#define CONTENT1_H

#include <cppcms/view.h>
#include <string>

namespace front1  {
    struct content1 : public cppcms::base_content {
        std::string text;
		std::string collections;
		std::string categories;
        std::string sellectionType;
		std::string collectionImages;
		std::string productImage;
    };
}


#endif
// vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4
