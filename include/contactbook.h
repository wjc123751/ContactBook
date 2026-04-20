#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "contact.h"

class ContactBook {
private:
    std::vector<Contact> contacts;
    const std::string filename = "../data/contacts.txt";

public:
    ContactBook() {
        loadFromFile();
    }

    // 添加
    void add(const std::string& name, const std::string& phone) {
        contacts.push_back({name, phone});
        saveToFile();
    }

    // 显示全部
    void showAll() {
        if (contacts.empty()) {
            std::cout << "暂无联系人\n";
            return;
        }
        for (size_t i = 0; i < contacts.size(); ++i) {
            std::cout << i + 1 << ". " 
                      << contacts[i].name << " - " 
                      << contacts[i].phone << "\n";
        }
    }

    // 查找
    void search(const std::string& name) {
        for (auto& c : contacts) {
            if (c.name == name) {
                std::cout << "找到：" << c.name << " " << c.phone << "\n";
                return;
            }
        }
        std::cout << "未找到\n";
    }

    // 删除
    void remove(int index) {
        if (index < 1 || index > (int)contacts.size()) {
            std::cout << "编号错误\n";
            return;
        }
        contacts.erase(contacts.begin() + index - 1);
        saveToFile();
        std::cout << "删除成功\n";
    }

    // 从文件加载
    void loadFromFile() {
        std::ifstream file(filename);
        if (!file) return;

        Contact c;
        while (file >> c.name >> c.phone) {
            contacts.push_back(c);
        }
        file.close();
    }

    // 保存到文件
    void saveToFile() {
        std::ofstream file(filename);
        for (auto& c : contacts) {
            file << c.name << " " << c.phone << "\n";
        }
        file.close();
    }
};

#endif