#include <string>
#include "Direction.hpp"
#include <climits>
#include <map>

using namespace std;

namespace ariel{
    class Board{
    private:
        unsigned int maxrow=0;
        unsigned int minrow=UINT_MAX;
        unsigned int maxcols=0;
        unsigned int mincols=UINT_MAX;
        std::map<unsigned int,std::map<unsigned int,string>> board;
    public:
        void post(unsigned int row, unsigned int column, Direction dierction, string message);
        string read(unsigned int row, unsigned int column, Direction dierction, unsigned int howMuch);
        void show();
    };
}