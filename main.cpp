#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <random>
#include <thread>
#include <random>
#include <algorithm>
#include <chrono>
#include <Windows.h>


const float BAR_WIDTH = 4.0f; 
const float BAR_HEIGHT = 10.0f;






void visualizeSort(sf::RenderWindow& window, std::vector<float>& arr) {
    window.clear(sf::Color::Black);

    // Draw bars representing elements
    for (size_t i = 0; i < arr.size(); ++i) {
        sf::RectangleShape bar(sf::Vector2f(BAR_WIDTH, arr[i]));
        bar.setPosition(i*BAR_WIDTH , 600 - arr[i]);
        bar.setFillColor(sf::Color::White);
        window.draw(bar);
    }
    window.display();
};


void bubbleSort(sf::RenderWindow& window, std::vector<float>& arr){
    int n = arr.size();
    for (int i=0; i < n -1; ++i){
        for (int j = 0; j< n-i-1; ++j) {
            visualizeSort(window, arr);


            //std::this_thread::sleep_for(std::chrono::milliseconds(5));

            if(arr[j] > arr[j+1]){
                std::swap(arr[j] , arr[j+1]);
            }
        }
    }
} 






int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SAV");

    // data 
    std::vector<float> data; 
    for (int i = 0; i < 800 / BAR_WIDTH; ++i){
        data.push_back(std::rand() % 600);
    }

    bool showMenu = true;

    sf::Font font;
    // Load font file
    if (!font.loadFromFile("C:\\Users\\1717j\\Downloads\\arial.ttf-master\\arial.ttf-master\\arial.ttf")) {
        // Handle error if font loading fails
        std::cerr << "Failed to load font file" << std::endl;
        return 1; // Exit the program with an error code
    }


    // menu title
    sf::Text text;
    text.setFont(font);
    text.setString("Sorting Visualization");
    text.setCharacterSize(32);
    text.setFillColor(sf::Color::White);
    text.setPosition(260, 30);
    

    // bublesort button 
    sf::Text bubblesort;
    bubblesort.setFont(font);
    bubblesort.setString("Bubble Sort");
    bubblesort.setCharacterSize(24);
    bubblesort.setFillColor(sf::Color::White);
    bubblesort.setPosition(50, 130);
    //button
    sf::RectangleShape buttonRect(sf::Vector2f(200, 100));
    buttonRect.setFillColor(sf::Color::Blue);
    buttonRect.setPosition(30,105);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (showMenu) { // Only handle mouse clicks if the menu is currently visible
                    if (buttonRect.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                        // Handle the play button click (e.g., start the game)
                        showMenu = false; // Hide the menu
                        // Additional game initialization code can go here
                    }
                }
            }
        
        
        }

        // Check if the mouse cursor is within the bounds of the button
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (buttonRect.getGlobalBounds().contains(sf::Vector2f(mousePos))) {
            // Change button color when mouse hovers over it
            buttonRect.setFillColor(sf::Color::Red);
        } else {
            // Restore original button color when mouse is not hovering
            buttonRect.setFillColor(sf::Color::Green);
        }




        // Clear the window
        window.clear();

        if (showMenu){
            window.draw(buttonRect);
            window.draw(bubblesort);
            window.draw(text);
        }
        else {
        bubbleSort(window, data);
        }
        window.display();

    }

    return 0;
}