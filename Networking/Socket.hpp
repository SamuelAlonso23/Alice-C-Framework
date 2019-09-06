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
            IPv4,
            IPv6
        };

        enum class SocketType : u32
        {
            Stream,
            Datagram,
            SequencePacket
        };

        class Socket
        {
        public:
            Socket() noexcept {}

            Socket(
                const SocketDomain& Domain,
                const SocketType& Type) noexcept
            {
                u32 domain;
                u32 type;
                
                socketfd = socket(
                    domain, 
                    type, 
                    0);
                 if(socketfd == -1)
                 {
                     Exception::Raise(ExceptionType::SocketOpen);
                 }
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

            
        private:
            u32 socketfd;
        };
    }
}
