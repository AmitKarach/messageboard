#include <iostream>
#include "Board.hpp"
using namespace std;

namespace ariel
{
    //here we are posting a note on the board
    void Board::post(unsigned int row, unsigned int column, Direction dierction, string message )
    {
        //we are cheaching if this post is farther then the max note that there is on the board
        //we will use that in Show()
        if (dierction == Direction::Horizontal)
        {
            maxcols= max(maxcols,column+ unsigned(message.length()-1));
            maxrow = max(maxrow,row);
        }
        else
        {
            maxrow = max(maxrow,row+ unsigned(message.length()-1));
            maxcols= max(maxcols,column);
        }
        minrow= min(minrow,row);
        mincols=min(mincols,column);
        
        //we are going through the message and puting it on the board 
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

    //here we are reading a post from the board
    string Board::read(unsigned int row, unsigned int column, Direction dierction, unsigned int howMuch )
    {
        //we will add to this ans string every note we will find and if we get to a place there is no letter we put "_" insted
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
    //this will print the board we have 
    //we are starting at the min messege and from there we will go up
    //thats why if there is only a messege in line 1000 we wont start from line 0 and post "_" until we get to line 1000
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

