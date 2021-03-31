# String

A string builder implemented using memmove for crafting.

# Installation

* Install the library

`em list`

`em install`

`em build lib`

## Usage

* Include in a file

`touch test.c`
```c
#include "export/String.h"
int main(void) {
}
```

* Compile

`clang test.c export/*.*o $(find ../libs -name "*.*o" | xargs ls -d)`

## Development

* Write tests

## Contributing

1. Fork it (<https://github.com/EmeraldsFramework/String/fork>)
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request

## Contributors

- [Oblivious](https://github.com/Oblivious-Oblivious) - creator and maintainer
