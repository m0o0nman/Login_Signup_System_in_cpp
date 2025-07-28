# 🔐 Login & Signup System in C++

A comprehensive user authentication system built in C++ that demonstrates fundamental Object-Oriented Programming (OOP) principles, modern C++ features, and secure password management techniques. This project serves as an excellent learning resource for understanding C++ fundamentals while implementing a real-world application.

## 📚 Learning Objectives & C++ Fundamentals Demonstrated

### Object-Oriented Programming (OOP) Concepts

#### 1. **Encapsulation**
The `Login_Signup` class perfectly demonstrates encapsulation by:
- **Private Data Members**: Core data structures (`user_database`, `filename`) are kept private, ensuring data integrity
- **Private Helper Methods**: Sensitive operations like `generate_salt()` and `generate_hash()` are encapsulated as private static methods
- **Public Interface**: Only necessary methods are exposed through the public interface

```cpp
class Login_Signup {
private:
    string filename;
    unordered_map<string, pair<string, string>> user_database;
    
    // Private helper methods for security
    static string generate_salt(size_t length = 7);
    static string generate_hash(const string& password, const string& salt);

public:
    // Public interface for user interaction
    bool register_user(string username, string password, const string& filename);
    bool verify_login(const string& username, const string& password);
};
```

#### 2. **Abstraction**
The system abstracts complex cryptographic operations:
- Users interact with simple `register_user()` and `verify_login()` methods
- Complex hashing, salting, and file I/O operations are hidden from the user
- Clean separation between interface and implementation

#### 3. **Constructor Implementation**
Demonstrates proper constructor usage with parameter initialization:
```cpp
Login_Signup(unordered_map<string, pair<string, string>>& ud, string& fn);
```

### Modern C++ Features & Standard Library Usage

#### 1. **STL Containers**
- **`unordered_map<string, pair<string, string>>`**: Efficient O(1) average-case lookup for user authentication
- **`pair<string, string>`**: Elegant storage of salt and hashed password combinations

#### 2. **C++20 Features**
- **`contains()` method**: Modern container lookup (requires C++20)
```cpp
bool Login_Signup::username_exists(const string& username) const {
    return user_database.contains(username);  // C++20 feature
}
```

#### 3. **Advanced String Manipulation**
- **String streams**: Converting hash values to hexadecimal representation
- **Substring operations**: Parsing colon-delimited file format
- **String searching**: Using `find()` and `npos` for robust parsing

#### 4. **Random Number Generation**
Modern C++ random number generation using:
```cpp
mt19937 generator(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> dist(0, char_set.size() - 1);
```

#### 5. **File I/O Operations**
- **`ifstream`** and **`ofstream`**: Robust file handling with error checking
- **Persistent data storage**: User data survives program restarts

## 🚀 Key Features

### 🔒 Security Features

#### 1. **Cryptographic Salt Generation**
- **Random salt generation**: Each password gets a unique 7-character salt
- **Mersenne Twister PRNG**: High-quality randomness using `mt19937`
- **Time-based seeding**: Uses system clock for entropy

```cpp
string Login_Signup::generate_salt(const size_t length) {
    static const string char_set = "012345678ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    mt19937 generator(chrono::steady_clock::now().time_since_epoch().count());
    // ... salt generation logic
}
```

#### 2. **Password Hashing**
- **SHA-based hashing**: Uses `std::hash<string>` for password security
- **Salt + Password combination**: Prevents rainbow table attacks
- **Hexadecimal storage**: Clean, readable hash representation

#### 3. **Input Validation**
- **Duplicate username prevention**: Checks existing usernames before registration
- **Empty field validation**: Prevents registration with empty credentials
- **Robust error handling**: Comprehensive error messages and validation

### 💾 Data Persistence

#### 1. **File-Based Storage**
- **Colon-delimited format**: `username:salt:hashed_password`
- **Automatic file creation**: Creates user database file if it doesn't exist
- **Data integrity**: Validates file format during loading

#### 2. **Memory Management**
- **Efficient data structures**: Uses hash tables for O(1) lookups
- **Automatic resource management**: RAII principles for file handling

### 🎯 User Experience Features

#### 1. **Interactive Console Interface**
- **Menu-driven navigation**: Clear options for Register/Login/Exit
- **Input validation**: Ensures valid menu selections
- **User-friendly prompts**: Clear instructions and feedback

#### 2. **Comprehensive Error Handling**
- **File operation errors**: Graceful handling of file I/O failures
- **Authentication failures**: Clear error messages for login attempts
- **Registration conflicts**: Informative messages for duplicate usernames

## 🛠️ Technical Implementation Details

### Data Structure Design
```cpp
unordered_map<string, pair<string, string>> user_database;
//             ^key    ^salt  ^hashed_password
```
- **Key**: Username (unique identifier)
- **Value**: Pair containing salt and hashed password
- **Efficiency**: O(1) average-case lookup and insertion

### File Format Specification
```
username1:randomSalt1:hashedPassword1
username2:randomSalt2:hashedPassword2
```

### Security Architecture
1. **Registration Flow**:
   ```
   User Input → Salt Generation → Password + Salt → Hash Function → Storage
   ```

2. **Authentication Flow**:
   ```
   User Input → Retrieve Salt → Hash Input + Salt → Compare with Stored Hash
   ```

## 📋 Prerequisites

- **C++ Compiler**: Supporting C++20 standard (GCC 10+, Clang 10+, MSVC 2019+)
- **CMake**: Version 3.15 or higher (optional, for build management)
- **Operating System**: Windows, Linux, or macOS

## 🚀 Getting Started

### Compilation

#### Using g++ (Direct compilation):
```bash
g++ -std=c++20 -o login_system main.cpp Login_Signup.cpp
```

#### Using CMake:
```bash
mkdir build && cd build
cmake ..
make
```

### Running the Application
```bash
./login_system  # Linux/macOS
login_system.exe  # Windows
```

## 💡 Usage Examples

### Registration Process
```
=== === === === === Welcome === === === === ===

1. Register
2. Login
3. Exit
Enter your option: 1
Enter username: john_doe
Enter password: mySecurePassword123
Registration Successful
 Welcome john_doe
```

### Login Process
```
1. Register
2. Login
3. Exit
Enter your option: 2
Enter username: john_doe
Enter password: mySecurePassword123
Login successful! Welcome john_doe
```

### Error Handling Examples
```
Enter username: john_doe
Username already exists, try something else

Enter username: existing_user
Enter password: wrongPassword
   Username not found
Wrong password! Try again.
```

## 🏗️ Project Structure

```
Login_Signup_system_in_cpp/
├── main.cpp              # Main application entry point
├── Login_Signup.h        # Class declaration and interface
├── Login_Signup.cpp      # Class implementation
├── CMakeLists.txt        # Build configuration
├── user_data.txt         # User database file (auto-generated)
└── README.md            # Project documentation
```

## 🎓 Educational Value

### For Beginners
- **OOP Fundamentals**: Clear demonstration of classes, encapsulation, and data hiding
- **STL Usage**: Practical application of containers, iterators, and algorithms
- **File I/O**: Real-world file handling with error management
- **String Processing**: Advanced string manipulation techniques

### For Intermediate Developers
- **Security Concepts**: Understanding of salting, hashing, and secure storage
- **Modern C++**: Usage of C++20 features and best practices
- **Error Handling**: Comprehensive error management strategies
- **Code Organization**: Professional project structure and documentation

### Advanced Concepts Demonstrated
- **Cryptographic Principles**: Salt generation and password hashing
- **Data Structure Selection**: Choosing appropriate containers for performance
- **Memory Management**: RAII and automatic resource management
- **Cross-platform Compatibility**: Standard library usage for portability

## 🔧 Potential Enhancements

### Security Improvements
- Integration with stronger hashing algorithms (bcrypt, Argon2)
- Password strength validation
- Account lockout mechanisms
- Session management

### Feature Extensions
- User profile management
- Password reset functionality
- Multi-factor authentication
- Database integration (SQLite, MySQL)

### Technical Improvements
- Unit testing framework integration
- Logging system implementation
- Configuration file support
- GUI interface development

## 🤝 Contributing

This project welcomes contributions that enhance its educational value:

1. **Code Improvements**: Optimize algorithms or add new features
2. **Documentation**: Enhance comments and explanations
3. **Security Enhancements**: Implement additional security measures
4. **Cross-platform Support**: Ensure compatibility across different systems

## 📄 License

This project is designed for educational purposes and is available under the MIT License. Feel free to use, modify, and distribute for learning and teaching C++ programming concepts.

## 🎯 Conclusion

This Login & Signup System serves as a comprehensive example of applying C++ and OOP principles to solve real-world problems. It demonstrates how theoretical concepts translate into practical, secure, and maintainable code. Whether you're learning C++ fundamentals or exploring advanced programming concepts, this project provides valuable insights into professional software development practices.

The implementation showcases the power of C++'s standard library, the importance of security in user authentication systems, and the elegance of object-oriented design in creating maintainable and extensible software solutions.
