# ENCELADUS

Web server async multithreading based on boost api.

## MODEL
Enceladus is base in boost examples: https://www.boost.org/doc/libs/1_63_0/doc/html/boost_asio/examples.html

- model 1 
An HTTP server using an asio in a simple single-threaded server.

- model 2
An HTTP server using an io_service-per-CPU design. (Many threads is better)

- model 3 (default)
An HTTP server using a single io_service and a thread pool calling io_service::run(). (One Thread per cpu is better)

## BUILD

apt-get install libboost-all-dev

- clone in package directory
```
cd arkenplatform
git clone git@github.com:arkenplatform/titan.git packages/enceladus
Cloning into 'packages/enceladus'...
remote: Enumerating objects: 30, done.
remote: Counting objects: 100% (30/30), done.
remote: Compressing objects: 100% (22/22), done.
remote: Total 30 (delta 10), reused 25 (delta 5), pack-reused 0
Receiving objects: 100% (30/30), 65.68 KiB | 0 bytes/s, done.
Resolving deltas: 100% (10/10), done.
Checking connectivity... done.
```

- build  project

```
mkdir build
cd build
cmake ..
make -j4 (4 is number of cores)


ARKEN BACKEND...........: qt
ARKEN BASE64............: qt
ARKEN DIGEST............: qt
ARKEN MVM CONTAINER.....: deque-stack
ARKEN OS FILESYSTEM.....: qt
ARKEN OS UUID...........: qt
ARKEN REGEX.............: qt
ARKEN UTF8..............: qt
PACKAGE: titan
PACKAGE: callisto
PACKAGE: enceladus
ENCELADUS CONCURRENCY MODEL.....: model-3
-- Boost version: 1.55.0
-- Found the following Boost libraries:
--   system
--   thread
-- Configuring done
-- Generating done
-- Build files have been written to: /home/ariveira/projetos/arken/build

Building CXX object packages/miranda/CMakeFiles/enceladus.dir/src/main.cpp.o
Linking CXX executable ../../../bin/enceladus
Built target enceladus

```

### Config
config/enceladus.json

```
{
  "port"    : 2345,
  "threads" : 5,
  "pid"     : "tmp/pid/enceladus.pid"
}

```

## LICENSE
This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
