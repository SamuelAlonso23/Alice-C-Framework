#include <Basic/ExceptionType.hpp>
#include <Core/Exception.hpp>
#include <Networking/Socket.hpp>
#include <cstdlib>
#include <cstring>

int main(const int argc, const char ** argv)
{
    char *Message = "Hello from client";
     
    Alice::Networking::Socket ClientSocket(
        Alice::Networking::SocketDomain::IPv4, 
        Alice::Networking::SocketType::Stream);
       
    if(Alice::Exception::Check(ExceptionType::SocketOpen))
    {
        return EXIT_FAILURE;
    }

    ClientSocket.Connect("127.0.0.1",8080);

    if(Alice::Exception::Check(ExceptionType::SocketConnect))
    {
        return EXIT_FAILURE;
    }

    ClientSocket.Write(ClientSocket, Message, strlen(Messgae));

    return EXIT_SUCCESS;
}