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

            }

            void Bind(const char* Host, const u32 Port) noexcept
            {
                sockaddr address;
                if(bind(socketfd,&address,sizeof(address)) == -1)
                {
                    Exception::Raise(ExceptionType::SocketClose);
                }
            }

            void Close()
            {
                if(close(socketfd) == -1)
                {
                    Exception::Raise(ExceptionType::SocketClose);
                }
            }

            void Connect(const char* Host, const u32 Port) noexcept
            {

            }

            void Listen()
            {
                
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
            u32 socketfd;
            SocketDomain domain;
            SocketType type;
        };
    }
}
