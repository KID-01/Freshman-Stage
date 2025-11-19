#ifndef MESSAGE_H
#define MESSAGE_H

#include<string>
#include<chrono>
#include<memory>

class User;

class Message{
private:
	std::shared_ptr<User> m_sender;// m_sender现在是一个智能指针，它指向一个User对象，并且允许多个地方共享这个对象的所有权
	std::string m_content;
    std::chrono::system_clock::time_point m_sendTime;
public:
    Message(std::shared_ptr<User> sender,const std::string& content);
    std::string getContent() const;
    std::shared_ptr<User> getSender() const;
    std::string getSendTime() const;
// 时间的处理用的是系统时钟
    
};


#endif
