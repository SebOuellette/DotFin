#include <string>

#ifndef ESCAPEINQUOTES_H
#define ESCAPEINQUOTES_H

std::string escapeInQuotes(std::string line, std::string find) {
    std::string ret = line;
    int quotes = 0;
    for(int i=0;i<ret.length();i++) {
        if (ret[i] == '"') quotes++;
        for(int l=0;l<find.length();l++) {
            if (ret[i] == find[l] && quotes%2 == 1) {
                bool replace = true;
                if (i < ret.length() && find[l] == '\\') {
                    for(int x=0;x<find.length();x++) if (ret[i+1] == find[x]) replace = false; // so check if \ has operation right after, if it does, replace=false
                }
                if (replace) {
                    ret.insert(i,1, '\\');
                    i++;
                }
            }
        }
    }
    return ret;
}

#endif