#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include "server.hpp"
#include <arken/base>
#include <arken/mvm.h>
#include <arken/net/httpserver.h>

using HttpServer = arken::net::HttpServer;
using mvm    = arken::mvm;


//-----------------------------------------------------------------------------
// HTTP SERVER RUN
//-----------------------------------------------------------------------------

void HttpServer::run()
{
  std::cout << "start arken.net.HttpServer (enceladus) " << m_address <<
    ":" << m_port << " (" << m_threads << ") threads..." << std::endl;

  try
  {
    // Check command line arguments.
    /*
    if (argc != 4)
    {
      std::cerr << "Usage: http_server <address> <port> <doc_root>\n";
      std::cerr << "  For IPv4, try:\n";
      std::cerr << "    receiver 0.0.0.0 80 .\n";
      std::cerr << "  For IPv6, try:\n";
      std::cerr << "    receiver 0::0 80 .\n";
      return 1;
    }
    */

    //Config c("config/enceladus.json");
    //std::cout << "start enceladus " << c.address() << ":" << c.port() <<
    //  " (" << c.threads() << ") threads..." << std::endl;
    // Initialise the server.
    //http::server::server s(c.address(), std::to_string(c.port()), "public");
    std::string host(m_address.data());
    std::string port(std::to_string(m_port));
    http::server2::server s(host, port, "public", m_threads);


    // Run the server until stopped.
    s.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "exception: " << e.what() << "\n";
  }

}

