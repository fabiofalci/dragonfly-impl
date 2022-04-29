#include <chrono>
#include <thread>
#include <iostream>

#include "LogManager.h"
#include "GameManager.h"
#include "DisplayManager.h"
#include "Saucer.h"
#include "Star.h"
#include "Vector.h"

void runGameManager() {
    GM.startUp();
    LM.setFlush(true);

    Saucer *saucer0 = new Saucer;
    df::Vector position0(0.0, 0.0);
    saucer0->setPosition(position0);
    saucer0->setAltitude(4);

    Saucer *saucer1 = new Saucer;
    df::Vector position1(10.0, 10.0);
    saucer1->setPosition(position1);
    saucer1->setAltitude(1);

    Star *star = new Star;
    df::Vector position2(10.0, 10.0);
    star->setPosition(position2);
    star->setAltitude(2);

    GM.run();

    GM.shutDown();
}

void runDisplayManager() {
    DM.startUp();

    sf::Font font;
    if (font.loadFromFile("../df-font.ttf") == false) {
        std::cout << "Error. Unable to load font df-font.ttf" << std::endl;
        return;
    }

    sf::RenderWindow *window = DM.getWindow();
    window->clear();

    df::Vector pos(19, 8);
    DM.drawCh(pos, 'H', df::Color::BLACK);

    sf::Text text;
    text.setFont(font);
    text.setString("Hello world");
    text.setCharacterSize(32);
    text.setFillColor(sf::Color::Blue);
    text.setStyle(sf::Text::Bold);
    text.setPosition(93, 134);

    window->draw(text);
    window->display();

    std::this_thread::sleep_for(std::chrono::milliseconds(10000));

    DM.shutDown();
}

int main(int argc, char *argv[]) {
    runGameManager();
    // runDisplayManager();
    return 0;
}