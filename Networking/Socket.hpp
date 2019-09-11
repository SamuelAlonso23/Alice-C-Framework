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

/** @file Socket.hpp 
 *  @brief Contains Socket class and all related functions and enums
 *  @author John Patek
 */

namespace Alice
{
    namespace Networking
    {
        /** @enum SocketDomain
         * \author John Patek
         * @brief Strongly typed enum class representing the socket domain
         */
        enum class SocketDomain : u32
        {
            /*!\hideinitializer IPv4 Internet protocols */
            IPv4 = AF_INET,
            /*!\hideinitializer IPv6 Internet protocols */
            IPv6 = AF_INET6
        };

        /** @enum Alice::Networking::SocketType
         * \author John Patek
         * @brief Strongly typed enum class representing the socket domain
         */
        enum class SocketType : u32
        {
            /*! \hideinitializer Provides sequenced, reliable, 
                two-way, connection-based byte streams. */
            Stream = SOCK_STREAM,
            /*! \hideinitializer Supports connectionless, unreliable
                 messages of a fixed maximum length */
            Datagram = SOCK_DGRAM,
            /*! \hideinitializer Provides a sequenced, reliable, 
                two-way connection-based data transmission path for
                datagrams of fixed maximum length */
            SequencePacket = SOCK_SEQPACKET
        };

        /** @enum Alice::Networking::SocketOption
         * \author John Patek
         * @brief Strongly typed enum class representing the socket options
         */
        enum class SocketOption : u32
        {
            /*! \hideinitializer */
            Domain = SO_DOMAIN,
            /*! \hideinitializer */
            Error = SO_ERROR,
            /*! \hideinitializer */
            Mark = SO_MARK,
            /*! \hideinitializer */
            Priority = SO_PRIORITY,
            /*! \hideinitializer */
            ReceiveBuffer = SO_RCVBUF,
            /*! \hideinitializer */
            SendBuffer = SO_SNDBUF
        };
        
        /** @enum Alice::Networking::SocketFlag
         * \author John Patek
         * @brief Strongly typed enum class representing the socket flags
         */
        enum class SocketFlag : u32
        {
            /*! \hideinitializer */
            AcceptConnection = SO_ACCEPTCONN,
            /*! \hideinitializer */
            BindToDevice = SO_BINDTODEVICE,
            /*! \hideinitializer */
            Broadcast = SO_BROADCAST,
            /*! \hideinitializer */
            Debug = SO_DEBUG,
            /*! \hideinitializer */
            DoNotRoute = SO_DONTROUTE,
            /*! \hideinitializer */
            KeepAlive = SO_KEEPALIVE,
            /*! \hideinitializer */
            Linger = SO_LINGER,
            /*! \hideinitializer */
            OutOfBandInline = SO_OOBINLINE,
            /*! \hideinitializer */
            PassCredentials = SO_PASSCRED,
            /*! \hideinitializer */
            PeerCredentials = SO_PEERCRED,
            /*! \hideinitializer */
            ReuseAddress = SO_REUSEADDR,
            /*! \hideinitializer */
            ReusePort = SO_REUSEPORT,
            /*! \hideinitializer */
            TimeStamp = SO_TIMESTAMP
        };

        /** @enum Alice::Networking::SocketReceiveFlag
         * \author John Patek
         * @brief Strongly typed enum class representing the socket receive flags
         */
        enum class SocketReceiveFlag : u32
        {
            /*! \hideinitializer */
            DoNotWait = MSG_DONTWAIT,
            /*! \hideinitializer */
            ErrorQueue = MSG_ERRQUEUE,
            /*! \hideinitializer */
            OutOfBand = MSG_OOB,
            /*! \hideinitializer */
            Peek = MSG_PEEK,
            /*! \hideinitializer */
            Truncate = MSG_TRUNC,
            /*! \hideinitializer */
            WaitAll = MSG_WAITALL
        };
        
        /** @enum Alice::Networking::SocketSendFlag
         * \author John Patek
         * @brief Strongly typed enum class representing the socket send flags
         */
        enum class SocketSendFlag : u32
        {
            /*! \hideinitializer */
            Confirm = MSG_CONFIRM,
            /*! \hideinitializer */
            DoNotRoute = MSG_DONTROUTE,
            /*! \hideinitializer */
            DoNotWait = MSG_DONTWAIT,
            /*! \hideinitializer */
            EndOfRecord = MSG_EOR,
            /*! \hideinitializer */
            More = MSG_MORE,
            /*! \hideinitializer */
            NoSignal = MSG_NOSIGNAL,
            /*! \hideinitializer */
            OutOfBand = MSG_OOB
        };
        
        /** @class Alice::Networking::Socket
         * @author John Patek
         * @brief Class encapsulating an Alice styled a wrapper for a Unix socket.
         */
        class Socket
        {
        public:

            /**
             * @author John Patek
             * @brief Constructs an uninitialized Socket 
             * object.
             */ 
            Socket() noexcept {}

            /**
             * @author John Patek
             * @brief Constructs a Socket object given a domain and
             * a type. Attempts to open Socket once it has been 
             * created.
             */ 
            Socket(
                const SocketDomain& Domain,
                const SocketType& Type) noexcept
            {
                Open(Domain,Type);    
            }

            /**
             * @author John Patek
             * @brief Overrides copy constructor, calling delete
             * to prevent Socket from being copied.
             */ 
            Socket(const Socket& Other) = delete;

            /**
             * @author John Patek
             * @brief Constructs Socket from another Socket rvalue.
             */ 
            Socket(Socket&& Other) noexcept 
            {
                socketfd = Other.socketfd;
                domain = Other.domain;
                type = Other.type;
                open = Other.open;
            }

            /**
             * @author John Patek
             * @brief Destroys Socket, closing the Socket if necessary.
             */
            ~Socket()
            {
                if(open)
                {
                    Close();
                }
            }

            /**
             * @author John Patek
             * @brief Accept a connection on this Socket
             * @exception ExceptionType::SocketAccept if the Socket fails to accept the connection
             * @return A socket representing the newly accepted
             * connection.
             */
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
            
            /**
             * @author John Patek
             * @brief Bind Socket to a given port number
             * @exception ExceptionType::SocketBind if port number
             * is invalid or Socket fails to bind to it.
             * @param[in] Port Desired port number Socket is to be
             * bound to.
             */
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
            
            /**
             * @author John Patek
             * @brief Close Socket
             * @exception ExceptionType::SocketClose the if Socket is
             * unable to close the underlying connection handle.
             */
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

            /**
             * @author John Patek
             * @brief Connect Socket to a given host and port number.
             * @exception ExceptionType::SocketConnect if Socket is
             * unable to connect to the given host and port.
             * @param[in] Host IPv4 or IPv6 host. Must match domain.
             * @param[in] Port port number to on which the connection
             * is to be established.
             */
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

            /**
             * @author John Patek
             * @brief Set flags for the Socket object.
             * @exception ExceptionType::SocketSetFlag if Socket is
             * unable to set the specific flag.
             * @param[in] Flag SocketFlag to be set by the Socket
             * object
             * @param[in] Value bool value indicating if the flag is
             * to be turned on or off
             */
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

            /**
             * @author John Patek
             * @brief Set option values for the Socket object.
             * @exception ExceptionType::SocketSetOption if Socket is
             * unable to set the specific option.
             * @param[in] Option SocketOption to be set by the Socket
             * object
             * @param[in] Value u32 value representing the integer
             * value to be stored for this Socket option
             */
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
