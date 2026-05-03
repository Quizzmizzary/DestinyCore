#ifndef AsioHacksFwd_h__
#define AsioHacksFwd_h__

#include <boost/version.hpp>

/**
  Collection of forward declarations to improve compile time
 */
namespace boost
{
    namespace posix_time
    {
        class ptime;
    }

    namespace asio
    {
        template <typename Time>
        struct time_traits;

        namespace ip
        {
            class address;

            class tcp;

            template <typename InternetProtocol>
            class basic_endpoint;

            typedef basic_endpoint<tcp> tcp_endpoint;
        }

#if BOOST_VERSION >= 107000
        class executor;

        namespace ip
        {
            template <typename InternetProtocol, typename Executor>
            class basic_resolver;

            typedef basic_resolver<tcp, executor> tcp_resolver;
        }
#elif BOOST_VERSION >= 106600
        namespace ip
        {
            template <typename InternetProtocol>
            class basic_resolver;

            typedef basic_resolver<tcp> tcp_resolver;
        }
#else
        namespace ip
        {
            template <typename InternetProtocol>
            class resolver_service;

            template <typename InternetProtocol, typename ResolverService>
            class basic_resolver;

            typedef basic_resolver<tcp, resolver_service<tcp>> tcp_resolver;
        }
#endif
    }
}

namespace Trinity
{
    namespace Asio
    {
        class IoContext;
        class Strand;
    }
}

#endif // AsioHacksFwd_h__