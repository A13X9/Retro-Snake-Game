#pragma once

#include <SFML/Graphics/Text.hpp>
#include <memory>

#include "Game.hpp"
#include "GamePlay.hpp"
#include "State.hpp"

class PauseGame : public Engine::State
{
  private:
    std::shared_ptr<Context> m_context;
    sf::Text m_pauseTitle;

  public:
    PauseGame(std::shared_ptr<Context> &context);
    ~PauseGame();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
};