# buckler

The framework for malice blocker.  

Malice blocker block malicious data, file or packet.  
(For example, antivirus and WAF are malice blocker.  )

## Getting Started

### Dependencies
Please install them before install buckler.

* boost
* yaml-cpp
* [armoury(Package manager for buckler)](https://github.com/buckler-project/armoury)

And now, it support only Linux.  
(it will support Windows for the future.)

### Installing

First, we have to clone from the repository.

```shell
$ git clone https://github.com/buckler-project/buckler
$ cd ./buckler
```

Then run `make`, and `make install`.

```shell
$ make
$ sudo make install
```

### Example

#### 1. Init project
First, make projects.

```sh
$ mkdir antivirus && cd antivirus
$ armoury install blocker
```


#### 2. Write code and build
Second, write source code as below.

```cpp
// antivirus.cc

#include <iostream>
#include <cstdlib>

#include <buckler/buckler.hpp>
#include <buckler/base.hpp>


int main(int argc, char* argv[]) {
    if (argc < 1) {
        std::cerr << "[err] argument not found." << std::endl;
        std::exit(1);
    }

    std::vector<unsigned char> buffer = {};

    std::fstream fs;

    fs.open(argv[1], std::ios::in | std::ios::binary);
    char data;

    if (fs.fail()) {
        std::cerr << "failed to open file\n" << std::endl;
        std::exit(1);
    }

    while(!fs.eof()){
        fs.read(&data, sizeof(char));
        buffer.push_back(data);
    }
    buffer.pop_back();

    // make target
    auto target = buckler::Target(buffer);
    auto buckler = buckler::Buckler(target);

    // load
    buckler.Load();

    // scan
    auto result = buckler.Scan();
    if (result.has_hit) {
        std::cout << "`" << argv[1]
            << "` is malware." << std::endl;
    } else {
        std::cout << "`"<< argv[1]
            << "` is not malware." << std::endl;
    }
}
```

And build it.
```sh
g++ -lpthread -lboost_system -lboost_filesystem -lyaml-cpp -ldl -lbuckler -g -Wall -std=c++17 -fPIC ./antivirus.cc -o ./antivirus 
```

#### 3. Install scanners and signatures
Then install packages of scanner and signature.  
(The scanners will have been auto configurated.)

```sh
echo "y" | armoury install signature buckler-project/sample-signature
```

#### 4. Run
Run command to run antivirus.

```sh
./antivirus TARGET_FILE
```

If your TARGET_FILE's hash hits [signature file](`https://github.com/buckler-project/sample-signature/blob/master/data/md5.line`) `./antivirus`, say hits.
