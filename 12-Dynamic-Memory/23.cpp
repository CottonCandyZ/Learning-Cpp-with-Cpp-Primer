//
// Created by CottonCandyZ on 3/2/22.
//

#include <iostream>
#include <string>

int main() {
    {
        char *s1 = (char *) "abc";
        char *s2 = (char *) "efg";
        char *s3 = new char[strlen(s1) + strlen(s2) + 1];
        strcat(s3, s1);
        strcat(s3, s2);
        std::cout << s3 << std::endl;
        delete [] s1;
        delete [] s2;
        delete [] s3;
    }

    {
        std::string s1 = "abc";
        std::string s2 = "efg";
        char *s3 = new char[s1.length() + s2.length() + 1];
        strcpy(s3, (s1 + s2).c_str());
        std::cout << s3 << std::endl;
        delete [] s3;
    }
    return 0;
}