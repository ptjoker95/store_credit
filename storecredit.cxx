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
		int N, C, I, *P;
		int output1, output2, index1, index2;
		
		bool thereisP()
		{
			if( sizeof(P) == 0 )
				return false;
			else
				return true;
		}
	
	public:
		void return_outputs()
		{
			if( output1 != 0 && output2 != 0 )
			{
				cout << "Case #" << N+1 << ": " << index1 << " " << index2 << endl;
			}
		}
		
		void finditem()
		{
			int sumC;
			int first_item, second_item;
			
			if( thereisP() )
			{
				for( int i=0; i < I; i++ )
				{
					first_item = P[i];
					for( int j=i+1; j < I; j++ )
					{
						second_item = P[j];
						sumC = first_item + second_item;
						
						if( sumC == C )
						{
							output1 = first_item;
							output2 = second_item;
							index1 = i+1;
							index2 = j+1;
						}
					}
				}
			}
		}		
		
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
		
		void input( int Num, int Cost, int Item, int Price[] )
		{
			N = Num;
			C = Cost;
			I = Item;
			
			P = new int[Item];
			
			for ( int i=0; i < Item; i++ )
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
			delete [] P;
		}

} store;



int main(int argc, char **argv)
{
	int N, C, I, *P;
	string line;
	
	StoreCredit *store;

	//read file data
	ifstream myfile ("A-large-practice.in");
	if ( myfile.is_open() )
	{
		//read total number of cases
		myfile >> N;
		store = new StoreCredit[N];
		
		for( int i=0; i<N; i++ )
		{
			//read Cost and Item
			myfile >> C >> I;
		
			//make Prices array
			P = new int[I];
	
			//read prices
			for( int j=0; j<I; j++ )
				myfile >> P[j];
			
			store[i].input( i, C, I, P );
			
			delete [] P;
		}
	}	

	// calculate data
	for( int i=0; i < N; i++ )
	{
		store[i].finditem();
		store[i].return_outputs();
	}
	
	myfile.close();
	
	// delete class
	for( int i=0; i < N; i++ )
	{
		store[i].~StoreCredit();
	}
	
	return 0;
}

