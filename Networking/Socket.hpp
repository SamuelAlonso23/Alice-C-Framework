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

        enum class SocketReceiveFlag : u32
        {
            None,
            
        };
        
        enum class SocketSendFlag : u32
        {

        };

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
                if(close(socketfd) == -1)
                {
                    Exception::Raise(ExceptionType::SocketClose);
                }
            }

            Socket Accept() noexcept
            {

            }

            void Bind(const char* Host, const u32 Port) noexcept
            {

            }

            void Connect(const char* Host, const u32 Port) noexcept
            {

            }

            void Listen()
            {
                
            }

            void Receive(const Socket& Sender)
            {

            }

            void Send(const Socket& Receiver)
            {

            }

            void SetOpt()
            {

            }

        private:
            u32 socketfd;
        };
    }
}
