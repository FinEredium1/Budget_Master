#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class TextInput {
private:
    sf::RectangleShape m_textField;
    sf::Text m_text;
    std::string m_inputText;
    sf::Font m_font;
    int _inpx;
    int _inpy;
    bool m_active;

public:
    TextInput(sf::Vector2f size, sf::Vector2f position, int x, int y) : m_active(false) {
        _inpx = x;
        _inpy = y;
        m_textField.setSize(size);
        m_textField.setPosition(position);
        m_textField.setFillColor(sf::Color::White);
        m_font.loadFromFile("data\\arial.ttf");
        m_text.setFont(m_font);
        m_text.setCharacterSize(24);
        m_text.setFillColor(sf::Color::Black);
    }

    bool isActive(){
        if (m_active){
            return true;
        }
        else{
            return false;
        }

    }

    void setActive(bool active) {
        m_active = active;
    }


    void handleInput(sf::Event& event, bool digit_only) {
        if (m_active && event.type == sf::Event::TextEntered) {
            if (event.text.unicode < 128) {
                if (event.text.unicode == 8) {
                    if (!m_inputText.empty()) {
                        m_inputText.pop_back();
                    }
                } else if (digit_only) {
                    if (isdigit(static_cast<char>(event.text.unicode)) && m_inputText.size() <= 7){
                        m_inputText += static_cast<char>(event.text.unicode);                       
                    }
                }
                else{
                    if (m_inputText.size() < 30){
                        m_inputText += static_cast<char>(event.text.unicode);
                    }
                }
                m_text.setPosition(sf::Vector2f(_inpx, _inpy));
                m_text.setString(m_inputText);
            }
        }
    }

    std::string get_text(){
        return m_inputText;
    }

    void set_nullbuffer(){
        m_inputText = "";
    }

    void draw(sf::RenderWindow& window, bool no) {
        if (!no){
        window.draw(m_textField);
        window.draw(m_text);
        }
    }

    void setText(const std::string& text, sf::Vector2f position) {
        m_inputText = text;
        m_text.setString(m_inputText);
        m_text.setPosition(position);
    }
};


class TextDisplay {
private:
    sf::Text m_text;
    sf::Font m_font;


public:
    TextDisplay(const std::string& text, int font, unsigned int characterSize, sf::Vector2f position, sf::Color color) {
        m_text.setString(text);
        (font != 1) ? m_font.loadFromFile("data\\arial.ttf"):m_font.loadFromFile("data\\ariana.ttf");
        m_text.setFont(m_font);
        m_text.setCharacterSize(characterSize);
        m_text.setPosition(position);
        m_text.setFillColor(color);
    }

    void setText(const std::string& text) {
        m_text.setString(text);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(m_text);
    }
};


class Rectangle {
private:
    sf::RectangleShape m_shape;

public:
    Rectangle(sf::Vector2f size, sf::Vector2f position, sf::Color color) {
        m_shape.setSize(size);
        m_shape.setPosition(position);
        m_shape.setFillColor(color);
    }

    

    void draw(sf::RenderWindow& window) {
        window.draw(m_shape);
    }
};
