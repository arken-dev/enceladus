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
#include <boost/lexical_cast.hpp>
#include "server.hpp"
#include <charon/base>

using mvm    = charon::mvm;
using Config = charon::net::Config;

int main(int argc, char* argv[])
{
  mvm::init(argc, argv);
  try
  {

    // Check command line arguments.
    /*
    if (argc != 5)
    {
      std::cerr << "Usage: http_server <address> <port> <threads> <doc_root>\n";
      std::cerr << "  For IPv4, try:\n";
      std::cerr << "    receiver 0.0.0.0 80 1 .\n";
      std::cerr << "  For IPv6, try:\n";
      std::cerr << "    receiver 0::0 80 1 .\n";
      return 1;
    }
    */

    // Initialise the server.
    //std::size_t num_threads = boost::lexical_cast<std::size_t>(argv[3]);
    //http::server2::server s(argv[1], argv[2], argv[4], num_threads);

    Config c("config/enceladus.json");
    std::cout << "enceladus start ";
    std::cout << " address " << c.address();
    std::cout << " port "    << c.port();
    std::cout << " threads " << c.threads();
    std::cout << std::endl;
    http::server2::server s(c.address(), c.port(), "/", c.threads());

    // Run the server until stopped.
    s.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "exception: " << e.what() << "\n";
  }

  return 0;
}