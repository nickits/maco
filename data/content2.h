#ifndef CONTENT2_H
#define CONTENT2_H

#include <cppcms/view.h>
#include <string>

namespace front  {
    struct content : public cppcms::base_content {
        std::string text;
    };    
}


#endif
// vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4
