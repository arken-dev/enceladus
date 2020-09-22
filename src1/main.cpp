//
// main.cpp
// ~~~~~~~~
//
// Copyright (c) 2003-2016 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "server.hpp"
#include <arken/base>

using mvm    = arken::mvm;
using Config = arken::net::Config;

int main(int argc, char* argv[])
{
  mvm::init(argc, argv);
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

    Config c("config/enceladus.json");
    std::cout << "start enceladus " << c.address() << ":" << c.port() <<
      " (" << c.threads() << ") threads..." << std::endl;
    // Initialise the server.
    http::server::server s(c.address(), std::to_string(c.port()), "public");

    // Run the server until stopped.
    s.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "exception: " << e.what() << "\n";
  }

  return 0;
}
