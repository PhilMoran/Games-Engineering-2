#include <iostream>
#include <vector>
#include "Boid.h"
#include "Pvector.h"
#include "Flock.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <string>
using namespace std;
/*
Brief description of Boid Class:
// This file acts as the main for our boids project. Here, we utilize the SFML
// library, import boids and flock classes, and run the program.-
*/

int main()
{
	float boidsSize = 3;
	string action = "flock";

	//Gets the resolution, size, and bits per pixel for the screen of the PC that is running this program.
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	const int window_height = desktop.height;
	const int window_width = desktop.width;

	//Having the style of "None" gives a false-fullscreen effect for easier closing and access.
	//No FPS limit of V-sync setting needed for it may cause unnecessary slowdown.
	sf::RenderWindow window(sf::VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel), "Boids", sf::Style::None); 
	
	//Create flock, vector of shapes, and initialize boids
	Flock fish;
	Flock gulls;
	
	sf::Texture skyTex;
	sf::Sprite sky;

	sf::Texture waterTex;
	sf::Sprite water;

	sf::Texture herringTex;
	sf::Sprite herring;
	vector<sf::Sprite> herrings;

	sf::Texture seagullsTex;
	sf::Sprite seagull;
	vector<sf::Sprite> seagulls;
	//vector<sf::Sprite> seagulls;

	if (!skyTex.loadFromFile("sky.jpeg"))
	{
		cout << "Texture not loaded" << endl;
	}
	if (!herringTex.loadFromFile("herring.png"))
	{
		cout << "Texture not loaded" << endl;
	}
	if (!waterTex.loadFromFile("Water.png"))
	{
		cout << "Texture not loaded" << endl;
	}
	if (!seagullsTex.loadFromFile("seagull.png"))
	{
		cout << "Texture not loaded" << endl;
	}

	water.setTexture(waterTex);
	water.setPosition(0, 0);
	herring.setTexture(herringTex);
	herring.setOrigin(320, 92);
	seagull.setTexture(seagullsTex);
	sky.setTexture(skyTex);
	sky.setPosition(3840, 2160);
	sky.setScale(0.8, 0.8);
	sky.setRotation(180);
	
	int fLeader = 0; //NPC in slot 0 is the leader when in formation mode.

	for (int i = 0; i < 10; i++) //Number of boids is hardcoded for testing pusposes.
	{
		//Boid b(rand() % window_width, rand() % window_height); //Starts the boid with a random position in the window.
		Boid f(window_width/7, window_height/1.5 ); //Starts all boids in the center of the screen
		Boid b(window_width / 7, window_height / 5); //Starts all boids in the center of the screen
		//herring.setPosition(window_width, window_width); //Testing purposes, starts all shapes in the center of screen.
		seagull.setPosition(0, window_height / 3);
		//Adding the boid to the flock and adding the shapes to the vector<sf::CircleShape>
		fish.addBoid(f);
		gulls.addBoid(b);
		herrings.push_back(herring);
		seagulls.push_back(seagull);
	}

	while (window.isOpen())
	{	
		//Event used to close program when window is closed
		sf::Event event;
		sky.move(0, 0);
		while (window.pollEvent(event))
		{
			//"close requested" event: we close the window
			//Implemented alternate ways to close the window. (Pressing the escape, X, and BackSpace key also close the program.)
			if ((event.type == sf::Event::Closed) || 
				(event.type == sf::Event::KeyPressed &&
				 event.key.code == sf::Keyboard::Escape) ||
				(event.type == sf::Event::KeyPressed &&
				 event.key.code == sf::Keyboard::BackSpace) ||
				(event.type == sf::Event::KeyPressed &&
				 event.key.code == sf::Keyboard::X))
			{
				window.close();
			}
			if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space))
				if (action == "flock")
					action = "swarm";
				else
					action = "flock";
			if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Z))
				action = "cformation";

		}

		//check for mouse click, draws and adds boid to flock if so.
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//Gets mouse coordinates, sets that as the location of the boid and the shape
			sf::Vector2i mouseCoords = sf::Mouse::getPosition(window);
			Boid f(mouseCoords.x, mouseCoords.y, true);
			sf::CircleShape shape(10,3);

			//Changing visual properties of newly created boid
			shape.setPosition(mouseCoords.x, mouseCoords.y);
			shape.setOutlineColor(sf::Color(255, 0, 0));
			shape.setFillColor(sf::Color(255, 0, 0));
			shape.setOutlineColor(sf::Color::White);
			shape.setOutlineThickness(1);
			shape.setRadius(boidsSize);

			//Adds newly created boid and shape to their respective data structure
			fish.addBoid(f);
			herrings.push_back(herring);

			//New Shape is drawn
			window.draw(herrings[herrings.size()-1]);
		}
		//Clears previous frames of visualization to not have clutter. (And simulate animation)
		window.clear();
		
		window.draw(sky);
		window.draw(water);
		//Draws all of the Boids out, and applies functions that are needed to update.
		for (int i = 0; i < herrings.size(); i++)
		{
			window.draw(herrings[i]);
			window.draw(seagulls[i]);
			//Cout's removed due to slowdown and only needed for testing purposes
			//cout << "Boid "<< i <<" Coordinates: (" << shapes[i].getPosition().x << ", " << shapes[i].getPosition().y << ")" << endl;
			//cout << "Boid Code " << i << " Location: (" << flock.getBoid(i).location.x << ", " << flock.getBoid(i).location.y << ")" << endl;

			//Matches up the location of the shape to the boid
			herrings[i].setPosition(fish.getBoid(i).location.x, fish.getBoid(i).location.y);
			seagulls[i].setPosition(gulls.getBoid(i).location.x, gulls.getBoid(i).location.y);
			// Calculates the angle where the velocity is pointing so that the triangle turns towards it.
			float theta;
			float gullTheta;
			theta = fish.getBoid(i).angle(fish.getBoid(i).velocity);
			gullTheta = gulls.getBoid(i).angle(gulls.getBoid(i).velocity);
			herrings[i].setRotation(theta-90);
			seagulls[i].setRotation(gullTheta - 90);

			// These if statements prevent boids from moving off the screen through warpping
			// If boid exits right boundary
			if (herrings[i].getPosition().x > window_width)
				herrings[i].setPosition(herrings[i].getPosition().x - window_width, herrings[i].getPosition().y);
			// If boid exits bottom boundary
			if (herrings[i].getPosition().y > window_height)
				herrings[i].setPosition(herrings[i].getPosition().x, herrings[i].getPosition().y - window_height);
			// If boid exits left boundary
			if (herrings[i].getPosition().x < 0)
				herrings[i].setPosition(herrings[i].getPosition().x + window_width, herrings[i].getPosition().y);
			// If boid exits top boundary
			if (herrings[i].getPosition().y < 0)
				herrings[i].setPosition(herrings[i].getPosition().x, herrings[i].getPosition().y + window_height);
		}

		//Applies the three rules to each boid in the flock and changes them accordingly.
		gulls.vFormation(5);
		fish.flocking();
		//Updates the window with current values of any data that was modified.
		
		window.display();
		
	//This loop continues until window is closed. Continues the process of updating, drawing, rendering the boids, and the window.
	}
	return 0;

}