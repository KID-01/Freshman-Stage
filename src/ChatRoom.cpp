#include"ChatRoom.h"
#include"User.h"
#include"Message.h"
#include<string>
#include<vector>
#include<iostream>
#include<memory>

ChatRoom::ChatRoom(const std::string& name):roomName(name){}

void ChatRoom::addUser(std::shared_ptr<User> user)
{
    m_users.push_back(user);
    std::cout<<user->getNickname()<<"加入了聊天室喵"<<std::endl;
}

void ChatRoom::sendMessage(std::shared_ptr<User> sender,const std::string& content)
{
    // 创建信息并存储
    Message msg(sender,content);
    m_messages.push_back(msg);

    // 直接发送（显示）信息
    std::cout<<"["<<msg.getSendTime()<<"]"<<sender->getNickname()<<":"<<content<<std::endl;
}

void ChatRoom::displayMessages() const
{
    std::cout<<"===聊天记录==="<<std::endl;
    for(const auto& msg:m_messages)
        std::cout<<"["<<msg.getSendTime()<<"]"<<msg.getSender()->getNickname()<<":"<<msg.getContent()<<std::endl;
}

bool ChatRoom::userLogin(const std::string& userID)
{
	if(userID.empty()||userID.find_first_not_of(" ")==std::string::npos)
	{
		std::cout<<"错误：用户ID不能为空或纯空格！\n"<<std::endl;
		return false;
	}
	for(std::shared_ptr<User> user:m_users)
	{
		if(user->getID()==userID)
		{
			user->login();
			std::cout<<user->getNickname()<<"上线了！\n"<<std::endl;
			return true;
		}
	}
	std::cout<<"用户 "<<userID<<" 不存在！\n"<<std::endl;
	return false;	
}

bool ChatRoom::userLogout(const std::string& userID)
{
	if(userID.empty()||userID.find_first_not_of(" ")==std::string::npos)
        {
                std::cout<<"错误：用户ID不能为空或纯空格！\n"<<std::endl;
                return false;
        }
	for(std::shared_ptr<User> user:m_users)
        {
                if(user->getID()==userID)
                {
                        user->logout();
                        std::cout<<user->getNickname()<<"下线了！\n"<<std::endl;
                        return true;
                }
        }
        std::cout<<"用户 "<<userID<<" 不存在！\n"<<std::endl;
        return false;
}

void ChatRoom::displayOnlineUsers() const
{
	std::cout<<"==在线用户==="<<std::endl;
	bool hasOnline=false;
	for(std::shared_ptr<User> user:m_users)
        {
                if(user->getOnline())
                {
			hasOnline=true;
                        std::cout<<">>"<<user->getNickname()<<"("<<user->getID()<<")"<<std::endl;
                }
        }
	if(!hasOnline)std::cout<<"目前无在线用户！"<<std::endl;
	std::cout<<std::endl;
}
