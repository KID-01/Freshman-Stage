#include"User.h"
#include"Message.h"
#include"ChatRoom.h"
#include<string>
#include<iostream>
#include<vector>
#include<memory>
#include<algorithm>
#include<cctype>


int main()
{
    std::cout<<"===Chat v0.1==="<<std::endl<<std::endl;
    
    // 创建聊天室
    ChatRoom room("乌托邦");

    // 添加用户
    std::shared_ptr<User> user01=std::make_shared<User>("01","宵宫");
    std::shared_ptr<User> user02=std::make_shared<User>("02","星见雅");
    std::shared_ptr<User> user03=std::make_shared<User>("03","桃金娘");

    // 用户加入聊天室
    room.addUser(user01);
    room.addUser(user02);
    room.addUser(user03);

    // test循环
    std::string input;
    std::cout<<"\n欢迎回来，管理员"<<std::endl;
    while(std::getline(std::cin,input))
    {
	    std::string command=input;
	    std::transform(command.begin(),command.end(),command.begin(),::tolower);
	    if(command.empty())break;
	    if(command.find("login")==0)
	    {
		    // 对输入的命令进行正确判断
		    if(input.length()<=6)
		    {
			    std::cout<<"错误：请指定用户ID。示例：login [用户ID]\n"<<std::endl;
			    continue;
		    }

		    std::string userID=input.substr(6);
		    userID.erase(0,userID.find_first_not_of(" "));// 去掉可能的空格

		    if(!userID.empty()&&userID.find_first_not_of(" ")!=std::string::npos)std::cout<<"尝试登录用户："<<userID<<std::endl;// 以“login”开头
		    room.userLogin(userID);
	    }
	    else if(command.find("logout")==0)
	    {
		    if(input.length()<=6)
                    {
                            std::cout<<"错误：请指定用户ID。示例：logout [用户ID]\n"<<std::endl;
                            continue;
                    }

		    std::string userID=input.substr(7);
		    userID.erase(0,userID.find_first_not_of(" "));

		    if(!userID.empty()&&userID.find_first_not_of(" ")!=std::string::npos)std::cout<<"尝试登出用户："<<userID<<std::endl;
		    room.userLogout(userID);
	    }
	    else if(command=="online")
	    {
		    room.displayOnlineUsers();
	    }
	    // 显示所有在线用户
	    else if(command.find("switch to")==0)
	    {
		    if(input.length()<=9)
		    {
			    std::cout<<"错误：请指定转换的模式。示例：switch to admin\n"<<std::endl;
			    continue;
		    }
		    std::string mode=input.substr(10);
		    mode.erase(0,mode.find_first_not_of(" "));

		    if(mode=="admin")
		    {
			    room.switchToAdminMode();
			    continue;
		    }
		    // 管理员mode
		    if(command.find("switch to user")==0)
		    {
			    mode=input.substr(15);
			    mode.erase(0,mode.find_first_not_of(" "));
			    room.switchToUserMode(mode);
		    }
		    else
		    {
			    std::cout<<"错误：格式不正确。示例：switch to user userID\n"<<std::endl;
		    }
	    }
	    // 转换模式以发言
	    else if(command=="statue")
	    {
		    if(room.isAdminMode())
		    {
			    std::cout<<"you are in admin mode\n"<<std::endl;
		    }
		    else
		    {
			    std::shared_ptr<User> user=room.getCurrentUser();
			    std::cout<<"you are in user mode , userID: "<<user->getID()<<std::endl<<std::endl;
		    }
	    }
	    // 查看当前模式
	    else if(command=="exit")break;
	    // 退出
	    else
	    {
		    room.sendMessage(input);
	    }
	    // else用来发送信息
    }

    // 显示所有消息
    room.displayMessages();

    std::cout<<"===模拟结束===\n"<<std::endl;

    // 添加暂停
    std::cout<<"按回车键退出...\n"<<std::endl;
    std::string tem;
    while(std::getline(std::cin,tem)){if(tem.empty())break;}

    return 0;


}
