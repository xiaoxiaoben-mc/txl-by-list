#pragma once

#include<string>
class contact
{
public:
	std::string name;
	std::string phone;
	contact* next;
	contact() :next(nullptr) {}//构造函数 
	contact(std::string nm, std::string ph) :name(nm), phone(ph), next(nullptr) {}//构造函数 

};
class txl
{
private:
	contact* head;//头节点 
	contact* tail;//尾节点 
	int m_size;//链表当前节点数量 ，即链表长度 
public:
	txl() :head(nullptr), tail(nullptr), m_size(0) {
	}
	~txl();
	txl(const txl&) = delete;
	txl& operator=(const txl&) = delete;
	int size() const;
	
	bool isEmpty() const;//判空函数 
	void add(std::string nm, std::string ph);

	bool reduce(int num);
	
	bool find(std::string nm) const;//通过姓名查找 ;
	
	bool print() const;
	
	bool change(int num, std::string nm, std::string ph);
	
};

