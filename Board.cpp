#include <iostream>
#include "Board.hpp"
using namespace std;

namespace ariel
{
    void Board::post(unsigned int row, unsigned int column, Direction dierction, string message )
    {
        if (dierction == Direction::Horizontal)
        {
            maxcols= max(maxcols,column+ unsigned(message.length()));
            maxrow = max(maxrow,row);
        }
        else
        {
            maxrow = max(maxrow,row+ unsigned(message.length()));
            maxcols= max(maxcols,column);
        }
        minrow= min(minrow,row);
        mincols=min(mincols,column);
        
        for (unsigned int i = 0; i < message.length(); i++)
        {
            board[row][column] = message.at(i);
            if (dierction == Direction::Horizontal)
            {
               column++;
            }
            else
            {
                row++;
            }         
        }   
            
    }

    string Board::read(unsigned int row, unsigned int column, Direction dierction, unsigned int howMuch )
    {
        string ans;
        for (int i = 0; i < howMuch; i++)
        {
            if(board.find(row) == board.end() || board[row].find(column)== board[row].end())
            {
                ans.append("_");
            }
            else{
                ans.append(board[row][column]);
            }
            if (dierction == Direction::Horizontal)
            {
               column++;
            }
            else
            {
                row++;
            } 
        }
        
        return ans;
    }

    void Board::show()
    {
        for (unsigned int i = minrow; i <= maxrow; i++)
        {
            for (unsigned int j = mincols; j <= maxcols; j++)
            {
                if (!board[i][j].empty())
                {
                    cout << board[i][j];
                }
                else{
                    cout << "_";
                }
                    
            }
            cout<<endl;
        }
        
    }
} 

