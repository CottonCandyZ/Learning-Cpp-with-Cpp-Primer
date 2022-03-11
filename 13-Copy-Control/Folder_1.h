//
// Created by CottonCandyZ on 3/8/22.
//

#ifndef C__PRIMER_FOLDER_1_H
#define C__PRIMER_FOLDER_1_H

#include <set>

class Message;
class Folder {
    friend void swap(Folder&, Folder&);
public:
    void addMsg(Message *);
    void remMsg(Message *);
    Folder() = default;
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();
private:
    std::set<Message *> messages;
    void add_to_Messages(const Folder&);
    void remove_from_Messages();
};

void Folder::addMsg(Message *m) {
    messages.insert(m);
}

void Folder::remMsg(Message *m) {
    messages.erase(m);
}

Folder::Folder(const Folder &f) :messages(f.messages){
    add_to_Messages(f);
}

Folder &Folder::operator=(const Folder &rhs) {
    remove_from_Messages();
    messages = rhs.messages;
    add_to_Messages(rhs);
    return *this;
}

Folder::~Folder() {
    remove_from_Messages();
}

void swap(Folder& lhs, Folder&rhs) {
    using std::swap;
    lhs.remove_from_Messages();
    rhs.remove_from_Messages();
    swap(lhs.messages, rhs.messages);
    lhs.add_to_Messages(lhs);
    rhs.add_to_Messages(rhs);
}





#endif //C__PRIMER_FOLDER_1_H
