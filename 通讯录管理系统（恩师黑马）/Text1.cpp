#include<bits/stdc++.h>
#include<Windows.h>
#undef max
#undef min
using namespace std;
// 本项目所有注释均在关键代码下方显示

class ConsoleColor {
private:
	HANDLE hConsole;  // 控制台句柄，相当于控制台的"遥控器"
	// console--(n.)控制台
	
public:
	// 构造函数：获取控制台句柄
	ConsoleColor() {
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取标准输出句柄
	}

	// 设置文字颜色
	void setTextColor(int color) {
		/*
		 * color 参数说明：
		 * 0:黑色 1:蓝色 2:绿色 3:浅蓝色 4:红色 5:紫色 6:黄色 7:白色
		 * 8:灰色 9:淡蓝 10:淡绿 11:淡浅蓝 12:淡红 13:淡紫 14:淡黄 15:亮白
		 */
		SetConsoleTextAttribute(hConsole, color);
	}

	// 设置背景和文字颜色
	void setColor(int backgroundColor, int textColor) {
		// 背景色左移4位，然后与文字颜色组合
		int color = (backgroundColor << 4) | textColor;
		SetConsoleTextAttribute(hConsole, color);
	}

	// 恢复默认颜色（灰底白字）
	void resetColor() {
		SetConsoleTextAttribute(hConsole, 7);  // 7 = 默认颜色
	}

	// 设置控制台窗口标题
	void setTitle(const wstring& title) {
		SetConsoleTitle(title.c_str());  // 将string转换为C风格字符串
		// 这里最后的A得加上，跟什么宽字符之类的有关，搞不懂
	}

	// 输出宽字符文本
	void print(const wstring& text) {
		DWORD written;
		WriteConsoleW(hConsole, text.c_str(), text.length(), &written, NULL);
	}

	// 输出宽字符文本并换行
	void println(const wstring& text) {
		DWORD written;
		WriteConsoleW(hConsole, text.c_str(), text.length(), &written, NULL);
		cout << endl;
	}

	// 输出带颜色的宽字符文本
	void printColored(int color, const wstring& text) {
		setTextColor(color);
		print(text);
		resetColor();
	}

	// 输出带颜色的宽字符文本并换行
	void printlnColored(int color, const wstring& text) {
		setTextColor(color);
		println(text);
		resetColor();
	}
};
// 2.0界面优化

// 创建全局颜色管理器对象
ConsoleColor console;

struct Person {
	string m_Name;// 姓名
	int m_Sex;// 性别：1->男，2->女
	int m_Age;// 年龄
	string m_Phone;// 电话
	string m_Addr;// 住址
};
// 联系人结构体

struct Addressbooks {
	vector<Person> personArray;// 2.0采用动态数组通讯录
};
// 通讯录结构体

void addPerson(Addressbooks* abs)
{
	// 2.0自动扩容，无数量限制
	Person temPerson;

	string name;
	cout << "请输入姓名：" << endl;
	cin >> name;
	temPerson.m_Name = name;
		

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
			temPerson.m_Sex = sex;
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
			temPerson.m_Age = age;
			break;
		}
		else if (age < 0)
			cout << "？？？？？本通讯录暂时无法存储天堂人的信息" << endl;
		else
		{
			cout << "您还认识神仙？他/她贵庚？" << endl;
			int age1;
			cin >> age1;
			temPerson.m_Age = age1;
			cout << "已经帮您把您的神仙朋友的年龄存好了（以第二次输入为准）" << endl;
			break;
		}
	}


	cout << "请输入联系电话：" << endl;
	string phone;cin >> phone;
	temPerson.m_Phone = phone;


	cout << "请输入家庭住址：" << endl;
	string address;cin >> address;
	temPerson.m_Addr = address;


	abs->personArray.push_back(temPerson);
	cout << "添加成功！\n" << endl;

	system("pause");
	system("cls");// 清屏

}
// 1、添加联系人

void showPerson(Addressbooks* abs)
{
	if (abs->personArray.size() == 0)
	{
		cout << "当前通讯录内无任何联系人......\n" << endl;
	}
	else
	{
		for (int i = 0; i < abs->personArray.size(); i++)
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
	for (int i = 0; i < abs->personArray.size(); i++)
	{
		if (name == abs->personArray[i].m_Name)
			return i;
	}
	return -1;
}
int is_exist(Addressbooks* abs, string name, bool f)
{
	for (int i = 0; i < abs->personArray.size(); i++)
	{
		if (abs->personArray[i].m_Name.find(name) != string::npos)
			return i;
	}
	return -1;
}
// 检测联系人是否存在,2.0分为模糊搜索和具体搜索

void deletePerson(Addressbooks* abs)
{
	cout << "请输入您想要删除的联系人姓名：" << endl;
	string name;
	cin >> name;

	int ret = is_exist(abs, name);// ret就是要删除之人的下标
	if (ret != -1)
	{
		abs->personArray.erase(abs->personArray.begin() + ret);
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
	cout << "请输入查询方式：1——具体查询\n" <<
		    "                2——模糊查询" << endl;
	int a; cin >> a;
	// 2.0支持模糊查询
	string name;
	cout << "请输入您想要查找的联系人：" << endl;
	cin >> name;
	int ret;
	if (a == 1)ret = is_exist(abs, name);
	else ret = is_exist(abs, name, 1);
	if (ret != -1)
	{
		if (a == 1)
		{
			for (int i = 0; i < abs->personArray.size(); i++)
			{
				if (abs->personArray[i].m_Name == name)
				{
					cout << "姓名： " << abs->personArray[i].m_Name << endl;
					cout << "性别： " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << endl;
					cout << "年龄： " << abs->personArray[i].m_Age << endl;
					cout << "电话： " << abs->personArray[i].m_Phone << endl;
					cout << "住址： " << abs->personArray[i].m_Addr << endl;
					cout << "=============================" << endl;
				}
			}
		}
		else
		{
			for (int i = 0; i < abs->personArray.size(); i++)
			{
				if (abs->personArray[i].m_Name.find(name) != string::npos)
				{
					cout << "姓名： " << abs->personArray[i].m_Name << endl;
					cout << "性别： " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << endl;
					cout << "年龄： " << abs->personArray[i].m_Age << endl;
					cout << "电话： " << abs->personArray[i].m_Phone << endl;
					cout << "住址： " << abs->personArray[i].m_Addr << endl;
					cout << "=============================" << endl;
				}
			}
		}
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
						cout << "您还认识神仙？他/她贵庚？" << endl;
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
				abs->personArray[ret].m_Phone = phone;
				break;
			}
			case 'e':
			{
				cout << "请输入家庭住址：" << endl;
				string address;
				cin >> address;
				abs->personArray[ret].m_Addr = address;
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
		abs->personArray.clear();
		cout << "当前通讯录已清空" << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
}
// 6、清空联系人

void showMenu()
{
	system("cls");  // 清屏
	// 顶部标题
	console.printlnColored(11, L"╔══════════════════════════════════════╗");
	console.printlnColored(11, L"║          通讯录管理系统 v2.0         ║");
	console.printlnColored(11, L"╚══════════════════════════════════════╝");
	console.println(L"");

	// 菜单选项
	console.printlnColored(10, L"  ┌──────────────────────────────────┐");
	console.printColored(10, L"  │  ");
	console.printColored(14, L"1.");
	console.printlnColored(10, L" 📝 添加联系人                │");

	console.printColored(10, L"  │  ");
	console.printColored(14, L"2.");
	console.printlnColored(10, L" 👥 显示所有联系人            │");

	console.printColored(10, L"  │  ");
	console.printColored(14, L"3.");
	console.printlnColored(10, L" 🗑️  删除联系人               │");

	console.printColored(10, L"  │  ");
	console.printColored(14, L"4.");
	console.printlnColored(10, L" 🔍 查找联系人                │");

	console.printColored(10, L"  │  ");
	console.printColored(14, L"5.");
	console.printlnColored(10, L" ✏️  修改联系人               │");

	console.printColored(10, L"  │  ");
	console.printColored(14, L"6.");
	console.printlnColored(10, L" 🧹 清空通讯录                │");

	console.printColored(10, L"  │  ");
	console.printColored(14, L"0.");
	console.printlnColored(10, L" 🚪 退出系统                  │");
	console.printlnColored(10, L"  └──────────────────────────────────┘");
	console.println(L"");

	// 输入提示
	console.printColored(14, L"请输入您的选择 (0-6): ");
}
// 菜单界面

int main()
{
	Addressbooks abs;
	// 创建通讯录结构体变量

	// 设置控制台标题
	console.setTitle(L"📒 通讯录管理系统 v2.0");

	int select = 0;// 创建一个用户选择输入的变量

	while (true)
	{
		console.setTitle(L"📒 通讯录管理系统 v2.0");

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