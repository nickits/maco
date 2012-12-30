#ifndef ADMIN_H
#define ADMIN_H

#include <cppcms/view.h>
#include <string>

namespace back  {
    struct admin : public cppcms::base_content {
        std::string entity;
    };
}


#endif
// vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4
