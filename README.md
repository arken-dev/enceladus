# ENCELADUS

Web server async multithreading based on boost api.


## BUILD

apt-get install libboost-all-dev

- clone in package directory
```
cd charonplatform
git clone git@github.com:charonplatform/titan.git packages/enceladus
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


CHARON BACKEND...........: qt
CHARON BASE64............: qt
CHARON DIGEST............: qt
CHARON MVM CONTAINER.....: deque-stack
CHARON OS FILESYSTEM.....: qt
CHARON OS UUID...........: qt
CHARON REGEX.............: qt
CHARON UTF8..............: qt
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
-- Build files have been written to: /home/ariveira/projetos/charon/build

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
