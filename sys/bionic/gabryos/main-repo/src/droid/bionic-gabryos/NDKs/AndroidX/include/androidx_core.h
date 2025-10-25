#ifndef ANDROIDX_CORE_H
#define ANDROIDX_CORE_H

#include <string>
#include <iostream>

namespace androidx {
    void initCore();
    std::string getSystemProperty(const std::string &key);
}

#endif // ANDROIDX_CORE_H
