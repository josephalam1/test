#ifndef WORLD_H
#define WORLD_H
#include <cstdlib>
#include <string>

class World {
	public:
		World() {};
		
		virtual void PrintGrid() = 0;
		virtual void UpdateGrid() = 0;
		
	protected:
		int day; 
		std::string grid[10][10];
		
		virtual void initGrid() = 0;
	
};

#endif /* WORLD_H */
