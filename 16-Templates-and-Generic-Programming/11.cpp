//
// Created by CottonCandyZ on 3/17/22.
//

#include <iostream>
template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
    List<elemType>();
    List<elemType>(const List<elemType> &);
    List<elemType> &operator=(const List<elemType> &);
    ~List();
//    void insert(ListItem *ptr, elemType value);
    void insert(ListItem<elemType> *ptr, elemType value);

private:
//    ListItem *front, *end;
    ListItem<elemType> *front, *end;
};


int main() {
    return 0;
}