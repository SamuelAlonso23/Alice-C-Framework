#include <Basic/ExceptionType.hpp>
#include <Core/Exception.hpp>
#include <Networking/Socket.hpp>
#include <cstdlib>
#include <cstring>
#include <iostream>

int main(const int argc, const char ** argv)
{
    const char *Message = "Hello from client";
    char Buffer[1024] = {0};
    

    Alice::Networking::Socket ClientSocket(
        Alice::Networking::SocketDomain::IPv4, 
        Alice::Networking::SocketType::Stream);
       
    if(Alice::Exception::Check(ExceptionType::SocketOpen))
    {
        std::cerr << "Socket Open" << std::endl;
        return EXIT_FAILURE;
    }

    ClientSocket.Connect("127.0.0.1",8080);

    if(Alice::Exception::Check(ExceptionType::SocketConnect))
    {
        std::cerr << "Socket Connect" << std::endl;
        return EXIT_FAILURE;
    }

    ClientSocket.Write(Message,strlen(Message));

    if(Alice::Exception::Check(ExceptionType::SocketWrite))
    {
        std::cerr << "Socket Write" << std::endl;
        return EXIT_FAILURE;
    }

    ClientSocket.Read(Buffer, sizeof(Buffer));

    if(Alice::Exception::Check(ExceptionType::SocketRead))
    {
        std::cerr << "Socket Read" << std::endl;
        return EXIT_FAILURE;
    }
    
    std::cerr << Buffer << std::endl;

    return EXIT_SUCCESS;
}