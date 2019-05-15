#include <string>

#ifndef UNESCAPE_H
#define UNESCAPE_H

std::string unEscape(std::string line, std::string find) {
    std::string ret = line;
    for(int i=0;i<ret.length();i++) {
        for(int l=0;l<find.length();l++) {
            if (ret[i] == find[l]) {
                bool replace = true;
                if (replace) {
                    ret.erase(i-1, 1);
                    i--;
                }
            }
        }
    }
    return ret;
}

#endif