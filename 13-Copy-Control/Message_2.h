//
// Created by CottonCandyZ on 3/8/22.
//

#ifndef C__PRIMER_MESSAGE_2_H
#define C__PRIMER_MESSAGE_2_H

#include <string>
#include <set>
#include "Folder_1.h"

class Message {
    friend class Folder;

public:
    explicit Message(const std::string &str = "") : contents(str) {}

    Message(const Message &);

    Message &operator=(const Message &);

    ~Message();

    void save(Folder &);

    void remove(Folder &);

    friend void swap(Message &, Message &);

private:
    std::string contents;
    std::set<Folder *> folders;

    void add_to_Folders(const Message &);
    void remove_from_Folders();

    void addFldr(Folder* f) { folders.insert(f); }
    void remFldr(Folder* f) { folders.erase(f); }
};

void Message::save(Folder &f) {
    addFldr(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    remFldr(&f);
    f.remMsg(this);
}

/**
 * 负责更新指向 folder 内的指针，使其指向新的 message
 * @param m 传入一个原先 message 的常量引用
 */
void Message::add_to_Folders(const Message &m) {
    for (auto &f: m.folders) {
        f->addMsg(this);
    }
}

Message::Message(const Message &m) :
        contents(m.contents), folders(m.folders) {
    add_to_Folders(m);
}

/**
 * 负责更新指向 folder 内的指针，使其删除指向的 message
 */
void Message::remove_from_Folders() {
    for (auto &f: folders) {
        f->remMsg(this);
    }
}

Message::~Message() {
    remove_from_Folders();
}

Message &Message::operator=(const Message &rhs) {
    remove_from_Folders(); // 清理已连接的 folders
    contents = rhs.contents;
    folders = rhs.folders; // 直接完成替换
    add_to_Folders(rhs); // 更新
    return *this;
}

void swap(Message &lhs, Message &rhs) {
    using std::swap;
    for (const auto &f:lhs.folders) {
        f->remMsg(&lhs);
    }
    for (const auto &f:rhs.folders) {
        f->remMsg(&rhs);
    }
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for (const auto &f:lhs.folders) {
        f->addMsg(&lhs);
    }
    for (const auto &f:rhs.folders) {
        f->addMsg(&rhs);
    }
}

void Folder::add_to_Messages(const Folder& f) {
    for (auto m : f.messages)
        m->folders.insert(this);
}

void Folder::remove_from_Messages() {
    for (auto m:this->messages) {
        m->folders.erase(this);
    }
}

#endif //C__PRIMER_MESSAGE_2_H
