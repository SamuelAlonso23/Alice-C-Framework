#include <Basic/NoDefault.hpp>
#include <Basic/Types.hpp>
#include <Collections/Generic/List.hpp>
#include <Configuration.hpp>
#include <Core/Exception.hpp>


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
            Domain = SO_DOMAIN,
            Error = SO_ERROR,
            Mark = SO_MARK,
            Priority = SO_PRIORITY,
            ReceiveBuffer = SO_RCVBUF,
            SendBuffer = SO_SNDBUF
        };

        enum class SocketFlag : u32
        {
            AcceptConnection = SO_ACCEPTCONN,
            BindToDevice = SO_BINDTODEVICE,
            Broadcast = SO_BROADCAST,
            Debug = SO_DEBUG,
            DoNotRoute = SO_DONTROUTE,
            KeepAlive = SO_KEEPALIVE,
            Linger = SO_LINGER,
            OutOfBandInline = SO_OOBINLINE,
            PassCredentials = SO_PASSCRED,
            PeerCredentials = SO_PEERCRED,
            ReuseAddress = SO_REUSEADDR,
            ReusePort = SO_REUSEPORT,
            TimeStamp = SO_TIMESTAMP
        };

        enum class SocketReceiveFlag : u32
        {
            DoNotWait = MSG_DONTWAIT,
            ErrorQueue = MSG_ERRQUEUE,
            OutOfBand = MSG_OOB,
            Peek = MSG_PEEK,
            Truncate = MSG_TRUNC,
            WaitAll = MSG_WAITALL
        };
        
        enum class SocketSendFlag : u32
        {
            Confirm = MSG_CONFIRM,
            DoNotRoute = MSG_DONTROUTE,
            DoNotWait = MSG_DONTWAIT,
            EndOfRecord = MSG_EOR,
            More = MSG_MORE,
            NoSignal = MSG_NOSIGNAL,
            OutOfBand = MSG_OOB
        };

        class Socket
        {
        public:
            Socket() noexcept {}

            Socket(
                const SocketDomain& Domain,
                const SocketType& Type) noexcept
            {
                Open(Domain,Type);    
            }

            Socket(const Socket& Other) = delete;

            Socket(Socket&& Other) noexcept 
            {
                socketfd = Other.socketfd;
                domain = Other.domain;
                type = Other.type;
                open = Other.open;
            }

            ~Socket()
            {
                if(open)
                {
                    Close();
                }
            }

            Socket Accept() noexcept
            {
                Socket client;
                s32 result(-1);
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
                else
                {
                    client.socketfd = result;
                    client.open = true;
                    client.port = port;
                    client.domain = domain;
                    client.type = type;   
                }
                return client;
            }

            void Bind(const u32 Port) noexcept
            {
                s32 result(-1);
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
                else
                {
                    port = Port;
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
                s32 result(-1);
                if(domain == SocketDomain::IPv4)
                {
                    sockaddr_in address;
                    address.sin_family = AF_INET;
                    address.sin_port = htons(Port);
                    inet_pton(AF_INET,Host,&address.sin_addr);
                    result = connect(socketfd,(sockaddr*)&address,sizeof(address));
                }   
                else if(domain == SocketDomain::IPv6)
                {
                    sockaddr_in6 address;
                    address.sin6_family = AF_INET6;
                    address.sin6_port = htons(Port);
                    inet_pton(AF_INET6,Host,&address.sin6_addr);
                    result = connect(socketfd,(sockaddr*)&address,sizeof(address));
                }

                if(result == -1)
                {
                    Exception::Raise(ExceptionType::SocketConnect);
                }
                else
                {
                    port = Port;
                }       
            }

            bool GetFlag(const SocketFlag& Flag) const
            {
                u32 flag(0);
                u32 size = sizeof(Flag);

                if(getsockopt(
                       socketfd,
                       SOL_SOCKET,
                       static_cast<u32>(Flag),
                       &flag,
                       (socklen_t*)&size) == -1)
                {
                    Exception::Raise(ExceptionType::SocketGetFlag);
                }

                return flag > 0;
            }

            u32 GetOption(const SocketOption& Option) const
            {
                u32 option(0);
                u32 size = sizeof(Option);

                if(getsockopt(
                       socketfd,
                       SOL_SOCKET,
                       static_cast<u32>(Option),
                       &option,
                       (socklen_t*)&size) == -1)
                {
                    Exception::Raise(ExceptionType::SocketGetOption);
                }
                
                return option;
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
                char* Buffer,
                u32 Length)
            {
                s32 length = read(socketfd, Buffer, Length);
                if(length == -1)
                {
                    Exception::Raise(ExceptionType::SocketRead);
                    return 0;
                }
                return length;
            }

            s32 Receive(
                char* Buffer, 
                const u32 Length, 
                Alice::Collections::Generic::List<SocketReceiveFlag> ReceiveFlags)
            {
                s32 length;
                u32 flags(0);
                for(u32 index = 0; index < ReceiveFlags.Size(); index++)
                {
                    flags |= static_cast<u32>(ReceiveFlags[index]);
                }
                length = recv(socketfd, Buffer, Length, flags);
                if(length == -1)
                {
                    Exception::Raise(ExceptionType::SocketReceive);
                }
                return length;
            }

            s32 Send(
                const char* Buffer, 
                const u32 Length, 
                Alice::Collections::Generic::List<SocketSendFlag> SendFlags)
            {
                s32 length;
                u32 flags(0);
                for(u32 index = 0; index < SendFlags.Size(); index++)
                {
                    flags |= static_cast<u32>(SendFlags[index]);
                }
                length = send(socketfd, Buffer, Length, flags);
                if(length == -1)
                {
                    Exception::Raise(ExceptionType::SocketSend);
                }
                return length;
            }

            void SetFlag(const SocketFlag& Flag, const bool Value)
            {
                u32 value = Value ? 1 : 0;
                if(setsockopt(
                       socketfd, 
                       SOL_SOCKET,
                       static_cast<u32>(Flag),
                       &value,
                       sizeof(value)) == -1)
                {
                    Exception::Raise(ExceptionType::SocketSetFlag);
                }
            }

            void SetOption(const SocketOption& Option, const u32 Value)
            {
                if(setsockopt(
                       socketfd, 
                       SOL_SOCKET, 
                       static_cast<u32>(Option),
                       &Value,
                       sizeof(Value)) == -1)
                {
                    Exception::Raise(ExceptionType::SocketSetOption);
                }
            }

            s32 Write(
                const char* Buffer, 
                u32 Length)
            {
                s32 length = write(socketfd, Buffer, Length);
                if(length == -1)
                {
                    Exception::Raise(ExceptionType::SocketWrite);
                    return 0;
                }
                return length;
            }

            Socket& operator=(const Socket& rhs) = delete;

            Socket& operator=(Socket&& rhs)
            {
                socketfd = rhs.socketfd;
                domain = rhs.domain;
                type = rhs.type;
                open = rhs.open;
            }

        private:
            bool open;
            s32 socketfd;
            u32 port;
            SocketDomain domain;
            SocketType type;
        };
    }
}
