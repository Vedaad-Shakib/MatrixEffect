#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>

using namespace std;

const int width = 158;        // Width of terminal window
const int flipsPerLine = 5;    // No. of columns changed per line
const int millisecondsOfSleep = 50; // Delay between lines in millisecond
int main() {
  srand(time_t(NULL));
  bool switches[width] = { true };
  const string garbage = "1234567890/*-+.,./;[]\\=_~`!@#$%^&*()";
  const auto glen = garbage.size();
  while (true) {        // Waiting for Ctrl-C
    for (int i = 0; i != width; ++i) {
      if (switches[i]) {
	cout << garbage[rand() % glen];
      } else {
	cout << ' ';
      }
    }
    cout << endl;
    for (int i = 0; i != flipsPerLine; ++i) {
      int x = rand() % width;
      switches[x] = !switches[x];
      // Flipping switches
    }
    this_thread::sleep_for(chrono::milliseconds(millisecondsOfSleep));
  }
  return 0;
}
