#include "HowToPlay.hpp"

#include <SFML/Window/Event.hpp>

HowToPlay::HowToPlay(std::shared_ptr<Context> &context) : m_context(context)
{
}

HowToPlay::~HowToPlay()
{
}


void HowToPlay::Init()
{
    m_howToPlaytitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_howToPlaytitle.setString("How to play?");
    m_howToPlaytitle.setOrigin(m_howToPlaytitle.getLocalBounds().width / 2, m_howToPlaytitle.getLocalBounds().height / 2);
    m_howToPlaytitle.setPosition(m_context->m_window->getSize().x / 2 + 30.f, m_context->m_window->getSize().y / 2 - 100.f);
    m_howToPlaytitle.setCharacterSize(20);

    m_howToPlaytext.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_howToPlaytext.setString("Eat the food to increase the size and score.\n\nYou die if the snake touches itself or the walls.\n\nYou can move the snake with the arrow keys.\n\nYou can pause the game with the escape key.\n\n\n\n   Press Escape to go back to the main menu.");
    m_howToPlaytext.setOrigin(m_howToPlaytitle.getLocalBounds().width / 2, m_howToPlaytitle.getLocalBounds().height / 2);
    m_howToPlaytext.setPosition(m_context->m_window->getSize().x / 2 - 120.f, m_context->m_window->getSize().y / 2 - 25.f);
    m_howToPlaytext.setCharacterSize(10);
}

void HowToPlay::ProcessInput()
{
    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_context->m_window->close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Escape:
                m_context->m_states->Add(std::make_unique<MainMenu>(m_context));
                break;

            default:
                break;
            }
        }
    }
}

void HowToPlay::Update(sf::Time deltaTime)
{
}

void HowToPlay::Draw()
{
    m_context->m_window->clear(sf::Color::Black);
    m_context->m_window->draw(m_howToPlaytitle);
    m_context->m_window->draw(m_howToPlaytext);
    m_context->m_window->display();
}