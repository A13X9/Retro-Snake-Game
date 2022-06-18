#pragma once
#include "Game.hpp"
#include "GamePlay.hpp"
#include "State.hpp"
#include "MainMenu.hpp"

class HowToPlay: public Engine :: State
{
  private:
    std::shared_ptr<Context> m_context;
    sf::Text m_howToPlaytitle;
    sf::Text m_howToPlaytext;

  public:
    HowToPlay(std::shared_ptr<Context> &context);
    ~HowToPlay();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
};