#pragma once
#include "Astronomer.h"
#include "Star.h"
#include <algorithm>

class Controller {
private:
	vector<Astronomer> astronomers;
	vector<Star> stars;
	string astronomersFile = "astronomers.txt", starsFile = "stars.txt";
public:
	Controller() {
		this->readAstronomers();
		this->readStars();
	}
	void readAstronomers();
	void readStars();
	void writeStars();

	vector<Star>& getStars() {
		sort(stars.begin(), stars.end(), [&](Star& i, Star& j) {
			return i.getName() < j.getName();
			});
		return this->stars;
	}

	vector<Astronomer>& getAstronomers() {
		return this->astronomers;
	}

	void addStar(Star& s) {
		this->stars.push_back(s);
	}
};
/*#include <iostream>
#include <cassert>
#include "Controller.h" // Assuming you have a separate header file for the Controller class

void testAddStar() {
    Controller controller;
    vector<Star>& stars = controller.getStars();

    // Create a sample star
    Star newStar("Sample Star", 10.0); // Assuming the Star constructor takes name and magnitude as parameters

    // Call the addStar function
    controller.addStar(newStar);

    // Check if the star was added successfully
    assert(stars.size() == 1);
    assert(stars[0].getName() == "Sample Star");
    assert(stars[0].getMagnitude() == 10.0);

    // Add more test cases if needed

    // Print success message if all assertions passed
    std::cout << "addStar test passed!" << std::endl;
}

int main() {
    testAddStar();
    return 0;
}
*/
/*void function1() {
    throw std::runtime_error("Exception occurred in function1");
}

void function2() {
    try {
        function1();
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}*/