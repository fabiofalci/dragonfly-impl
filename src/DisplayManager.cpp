#include <iostream>

#include "DisplayManager.h"

namespace df {

DisplayManager::DisplayManager() {
    setType("DisplayManager");
    m_p_window = NULL;

    m_window_horizontal_pixels = WINDOW_HORIZONTAL_PIXELS_DEFAULT;
    m_window_vertical_pixels = WINDOW_VERTICAL_PIXELS_DEFAULT;
    m_window_horizontal_chars = WINDOW_HORIZONTAL_CHARS_DEFAULT ;
    m_window_vertical_chars = WINDOW_VERTICAL_CHARS_DEFAULT;
}

DisplayManager::DisplayManager(DisplayManager const&) {}

void DisplayManager::operator=(DisplayManager const&) {}

DisplayManager& DisplayManager::getInstance() {
    static DisplayManager *p_display_manager = new DisplayManager;
    return *p_display_manager;
}

int DisplayManager::startUp() {
    if (m_p_window != NULL)
        return 1;

    m_p_window = new sf::RenderWindow(sf::VideoMode(WINDOW_HORIZONTAL_PIXELS_DEFAULT, WINDOW_VERTICAL_PIXELS_DEFAULT), WINDOW_TITLE_DEFAULT);
    if (!m_p_window) {
        std::cout << "Error! Unable to allocate RenderWindow" << std::endl;
        return 0;
    }

    if (m_font.loadFromFile("../df-font.ttf") == false) {
        std::cout << "Error. Unable to load font df-font.ttf" << std::endl;
        return 0;
    }

    m_p_window->setMouseCursorVisible(false);
    m_p_window->setVerticalSyncEnabled(true);
    return Manager::startUp();
}

void DisplayManager::shutDown() {
    m_p_window->close();
    return Manager::shutDown();
}

int DisplayManager::drawCh(Vector world_pos, char ch, Color color) const {
    if (m_p_window == nullptr)
        return -1;

    Vector pixel_pos = spacesToPixels(world_pos);

    static sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(charWidth(), charHeight()));
    rectangle.setFillColor(WINDOW_BACKGROUND_COLOR_DEFAULT);
    rectangle.setPosition(pixel_pos.getX() - charWidth() / 10, pixel_pos.getY() + charHeight() / 5);

    m_p_window->draw(rectangle);

    static sf::Text text("", m_font);
    text.setString(ch);
    text.setStyle(sf::Text::Bold);

    if (charWidth() < charHeight())
        text.setCharacterSize(charWidth() * 2);
    else
        text.setCharacterSize(charHeight() * 2);

    switch(color) {
        case YELLOW:
            text.setFillColor(sf::Color::Yellow);
            break;
        case RED:
            text.setFillColor(sf::Color::Red);
            break;
        case BLUE:
            text.setFillColor(sf::Color::Blue);
            break;
        case GREEN:
            text.setFillColor(sf::Color::Green);
            break;
        case WHITE:
            text.setFillColor(sf::Color::White);
            break;

        default:
            text.setFillColor(sf::Color::Green);
            break;
    }

    text.setPosition(pixel_pos.getX(), pixel_pos.getY());
    m_p_window->draw(text);
    return 0;
}

int DisplayManager::drawString(Vector world_pos, std::string str, Justification just, Color color) const {
    Vector starting_pos = world_pos;
    switch(just) {
        case CENTER_JUSTIFIED:
            starting_pos.setX(world_pos.getX() - str.size() / 2);
            break;
        case RIGHT_JUSTIFIED:
            starting_pos.setX(world_pos.getX() - str.size());
            break;
        case LEFT_JUSTIFIED:
        default:
            break;
    }

    for (int i=0; i < str.size(); i++) {
        Vector temp_pos(starting_pos.getX() + i, starting_pos.getY());
        drawCh(temp_pos, str[i], color);
    }

    return 0;
}


int DisplayManager::getHorizontal() const {
    return m_window_horizontal_chars;
}

int DisplayManager::getVertical() const {
    return m_window_vertical_chars;
}

int DisplayManager::getHorizontalPixels() const {
    return m_window_horizontal_pixels;
}

int DisplayManager::getVerticalPixels() const {
    return m_window_vertical_pixels;
}

int DisplayManager::swapBuffers() {
    if (m_p_window == nullptr)
        return 1;
    
    m_p_window->display();
    m_p_window->clear();
    return 0;
}

sf::RenderWindow* DisplayManager::getWindow() const {
    return m_p_window;
}


float DisplayManager::charHeight() const {
    return getVerticalPixels() / getVertical();
}

float DisplayManager::charWidth() const {
    return getHorizontalPixels() / getHorizontal();

}

Vector DisplayManager::spacesToPixels(Vector spaces) const {
    Vector vector(spaces.getX() * charWidth(), spaces.getY() * charHeight());
    return vector;
}

Vector DisplayManager::pixelsToSpaces(Vector pixels) const {
    Vector vector(pixels.getX() / charWidth(), pixels.getY() / charHeight());
    return vector;
}

}