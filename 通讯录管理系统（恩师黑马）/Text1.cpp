#include<bits/stdc++.h>
#include<Windows.h>
#undef max
#define MAX 1000
using namespace std;
// 本项目所有注释均在关键代码下方显示

struct Person {
	string m_Name;// 姓名
	int m_Sex;// 性别：1->男，2->女
	int m_Age;// 年龄
	string m_Phone;// 电话
	string m_Addr;// 住址
};
// 联系人结构体

struct Addressbooks {
	Person personArray[MAX];// 联系人数组
	int m_Size;// 当前记录的联系人个数
};
// 通讯录结构体

void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "当前通讯录已满，无法继续添加......" << endl;
		return;
	}
	// 判断是否满人
	else
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		

		cout << "请输入性别：" << endl;
		cout << "1————男" << endl;
		cout << "2————女" << endl;
		int sex = 0;
		while (1)
		{
			cin >> sex;
			if (cin.fail()) 
			{
				// 输入非数字时处理错误
				cin.clear(); // 清除错误状态
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清空缓冲区
				cout << "oioioi，你输入的是哪个类型的数据，老老实实给我输入1或2啊魂淡！！！" << endl;
				continue;
			}
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
				cout << "无意冒犯，这人是去过泰国吗喵？" << endl;
			// 这里想输出颜文字，还没解决VS特殊字符输出的问题，呜呜呜呜呜呜
		}


		cout << "请输入年龄：" << endl;
		int age = 0;
		while (1)
		{
			cin >> age;
			if (cin.fail())
			{
				// 输入非数字时处理错误
				cin.clear(); // 清除错误状态
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清空缓冲区
				cout << "oioioi，你输入的是哪个类型的数据，老老实实给我输入年龄啊魂淡！！！" << endl;
				continue;
			}
			if (age >= 0 && age < 500)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			else if (age < 0)
				cout << "？？？？？本通讯录暂时无法存储天堂人的信息" << endl;
			else
			{
				cout << "呦吼，你还认识神仙？他/她多少岁来着？" << endl;
				int age1;
				cin >> age1;
				abs->personArray[abs->m_Size].m_Age = age1;
				cout << "呜呼~~~已经帮你把你的神仙朋友的年龄存好了（以第二次输入为准）" << endl;
				break;
			}
		}


		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;


		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;


		abs->m_Size++;
		cout << "添加成功！\n" << endl;

		system("pause");
		system("cls");// 清屏

	}
}
// 1、添加联系人

void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前通讯录内无任何联系人......\n" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名： " << abs->personArray[i].m_Name << endl;
			cout << "性别： " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << endl;
			cout << "年龄： " << abs->personArray[i].m_Age << endl;
			cout << "电话： " << abs->personArray[i].m_Phone << endl;
			cout << "住址： " << abs->personArray[i].m_Addr << endl;
			cout << "=============================" << endl;
		}
	}
	system("pause");
	system("cls");// 清屏
}
// 2、显示联系人

int is_exist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (name == abs->personArray[i].m_Name)
			return i;
	}
	return -1;
}
// 检测联系人是否存在

void deletePerson(Addressbooks* abs)
{
	cout << "请输入您想要删除的联系人姓名：" << endl;
	string name;
	cin >> name;

	int ret = is_exist(abs, name);// ret就是要删除之人的下标
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		// 最暴力的删除，将要删除之人后面的所有数据进行前移
		cout << "删除成功\n" << endl;
	}
	else
		cout << "抱歉捏亲，查无此人......\n" << endl;

	system("pause");
	system("cls");// 清屏
}
// 3、删除联系人

void findPerson(Addressbooks* abs)
{
	string name;
	cout << "请输入您想要查找的联系人：" << endl;
	cin >> name;
	int ret = is_exist(abs, name);
	if (ret != -1)
	{
		cout << "姓名： " << abs->personArray[ret].m_Name << endl;
		cout << "性别： " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << endl;
		cout << "年龄： " << abs->personArray[ret].m_Age << endl;
		cout << "电话： " << abs->personArray[ret].m_Phone << endl;
		cout << "住址： " << abs->personArray[ret].m_Addr << endl << endl;
	}
	else
		cout << "抱歉捏亲，查无此人......\n" << endl;

	system("pause");
	system("cls");
}
// 4、查找联系人

void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您想要修改其信息的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = is_exist(abs, name);
	if (ret != -1)
	{
		cout << "请问您想要修改联系人的哪些信息呢？" << endl;
		string xinXi = "";
		cout << "a————姓名" << endl;
		cout << "b————性别" << endl;
		cout << "c————年龄" << endl;
		cout << "d————电话" << endl;
		cout << "e————住址" << endl;
		cout << "（示例：输入abe，即修改姓名、性别、住址）" << endl;
		cin >> xinXi;
		for (int i = 0; i < xinXi.size(); i++)
		{
			switch (xinXi[i])
			{
			case 'a':
			{
				string name;
				cout << "请输入姓名：" << endl;
				cin >> name;
				abs->personArray[ret].m_Name = name;
				break;
			}
			case 'b':
			{
				cout << "请输入性别：" << endl;
				cout << "1————男" << endl;
				cout << "2————女" << endl;
				int sex = 0;
				while (1)
				{
					cin >> sex;
					if (cin.fail())
					{
						// 输入非数字时处理错误
						cin.clear(); // 清除错误状态
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清空缓冲区
						cout << "oioioi，你输入的是哪个类型的数据，老老实实给我输入1或2啊魂淡！！！" << endl;
						continue;
					}
					if (sex == 1 || sex == 2)
					{
						abs->personArray[ret].m_Sex = sex;
						break;
					}
					else
						cout << "无意冒犯，这人是去过泰国吗喵？" << endl;
				}
				break;
			}
			case 'c':
			{
				cout << "请输入年龄：" << endl;
				int age = 0;
				while (1)
				{
					cin >> age;
					if (cin.fail())
					{
						// 输入非数字时处理错误
						cin.clear(); // 清除错误状态
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清空缓冲区
						cout << "oioioi，你输入的是哪个类型的数据，老老实实给我输入年龄啊魂淡！！！" << endl;
						continue;
					}
					if (age >= 0 && age < 500)
					{
						abs->personArray[ret].m_Age = age;
						break;
					}
					else if (age < 0)
						cout << "？？？？？本通讯录暂时无法存储天堂人的信息" << endl;
					else
					{
						cout << "您还认识神仙？他/她多少岁来着？" << endl;
						int age1;
						cin >> age1;
						abs->personArray[ret].m_Age = age1;
						cout << "已经帮您把您的神仙朋友的年龄存好了（以第二次输入为准）" << endl;
						break;
					}
				}
				break;
			}
			case 'd':
			{
				cout << "请输入联系电话：" << endl;
				string phone;
				cin >> phone;
				abs->personArray[abs->m_Size].m_Phone = phone;
				break;
			}
			case 'e':
			{
				cout << "请输入家庭住址：" << endl;
				string address;
				cin >> address;
				abs->personArray[abs->m_Size].m_Addr = address;
				break;
			}
			}
		}
		cout << "修改成功！！\n" << endl;
	}
	else
		cout << "抱歉捏亲，查无此人......\n" << endl;

	system("pause");
	system("cls");
}
// 5、修改联系人

void cleanPerson(Addressbooks* abs)
{
	cout << "请问您确定清空吗？（请输入确定/返回）" << endl;
	string decide;
	cin >> decide;
	if (decide == "确定") 
	{
		abs->m_Size = 0;
		cout << "当前通讯录已清空" << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	// 伪清空
}
// 6、清空联系人

void showMenu()
{
	cout << "#############################" << endl;
	cout << "#####   1、添加联系人   #####" << endl;
	cout << "#####   2、显示联系人   #####" << endl;
	cout << "#####   3、删除联系人   #####" << endl;
	cout << "#####   4、查找联系人   #####" << endl;
	cout << "#####   5、修改联系人   #####" << endl;
	cout << "#####   6、清空联系人   #####" << endl;
	cout << "#####   0、退出通讯录   #####" << endl;
	cout << "#############################" << endl;
}
// 菜单界面

int main()
{
	Addressbooks abs;
	// 创建通讯录结构体变量
	abs.m_Size = 0;

	int select = 0;// 创建一个用户选择输入的变量
	while (true)
	{
		showMenu();
		// 菜单调用

		cin >> select;
		switch (select)
		{
		case 1:// 1、添加联系人
			addPerson(&abs);
			break;
		case 2:// 2、显示联系人
			showPerson(&abs);
			break;
		case 3:// 3、删除联系人
			deletePerson(&abs);
			break;
		case 4:// 4、查找联系人
			findPerson(&abs);
			break;
		case 5:// 5、修改联系人
			modifyPerson(&abs);
			break;
		case 6:// 6、清空联系人
			cleanPerson(&abs);
			break;
		case 0:// 0、退出通讯录
			cout << "欢迎下次使用！！" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	// 当程序运行到 system("pause"); 时，会暂停控制台窗口的关闭，并显示提示信息：
	// 请按任意键继续...（Windows 系统下）
	// 用户按下任意键后，程序才会继续执行或退出
	// 常见用途：防止控制台程序运行结束后窗口直接关闭（就是打开exe文件窗口会一闪而过）（尤其是在直接双击运行.exe 时）
	return 0;
}
// 原视频：https://www.bilibili.com/video/BV1et411b73Z?spm_id_from=333.788.videopod.episodes&vd_source=e13512de71238e1d7acac3ac5bb6eb10&p=72
