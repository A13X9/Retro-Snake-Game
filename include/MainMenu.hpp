#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>

#include "State.hpp"
#include "Game.hpp"

class MainMenu : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    sf::Text m_gameTitle;
    sf::Text m_playButton;
    sf::Text m_exitButton;
    sf::Text m_howToPlayButton;

    bool m_isPlayButtonSelected;
    bool m_isPlayButtonPressed;

    bool m_isExitButtonSelected;
    bool m_isExitButtonPressed;

    bool m_isHowToPlayButtonSelected;
    bool m_isHowToPlayButtonPressed;

public:
    MainMenu(std::shared_ptr<Context> &context);
    ~MainMenu();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
};