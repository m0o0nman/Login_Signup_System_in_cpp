#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void print_welcome_blocks() {
    cout << "\n";
    cout << "██╗    ██╗███████╗██╗      ██████╗ ██████╗ ███╗   ███╗███████╗\n";
    std::this_thread::sleep_for(chrono::microseconds(500));
    cout << "██║    ██║██╔════╝██║     ██╔════╝██╔═══██╗████╗ ████║██╔════╝\n";
    this_thread::sleep_for(chrono::microseconds(500));
    cout << "██║ █╗ ██║█████╗  ██║     ██║     ██║   ██║██╔████╔██║█████╗  \n";
    this_thread::sleep_for(chrono::microseconds(500));
    cout << "██║███╗██║██╔══╝  ██║     ██║     ██║   ██║██║╚██╔╝██║██╔══╝  \n";
    this_thread::sleep_for(chrono::microseconds(500));
    cout << "╚███╔███╔╝███████╗███████╗╚██████╗╚██████╔╝██║ ╚═╝ ██║███████╗\n";
    this_thread::sleep_for(chrono::microseconds(500));
    cout << " ╚══╝╚══╝ ╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝\n";
    this_thread::sleep_for(chrono::microseconds(500));
    cout << "\n";
}

int main() {
    print_welcome_blocks();

}