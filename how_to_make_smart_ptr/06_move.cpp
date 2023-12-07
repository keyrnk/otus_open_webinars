#include "pretty.h"
#include "utils.h"

#include <functional>
#include <memory>
#include <cstring>

class Message
{
private:
    char* text;  // текст сообщения
    unsigned size;    // размер сообщения

public:
    // обычный конструктор
    Message(const char* data, std::size_t count)
    {
        std::cout << "Message ctor" << std::endl;
        size = count;
        text = new char[size];  // выделяем память
        for(std::size_t i = 0; i < size; i++)    // копируем данные
        {
            text[i] = data[i];
        }
    }
    // конструктор копирования
    Message(const Message& copy) 
        : Message{copy.text, copy.size }  // обращаемся к стандартному конструктору
    {
        std::cout << "Message copy ctor" << std::endl;
    }

    //перемещающий конструктор
    Message(Message&& msg)
        : text(msg.text)
        , size(msg.size)
    {
        std::cout << "Message move ctor" << std::endl;
        msg.text = nullptr;
        msg.size = 0;
    }
     
    // деструктор
    ~Message()
    { 
        std::cout << "Message dtor"<< std::endl;
        delete[] text;  // особождаем память
    }

    char* GetText() const
    {
        return text;
    }
};

class Messenger
{
public:
    Messenger(Message mes)
        : message(std::move(mes))
    { }
    void SendMessage() const
    {
        std::cout << "Send message " << std::endl;
    }
private:
    Message message;
};

void MessageTest()
{
    Message msg{"Hello Word", 11};
    std::cout << "message " << msg.GetText() << std::endl;

    Messenger messenger(std::move(msg));
    messenger.SendMessage();

    //std::cout << "message " << msg.GetText() << std::endl;
}

int main(int argc, char *argv[]) 
{
    MessageTest();
    return 0;
}
