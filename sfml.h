#pragma once
#ifndef SFML_H
#define SFML_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;

void playSound() {

	// Load a sound buffer from a wav file
	SoundBuffer buffer;
	if (!buffer.loadFromFile("erro.wav"))
		return;

	// Create a sound instance and play it
	Sound sound(buffer);
	sound.play();

	// Loop while the sound is playing
	while (sound.getStatus() == Sound::Playing)
	{
		// Leave some CPU time for other processes
		sleep(milliseconds(100));
	}
}

void displayGraphic(string s) {

	RenderWindow window(VideoMode(1024, 720), "Flex Management System");

	RectangleShape sound_Button(Vector2f(1024.0f, 720.0f));
	sound_Button.setPosition(10.0, 10.0);
	//String Parameter
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile(s);
	sound_Button.setTexture(&sound_ButtonTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed)
				window.close();
		}

		window.clear();

		window.draw(sound_Button);

		window.display();
	}
}

void sfml_text(string s) {
	RenderWindow window(VideoMode(500, 500), "Flex Management System");

	Font font;

	if (!font.loadFromFile("OpenSans-Bold.ttf"))
	{
		cout << "not";

	}

	Text line;

	line.setFont(font);
	line.setCharacterSize(50);
	line.setFillColor(Color::White);
	line.setPosition(10, 10);
	line.setString(s);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed)
				window.close();
		}

		window.clear();

		window.draw(line);

		window.display();
	}
}



void playBKL() {

	// Load a sound buffer from a wav file
	SoundBuffer buffer;
	if (!buffer.loadFromFile("BKL.wav"))
		return;

	// Create a sound instance and play it
	Sound sound(buffer);
	sound.play();

	// Loop while the sound is playing
	while (sound.getStatus() == Sound::Playing)
	{
		// Leave some CPU time for other processes
		sleep(milliseconds(100));
	}
}


#endif // !SFML_H