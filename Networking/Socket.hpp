#include <Basic/NoDefault.hpp>
#include <Basic/Types.hpp>
#include <Core/Exception.hpp>
#include <Configuration.hpp>


#if defined(AliceWindows)
#pragma comment(lib,"Ws2_32.lib")
#include <winsock2.h>
#include <ws2tcpip.h>
#elif defined(AliceLinux)
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h>
#endif

namespace Alice
{
    namespace Networking
    {
        enum class SocketDomain : u32
        {
            IPv4 = AF_INET,
            IPv6 = AF_INET6
        };

        enum class SocketType : u32
        {
            Stream = SOCK_STREAM,
            Datagram = SOCK_DGRAM,
            SequencePacket = SOCK_SEQPACKET
        };

        enum class SocketOption : u32
        {

        };
/**
        enum class SocketReceiveFlag : u32
        {
            None
        };
        
        enum class SocketSendFlag : u32
        {
            None
        };
*/
        class Socket
        {
        public:
            Socket() noexcept {}

            Socket(
                const SocketDomain& Domain,
                const SocketType& Type) noexcept
            {
                
            }

            Socket(const Socket& other) noexcept 
            {

            }

            Socket(Socket&& other) noexcept 
            {

            }

            ~Socket()
            {

            }

            Socket Accept() noexcept
            {
                Socket client;
                int result(-1);
                socklen_t size;
                if(domain == SocketDomain::IPv4)
                {
                    sockaddr_in address;
                    address.sin_family = AF_INET;
                    address.sin_addr.s_addr = INADDR_ANY;
                    address.sin_port = htons(port);
                    size = sizeof(address);
                    result = accept(socketfd,(sockaddr*)&address,&size);
                }
                else if(domain == SocketDomain::IPv6)
                {
                    sockaddr_in6 address;
                    address.sin6_family = AF_INET6;
                    address.sin6_addr = in6addr_any;
                    address.sin6_port = htons(port);
                    size = sizeof(address);
                    result = accept(socketfd,(sockaddr*)&address,&size);
                }

                if(result == -1)
                {
                    Exception::Raise(ExceptionType::SocketAccept);
                }
            }

            void Bind(const u32 Port) noexcept
            {
                u32 result(-1);
                if(domain == SocketDomain::IPv4)
                {
                    sockaddr_in address;
                    address.sin_family = AF_INET;
                    address.sin_addr.s_addr = INADDR_ANY;
                    address.sin_port = htons(Port);
                    result = bind(socketfd,(sockaddr*)&address,sizeof(address));
                }
                else if(domain == SocketDomain::IPv6)
                {
                    sockaddr_in6 address;
                    address.sin6_family = AF_INET6;
                    address.sin6_addr = in6addr_any;
                    address.sin6_port = htons(Port);
                    result = bind(socketfd,(sockaddr*)&address,sizeof(address));
                }
                
                if(result == -1)
                {
                    Exception::Raise(ExceptionType::SocketBind);
                }
            }

            void Close()
            {
                if(open)
                {
                    if(close(socketfd) == -1)
                    {
                        Exception::Raise(ExceptionType::SocketClose);
                    }
                    else
                    {
                        open = false;
                    }
                }
            }

            void Connect(const char* Host, const u32 Port) noexcept
            {
                if(open)
                {
                    if(domain == SocketDomain::IPv4)
                    {

                    }   
                    else if(domain == SocketDomain::IPv6)
                    {
                        /* code */
                    }
                }
            }

            void Listen(u32 Backlog)
            {
                if(listen(socketfd, Backlog) == -1)
                {
                    Exception::Raise(ExceptionType::SocketListen);
                }
            }

            void Open(const SocketDomain& Domain, const SocketType& Type)
            {
                socketfd = socket(
                    static_cast<int>(Domain),
                    static_cast<int>(Type),
                    0);
                if(socketfd == -1)
                {
                    Exception::Raise(ExceptionType::SocketOpen);
                }
                else
                {
                    domain = Domain;
                    type = Type;   
                    open = true;
                }
            }

            s32 Read(
                Socket& Connection,
                char* Buffer,
                u32 Length)
            {
                s32 length = read(Connection.socketfd, Buffer, Length);
                if(length == -1)
                {
                    Exception::Raise(ExceptionType::SocketRead);
                    return 0;
                }
                return length;
            }

            s32 Write(
                Socket& Connection, 
                const char* Buffer, 
                u32 Length)
            {
                s32 length = write(Connection.socketfd, Buffer, Length);
                if(length == -1)
                {
                    Exception::Raise(ExceptionType::SocketWrite);
                    return 0;
                }
                return length;
            }

            void SetOpt()
            {

            }

        private:
            bool open;
            u32 port;
            u32 socketfd;
            SocketDomain domain;
            SocketType type;
        };
    }
}
