# HugeReal: Arbitrary-Precision Real Number Library 🚀

A C++ library for handling extremely large real numbers with arbitrary precision, supporting fundamental arithmetic operations and comparisons.

## Table of Contents
- [Features](#features-)
- [Installation](#installation-)
- [Usage](#usage-)
- [Build Instructions](#build-instructions-)
- [API Reference](#api-reference-)
- [Examples](#examples-)
- [Roadmap](#roadmap-)
- [Contributing](#contributing-)
- [License](#license-)
- [Contact](#contact-)

## Features ✨
- ➕➖✖️➗ Basic arithmetic operations (addition, subtraction, multiplication, division)
- 🔍 Precision handling for very large numbers (limited only by system memory)
- 📁 File I/O support for number storage and retrieval
- ↔️ Comparison operators (>, <, ==, !=)
- 🛠️ Error handling for invalid operations
- 🖥️ Cross-platform support (Windows/Linux/macOS)

## Installation ⚙️

### Prerequisites
- C++17 compatible compiler
- CMake 3.12+ (recommended)

### Clone Repository
```bash
git clone https://github.com/Abdullah-Masood-05/HugeReal.git
cd HugeReal
```

## Build Instructions 🛠️

### Using CMake (Recommended)
```bash
mkdir build && cd build
cmake ..
cmake --build .
```

### Visual Studio
1. Open `HugeReal.sln`
2. Build solution (Ctrl+Shift+B)

### Command Line
```bash
g++ -std=c++17 -o HugeReal main.cpp HugeReal.cpp
```

## Usage 💻

### Basic Operations
```cpp
#include "HugeReal.h"

int main() {
    HugeReal a("123456789.123456789");
    HugeReal b("987654321.987654321");
    
    // Arithmetic operations
    HugeReal sum = a + b;
    HugeReal product = a * b;
    
    // Comparisons
    if (a > b) {
        std::cout << "a is greater than b";
    }
    
    return 0;
}
```

### File I/O
```cpp
// Load numbers from file
HugeReal::loadFromFile("Source.txt");

// Save result to file
result.saveToFile("output.txt");
```

## API Reference 📚

| Method | Description |
|--------|-------------|
| `HugeReal(const string&)` | Constructor from string |
| `operator+` | Addition |
| `operator-` | Subtraction |
| `operator*` | Multiplication |
| `operator/` | Division |
| `compare()` | Comparison helper |
| `normalize()` | Internal formatting |
| `loadFromFile()` | Batch number loading |
| `saveToFile()` | Result persistence |

## Examples 📖

**Input (Source.txt):**
```
4
00000000000000111.11  # Parsed as 111.11
31
2222222333333333333333324344343
13413676897984784765895601934712478
```

**Sample Output:**
```
[1] 111.11
[2] 31
[3] 2222222333333333333333324344343
[4] 13413676897984784765895601934712478

Select operation:
1. Add [1] + [2] = 142.11
2. Multiply [3] * [4] = 297837554640562954421853443672440448074
```

## Roadmap 🗺️
- [ ] Decimal precision configuration
- [ ] Scientific notation support
- [ ] Serialization/Deserialization
- [ ] Performance optimizations
- [ ] Python bindings

## Contributing 🤝
1. Fork the repository
2. Create feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit changes (`git commit -m 'Add AmazingFeature'`)
4. Push to branch (`git push origin feature/AmazingFeature`)
5. Open Pull Request

## License 📄
MIT License - See [LICENSE](LICENSE) for details

[![License](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)

## Contact 📧
- Author: Your Name
- Email: your.email@example.com
- Issues: [GitHub Issues](https://github.com/yourusername/HugeReal/issues)

---
