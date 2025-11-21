#ifndef CHATROOM_H
#define CHATROOM_H


#include<vector>
#include<string>
#include<memory>

class User;
class Message;

class ChatRoom{
private:
	enum class ChatMode{
            ADMIN_MODE,
            USER_MODE
    	};
    std::string roomName;
    std::vector<std::shared_ptr<User>> m_users;
    std::vector<Message> m_messages;
    ChatMode m_currentMode;
    std::shared_ptr<User> m_currentUser;

public:
    ChatRoom(const std::string& name);
    
    void addUser(std::shared_ptr<User> user);
    // 用户添加
    void sendMessage(const std::string& content);
    // 发送信息
    void displayMessages()const;
    
    bool userLogin(const std::string& userID);
    
    bool userLogout(const std::string& userID);
    
    void displayOnlineUsers() const;
    
    bool switchToUserMode(const std::string& userID);
    // 转换为用户模式
    bool isUserMode() const;
    // 判断是用户模式	

    bool switchToAdminMode();
    // 转换为管理员模式
    bool isAdminMode() const;
    // 判断是管理员模式

    ChatMode getCurrentMode() const;
    
    std::shared_ptr<User> getCurrentUser() const;
};


#endif
