#include <string>
#include "Direction.hpp"

using namespace std;

namespace ariel{
    class Board{
        unsigned int rows;
        unsigned int cols;
    public:
        static void post(unsigned int row, unsigned int column, Direction dierction, string info);
        static string read(unsigned int row, unsigned int column, Direction dierction, unsigned int howMuch);
        void show();
    };
}