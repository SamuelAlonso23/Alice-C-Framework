#include <Basic/ExceptionType.hpp>
#include <Core/Exception.hpp>
#include <Networking/Socket.hpp>
#include <cstdlib>
#include <cstring>
#include <iostream>

int main(const int argc, const char** argv)
{
    const char *Message = "Hello from server";
    char Buffer[1024] = {0};

    Alice::Networking::Socket ServerSocket(
        Alice::Networking::SocketDomain::IPv4, 
        Alice::Networking::SocketType::Stream);

    if(Alice::Exception::Check(ExceptionType::SocketOpen))
    {
        std::cerr << "Socket Open" << std::endl;
        return EXIT_FAILURE;
    }

    ServerSocket.Bind(8080);
    
    if(Alice::Exception::Check(ExceptionType::SocketBind))
    {
        std::cerr << "Socket Bind" << std::endl;
        return EXIT_FAILURE;
    }

    ServerSocket.Listen(3);

    if(Alice::Exception::Check(ExceptionType::SocketListen))
    {
        std::cerr << "Socket Listen" << std::endl;
        return EXIT_FAILURE;
    }

    Alice::Networking::Socket Connection = ServerSocket.Accept();

    if(Alice::Exception::Check(ExceptionType::SocketAccept))
    {
        std::cerr << "Socket Accept" << std::endl;
        return EXIT_FAILURE;
    }

    Connection.Read(Buffer,sizeof(Buffer));

    if(Alice::Exception::Check(ExceptionType::SocketRead))
    {
        std::cerr << "Socket Read" << std::endl;
        return EXIT_FAILURE;
    }

    std::cerr << Buffer << std::endl;

    Connection.Write(Message, strlen(Message));

    if(Alice::Exception::Check(ExceptionType::SocketRead))
    {
        std::cerr << "Socket Write" << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}