#include"ChatRoom.h"
#include"User.h"
#include"Message.h"
#include<string>
#include<vector>
#include<iostream>
#include<memory>

ChatRoom::ChatRoom(const std::string& name):roomName(name),
	m_currentMode(ChatMode::ADMIN_MODE),
	m_currentUser(nullptr){}

void ChatRoom::addUser(std::shared_ptr<User> user)
{
    m_users.push_back(user);
    std::cout<<user->getNickname()<<"加入了聊天室喵\n"<<std::endl;
}
// 添加用户

void ChatRoom::sendMessage(const std::string& content)
{
	if(m_currentMode==ChatMode::ADMIN_MODE)
	{
		std::cout<<"错误：管理员模式无法参与讨论\n"<<std::endl;
		return;
	}
	// 管理员无法发送信息

    // 创建信息并存储
    Message msg(m_currentUser,content);
    m_messages.push_back(msg);

    // 直接发送（显示）信息
    std::cout<<"["<<msg.getSendTime()<<"]"<<m_currentUser->getNickname()<<":"<<content<<std::endl;
}
// 发送信息

void ChatRoom::displayMessages() const
{
    std::cout<<"===聊天记录==="<<std::endl;
    for(const auto& msg:m_messages)
        std::cout<<"["<<msg.getSendTime()<<"]"<<msg.getSender()->getNickname()<<":"<<msg.getContent()<<std::endl;
}
// 显示聊天记录

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
// 用户登录（额，好像不应该用login作为登录，不管了）

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

			if(m_currentUser&&m_currentUser->getID()==userID)switchToAdminMode();
			// 如果在用户模式下用户下线，自动切换为管理员模式

                        return true;
                }
        }
        std::cout<<"用户 "<<userID<<" 不存在！\n"<<std::endl;
        return false;
}
// 用户登出

void ChatRoom::displayOnlineUsers() const
{
	std::cout<<"\n==在线用户==="<<std::endl;
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
// 显示所有在线用户

bool ChatRoom::switchToUserMode(const std::string& userID)
{
	if(userID.empty()||userID.find_first_not_of(" ")==std::string::npos)
	{
		std::cout<<"用户ID无效！请不要输入空！\n"<<std::endl;
		return false;
	}
	for(std::shared_ptr<User> user:m_users)
	{
		if(userID==user->getID())
		{
			if(!user->getOnline())
			{
				std::cout<<"当前用户"<<user->getID()<<"不在线\n"<<std::endl;
				return false;
			}
			else
			{
				m_currentUser=user;
				m_currentMode=ChatMode::USER_MODE;
				std::cout<<"已切换为普通用户模式\n"<<std::endl;
				return true;
			}
		}
	}
	std::cout<<"当前用户不存在\n"<<std::endl;
	return false;
}
// 转换为用户模式
bool ChatRoom::isUserMode() const{return m_currentMode==ChatMode::USER_MODE;}
// 判断为用户模式

bool ChatRoom::switchToAdminMode()
{
	m_currentUser=nullptr;
	m_currentMode=ChatMode::ADMIN_MODE;
	std::cout<<"已切换为管理员模式\n"<<std::endl;
	return true;
}
// 转换为管理员模式
bool ChatRoom::isAdminMode() const{return m_currentMode==ChatMode::ADMIN_MODE;}
// 判断为管理员模式

ChatRoom::ChatMode ChatRoom::getCurrentMode() const
{
	return m_currentMode;
}
// 获取现在的模式

std::shared_ptr<User> ChatRoom::getCurrentUser() const
{
	return m_currentUser;
}
// 获取现在在哪位用户的账号
