#include <string>
#include <iostream>
#include <random>
#include <vector>
#include <limits>
#include "BubbleSort.hpp"
#include "Algorithm.hpp"
#include "MergeSort.hpp"
#include <SFML/Graphics.hpp>

#define FONT_SIZE 16

sf::Font initFont();
sf::Text createText(std::string prompt, int charSize, int posX, int posY, const sf::Font& font);
sf::RenderWindow createWindow();
sf::RectangleShape initRectangle(float sizeX, float sizeY, float posX, float posY);
int getIntInput(std::string prompt, int min, int max);
void updateRectangle(sf::RectangleShape& rectangle, int value, sf::Vector2u windowSize, int currentX, int width);
Algorithm* makeSorter(int alg, int size);

int main()
{
	// 2 arrays. 1 is used to hold the values to be sorted.
	// the 2nd is for the rectangle objects that need to be drawn to the window.
	int input1;
	int input2;
	input1 = getIntInput("Select the algorithm you'd like to use:\n1. Bubble sort\n2. Merge sort\n", 1, 2);

	input2 = getIntInput("Enter the number of elements you'd like to sort (1-10000): ", 1, 10000);

	const int numElements = input2;
	Algorithm* sorter = makeSorter(input1, input2);

	if (!sorter) {
		std::cout << "Failed to make sorter. Terminating program.";
		return 1;
	}

	const std ::vector<int>& elements = sorter->getArr();
	std::vector<sf::RectangleShape> rectangles(numElements);

	// prematurely create window and make it invisible to access window size for calculations.
	sf::RenderWindow window = createWindow();
	
	int currentX = 0;
	int width = window.getSize().x / numElements;

	// populates rectangle array.
	for (int i = 0; i < numElements; i++) {
		float height = (elements[i] / 100.0f) * window.getSize().y; // scales the values so the graph is more interesting to look at
		
		sf::RectangleShape rect = initRectangle(static_cast<float>(width), height, static_cast<float>(currentX), static_cast<float>(window.getSize().y - height));
		currentX += width;
		rectangles[i] = rect;
	}
	
	sf::Clock clock;
	window.setVisible(true);
	
	sf::Font font;
	try {
		font = initFont();
	}
	catch (const std::exception& e) {
		std::cout << e.what() << "\n";
		return 1;
	}
	sf::Text numSwaps = createText("Number of swaps: 0", FONT_SIZE, 0, 0, font);
	sf::Text numComparisons = createText("Number of comparisons: 0", FONT_SIZE, 0, FONT_SIZE, font);

	bool sorting = true;
	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
		}
		window.clear(sf::Color::Black);
		
		if (sorting && clock.getElapsedTime().asSeconds() >= 0.1) {
			clock.restart();
			sorter->step();

			currentX = 0;
			for (int i = 0; i < numElements; i++) {
				updateRectangle(rectangles[i], elements[i], window.getSize(), currentX, width);
				currentX += width;
			}
			if (sorter->isFinished()) {
				sorting = false;
				int numSwaps = sorter->getNumSwaps();
				int numComparisons = sorter->getNumComparisons();
				std::cout << "Sorting has finished.\nNumber of swaps: " << numSwaps << "\nNumber of comparisons: " << numComparisons;
			}
		}
		
		for (int i = 0; i < numElements; i++) {
			window.draw(rectangles[i]);
		}

		int newSwaps = sorter->getNumSwaps();
		int newComparisons = sorter->getNumComparisons();

		numSwaps.setString("Number of swaps: " + std::to_string(newSwaps));
		numComparisons.setString("number of comparisons: " + std::to_string(newComparisons));

		window.draw(numSwaps);
		window.draw(numComparisons);
		
		window.display();
	}

	return 1;
}

void updateRectangle(sf::RectangleShape& rectangle, int value, sf::Vector2u windowSize, int currentX, int width) {
	float height = (value / 100.0f) * windowSize.y;
	rectangle.setSize({
		static_cast<float>(width),
		height
		});
	rectangle.setPosition({
		static_cast<float>(currentX),
		static_cast<float>(windowSize.y - height)
		});
}

Algorithm* makeSorter(int alg, int size) {
	Algorithm* sorter;
	switch (alg) {
	case 1:
		sorter = new BubbleSort(size, "O(n^2)");
		return sorter;
	case 2:
		sorter = new MergeSort(size, "O(nlogn)");
		return sorter;
	default:
		return nullptr;
	}
}

sf::Text createText(std::string prompt, int charSize, int posX, int posY, const sf::Font& font) {
	sf::Text text(font);
	text.setString(prompt);
	text.setCharacterSize(charSize);
	text.setPosition({ static_cast<float>(posX), static_cast<float>(posY) });
	return text;
}

sf::Font initFont() {
	sf::Font font;
	if (!font.openFromFile("assets/Akira.otf")) {
		throw std::runtime_error("FAILED TO LOAD FONT, TERMINATING PROGRAM.");
	}
	return font;
}

sf::RectangleShape initRectangle(float sizeX, float sizeY, float posX, float posY) {
	sf::RectangleShape rect;
	rect.setSize({
		sizeX,
		sizeY
		});
	rect.setPosition({
		posX,
		posY
		});
	return rect;
}

sf::RenderWindow createWindow() {
	sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Sorting Visualizer");
	window.setVerticalSyncEnabled(true);
	window.setVisible(false);
	return window;
}

int getIntInput(std::string prompt, int min, int max) {
	std::cout << prompt;
	int input;
	
	while (!(std::cin >> input) || input < min || input > max) {
		std::cout << "Invalid input. Please enter an integer.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << prompt;
	}

	return input;
}