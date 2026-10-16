#include <iostream>
#include<string>
#include"Txl.h"
bool readInt(int& value)
{
		if (std::cin >> value)
		{
			std::cin.ignore(100, '\n');
			return 1;
		}
		else
		{
			std::cin.clear();//复活吧，我的cin！！
			std::cin.ignore(100, '\n');
			return 0;
		}
}
std::string readString() 
{
	std::string str;
	std::getline(std::cin >> std::ws, str);
	if (!str.empty())
	{
		return str;
	}
	else
		return "";
}

bool isValidPhone(const std::string& phone)
{
	if (phone.size() != 11)//手机号只允许11位，后续可以添加数字判断
	{
		return 0;
	}
	bool isnumber = 1;

	for (int i = 0; i < 11; i++)
	{
		if (phone[i] < '0' || phone[i]>'9')
		{
			isnumber = 0;
			break;
		}
	}

	if (!isnumber)
	{
		return 0;
	}
	else
		return 1;
}

int main()
{
	txl ab;
	while (1)
	{
		//菜单打印
		std::cout << "\n--通讯录--" << '\n';
		std::cout << "1.增加" << '\n';
		std::cout << "2.删减" << '\n';
		std::cout << "3.查找" << '\n';
		std::cout << "4.显示" << '\n';
		std::cout << "5.修改" << '\n';
		std::cout << "请输入操作:";
		int s;
		while(1)
		{
			if (readInt(s))
			{
				break;
			}
			else 
				std::cout << "\n输入错误,请重新输入：";
		}
		
		switch (s) {
		case 1://1.增加
		{
			
			std::string name;
			while (1)
			{
				std::cout << "请输入姓名：\n";
				name = readString();
				if (!name.empty())
					break;
				else
					std::cout << "请重新输入姓名\n";
				
			}
			std::cout << "请输入手机号：\n";
			std::string phone;
			while (1)
			{
				phone = readString();
				if (!isValidPhone(phone))
				{
					std::cout << "请输入11位数字手机号\n";
				}
				else
					break;
			}
			ab.add(name, phone);//调用类add完成具体操作
			break;
		}
		case 2://2.删减
		{
			if (ab.size() == 0)//防止修改空通讯录
			{
				std::cout << "无可删除数据\n";
				break;
			}
			ab.print();
			std::cout << "请输入需要删除信息的索引\n";
			int num;
			while (1)
			{
				
				if (!readInt(num))
				{
					std::cout << "输入错误\n";
					continue;
				}
					
						
				if (num > 0 && num <= ab.size())
				{
					break;//条件正确跳出循环，否则重复要求用户输入
				}
				else
				{
					std::cout << "错误索引,请重新输入\n";
					continue;
				}

			}
			if (ab.reduce(num))//调用contacts类中的reduce删减被选中编号
			{
				std::cout << "删除成功\n";
				ab.print();
			}
			else
			{
				std::cout << "删除失败\n";
			}
			break;
		}
		case 3://3.查找
		{

			
			std::string name;
			while (1)
			{
				std::cout << "请输入姓名：\n";
				name = readString();
				if (!name.empty())
					break;
				else
					std::cout << "请重新输入姓名\n";

			}
			if (!ab.find(name))
			{
				std::cout << "没有找到\n";
			}

			break;
		}
		case 4://4.显示
			ab.print();
			break;
		case 5://5.修改
		{
			if (ab.size() == 0)//防止修改空通讯录
			{
				std::cout << "无可修改数据\n";
				break;
			}
			ab.print();//打印让用户可以选择需要修改的编号

			std::cout << "请输入需要修改的编号：\n";
			int num;

			while (1)//修改操作直接复制case1（ 后续可以提出成为函数，避免重复）
			{
				
				if (!readInt(num))
				{
					std::cout << "\n输入错误,请输入数字编号：";
					continue;
				}
				
					
				if (num > 0 && num <= ab.size())
				{
					//复制case1
					std::string name;
					while (1)
					{
						std::cout << "请输入姓名：\n";
						name = readString();
						if (!name.empty())
							break;
						else
							std::cout << "请重新输入姓名\n";

					}
					std::cout << "请输入手机号：\n";
					std::string phone;
					while (1)
					{
						phone = readString();
						if (!isValidPhone(phone))
						{
							std::cout << "请输入11位数字手机号\n";
						}
						else
							break;


					}
					//
					if (ab.change(num, name, phone))
					{
						std::cout << "修改成功\n";
					}
					else
					{
						std::cout << "修改失败\n";
					}
					break;
				}
				else
				{
					std::cout << "编号超出范围，请重新输入\n";
				}
				

			}
			break;
		}
		default://防止错误输入
		{
			std::cout << "错误索引,请重新输入\n";
			
			break;
		}
		}
	}

}
