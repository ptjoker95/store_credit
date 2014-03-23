/*
 * storecredit.cxx
 * 
 * Copyright 2014 ptjoker95 <ptjoker95@ptjoker95notebook>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <fstream>
using namespace std;

class StoreCredit
{
	private:
		int C, I, *P;
	
	public:
		void input( int Cost, int Item )
		{
			C = Cost;
			I = Item;
			
			P = new int[Item];
		}

		void input( int Cost, int Item, int Price[] )
		{
			C = Cost;
			I = Item;
			
			P = new int[Item];
			
			for ( int i=0; i<Item; i++ )
			{
				P[i] = Price[i];
			}
		}
		
		int Cost()
		{
			return C;
		}
		
		int Item()
		{
			return I;
		}
		
		int Prices(int i)
		{
			if( i < I )
			{
				return (int)P[i];
			}
		}
		
		~StoreCredit()
		{
			delete P;
		}

} store;



int main(int argc, char **argv)
{
	int N, C, I, *P;
	string line;
	
	StoreCredit *store;

	//read file data
	ifstream myfile ("A-small-practice.in");
	if ( myfile.is_open() )
	{
		//read total number of cases
		myfile >> N;
		store = new StoreCredit[N];
		
		for( int i=0; !myfile.eof(); i++ )
		{
			//read Cost and Item
			myfile >> C >> I;
		
			//make Prices array
			P = new int[I];
	
			//read prices
			for( int j=0; j<I; j++ )
				myfile >> P[j];
		
			store[i].input( C, I, P );
			
			delete [] P;
		}
	}	

	myfile.close();
	return 0;
}

