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

    // test循环
    std::string input;
    std::cout<<"\n欢迎回来，管理员"<<std::endl;
    while(std::getline(std::cin,input))
    {
	    std::transform(input.begin(),input.end(),input.begin(),::tolower);
	    if(input.empty())break;
	    if(input.find("login")==0)
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
	    else if(input.find("logout")==0)
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
	    else if(input=="online")
	    {
		    room.displayOnlineUsers();
	    }
	    else std::cout<<"有人发来消息\n"<<input<<std::endl<<std::endl;
    }


    // 模拟聊天
    room.sendMessage(user01,"英雄形态的宵宫姐姐登场！\n");
    room.sendMessage(user02,"我是对空六科的星见雅\n");

    room.addUser(user03);
    room.sendMessage(user01,"\n欢迎新人加入！\n");
    room.sendMessage(user03,"大家好！我是桃金娘。小苹果，今天就拜托你了\n");

    // 显示所有消息
    room.displayMessages();

    std::cout<<"===模拟结束===\n"<<std::endl;

    // 添加暂停
    std::cout<<"按回车键退出...\n"<<std::endl;
    std::string tem;
    while(std::getline(std::cin,tem)){if(tem.empty())break;}

    return 0;


}
