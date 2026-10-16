#include "Txl.h"
#include<iostream>
int txl::size() const
{
	return m_size;
}
txl::~txl() {//析构函数
	contact* current = head;
	while (current != nullptr)//遍历链表 
	{
		contact* NextNode = current->next;
		delete current;//删除节点，由于外部使用new生成 
		current = NextNode;
	}
}
bool txl::reduce(int num)
{
	if (isEmpty())//空链表返回错误提示
	{
		return false;
	}

	if (num > 0 && num <= m_size)//防止输入数字超出范围 
	{
		contact* p = head;
		if (num == 1)//单节点情况下的特殊处理 
		{

			head = p->next;
			delete p;
			m_size--;
			if (head == nullptr)
			{
				tail = nullptr;
			}
			return true;
		}

		int i = 1;
		for (i = 1; i < num - 1; i++)
		{
			p = p->next;
		}//遍历，使得p==目标节点的前一个节点， 
		contact* l = p->next;//得到需删除的目标节点 
		if (l == tail)//尾节点情况单独处理 
		{
			delete l;
			p->next = nullptr;
			tail = p;

		}
		else
		{
			p->next = l->next;
			delete l;

		}
		m_size--;
		return true;
	}
	else
	{
		return false;
	}

}
bool txl::find(std::string nm) const//通过姓名查找 
{
	if (isEmpty())//空链表返回错误提示
	{
		return false;
	}
	contact* p = head;
	int i = 0;
	while (p != nullptr)//遍历整个链表，并且对目标名字进行打印 
	{
		if (p->name == nm)
		{
			i++;

			std::cout << p->name << " ";
			std::cout << p->phone << "\n";

		}

		p = p->next;
	}
	if (i > 0)//判断是否找到目标名字
		return true;
	else
		return false;
}
bool txl::print() const
{
	if (isEmpty())//空链表返回错误提示
	{
		return false;
	}
	contact* p = head;
	int i = 1;
	while (p != nullptr)//遍历整个链表，打印所有的名字以及对应的号码 
	{
		std::cout << i << ".";
		std::cout << p->name << " ";
		std::cout << p->phone << "\n";
		p = p->next;
		i++;
	}
	return true;
}
bool txl::change(int num, std::string nm, std::string ph)
{
	if (isEmpty())//空链表返回错误提示
	{
		return false;
	}
	if (num > 0 && num <= m_size)//防止输入数字超出范围 
	{
		contact* p = head;
		int i = 1;
		for (i = 1; i < num; i++)
		{
			p = p->next;
		}
		p->name = nm;
		p->phone = ph;
		return true;
	}
	else
	{
		return false;
	}
}
void txl::add(std::string nm, std::string ph)
{
	contact* NewContact = new contact(nm, ph);//生一个链表 
	if (head == nullptr)//空链表的特殊处理 
	{
		head = NewContact;
		tail = NewContact;

	}
	else
	{
		tail->next = NewContact;
		tail = NewContact;

	}
	m_size++;//长度加1

}
bool txl::isEmpty() const//判空函数 
{
	return m_size == 0;
}