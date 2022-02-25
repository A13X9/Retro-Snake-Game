#include "MainMenu.hpp"

#include <SFML/Window/Event.hpp>

#include "GamePlay.hpp"

MainMenu::MainMenu(std::shared_ptr<Context> &context)
    : m_context(context), m_isPlayButtonSelected(true), m_isPlayButtonPressed(false), m_isExitButtonSelected(false),
      m_isExitButtonPressed(false), m_isHowToPlayButtonSelected(false), m_isHowToPlayButtonPressed(false),
      m_selectorPosition(1)
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::Init()
{
    m_context->m_assets->AddFont(MAIN_FONT, "assets/fonts/PressStart2P-Regular.ttf");

    // Game Title
    m_gameTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_gameTitle.setString("Retro Snake");
    m_gameTitle.setOrigin(m_gameTitle.getLocalBounds().width / 2, m_gameTitle.getLocalBounds().height / 2);
    m_gameTitle.setPosition(m_context->m_window->getSize().x / 2, m_context->m_window->getSize().y / 2 - 150.f);

    // Play Button
    m_playButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_playButton.setString("Play");
    m_playButton.setOrigin(m_playButton.getLocalBounds().width / 2, m_playButton.getLocalBounds().height / 2);
    m_playButton.setPosition(m_context->m_window->getSize().x / 2, m_context->m_window->getSize().y / 2 - 20.f);
    m_playButton.setCharacterSize(20);

    // How to Play Button
    m_howToPlayButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_howToPlayButton.setString("How to play?");
    m_howToPlayButton.setOrigin(m_howToPlayButton.getLocalBounds().width / 2,
                                m_howToPlayButton.getLocalBounds().height / 2);
    m_howToPlayButton.setPosition(m_context->m_window->getSize().x / 2 + 120,
                                  m_context->m_window->getSize().y / 2 + 15.f);
    m_howToPlayButton.setCharacterSize(20);

    // Exit Button
    m_exitButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_exitButton.setString("Exit");
    m_exitButton.setOrigin(m_exitButton.getLocalBounds().width / 2, m_exitButton.getLocalBounds().height / 2);
    m_exitButton.setPosition(m_context->m_window->getSize().x / 2, m_context->m_window->getSize().y / 2 + 55.f);
    m_exitButton.setCharacterSize(20);
}

void MainMenu::ProcessInput()
{
    sf::Event event;

    while (m_context->m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_context->m_window->close();
        }
        else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Down) &&
                 (m_selectorPosition < 3))
        {
            m_selectorPosition++;
            std::cout << m_selectorPosition << std::endl;
        }
        else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Up) &&
                 (m_selectorPosition > 1))
        {
            m_selectorPosition--;
            std::cout << m_selectorPosition << std::endl;
        }

        switch (m_selectorPosition)
        {
        case (1):
            m_isPlayButtonSelected = true;
            m_isHowToPlayButtonSelected = false;
            m_isExitButtonSelected = false;
            std::cout << "m_isPlayButtonSelected" << std::endl;
            break;

        case (2):
            m_isPlayButtonSelected = false;
            m_isHowToPlayButtonSelected = true;
            m_isExitButtonSelected = false;
            std::cout << "m_isHowToPlayButtonSelected" << std::endl;
            break;

        case (3):
            m_isPlayButtonSelected = false;
            m_isHowToPlayButtonSelected = false;
            m_isExitButtonSelected = true;
            std::cout << "m_isExitButtonSelected" << std::endl;
            break;

        default:
            break;
        }

        if ((m_isPlayButtonSelected) && (event.type == sf::Event::KeyPressed) &&
            (event.key.code == sf::Keyboard::Return))
        {
            m_isPlayButtonPressed = true;
        }

        else if ((m_isHowToPlayButtonSelected) && (event.type == sf::Event::KeyPressed) &&
                 (event.key.code == sf::Keyboard::Return))
        {
            m_isHowToPlayButtonPressed = true;
        }
        else if ((m_isExitButtonSelected) && (event.type == sf::Event::KeyPressed) &&
                 (event.key.code == sf::Keyboard::Return))
        {
            m_isExitButtonPressed = true;
        }
    }
}

void MainMenu::Update(sf::Time deltaTime)
{
    if (m_isPlayButtonSelected)
    {
        m_playButton.setFillColor(sf::Color::Green);
        m_howToPlayButton.setFillColor(sf::Color::White);
        m_exitButton.setFillColor(sf::Color::White);
    }
    else if (m_isHowToPlayButtonSelected)
    {
        m_playButton.setFillColor(sf::Color::White);
        m_howToPlayButton.setFillColor(sf::Color::Green);
        m_exitButton.setFillColor(sf::Color::White);
    }
    else if (m_isExitButtonSelected)
    {
        m_playButton.setFillColor(sf::Color::White);
        m_howToPlayButton.setFillColor(sf::Color::White);
        m_exitButton.setFillColor(sf::Color::Green);
    }

    if (m_isPlayButtonPressed)
    {
        m_context->m_states->Add(std::make_unique<GamePlay>(m_context), true);
    }
    else if (m_isExitButtonPressed)
    {
        m_context->m_window->close();
    }
    else if (m_isHowToPlayButtonPressed)
    {
        std::cout << "HOW TO PLAY PRESSED" << std::endl;
    }
}

void MainMenu::Draw()
{
    m_context->m_window->clear(sf::Color::Black);
    m_context->m_window->draw(m_gameTitle);
    m_context->m_window->draw(m_playButton);
    m_context->m_window->draw(m_howToPlayButton);
    m_context->m_window->draw(m_exitButton);
    m_context->m_window->display();
}