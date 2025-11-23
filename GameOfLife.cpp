#include <iostream>
#include <vector>

int main()
{
    std::vector <int> testvec{ 3, 2};
    std::string name = "test";
    std::vector <char> test2{'#','#','#','\n',' ',' ','#','\n',' ','#',' ' };
  
	std::cout << testvec.size() << "\n";

    for (int i = 0; i < testvec.size(); i++) {
        if (i == testvec.size() - 1) {
            std::cout << testvec[i]<<"\n";
        }
        else
        {
		    std::cout << testvec[i] << " ";
        }
    }

    for (int i = 0;i < test2.size();i++) {
		std::cout << test2[i];
    }
	std::cout << "\n" << name << "\n\n";
    std::cout << "Hello World!\n";



}
