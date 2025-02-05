
#include "Game.hpp"
#include <SFML/Graphics/CircleShape.hpp>

#include "MainMenu.hpp"

Game::Game():m_context(std::make_shared<Context>())
 {
     m_context->m_window->create(sf::VideoMode(900, 600), "Snake Game",sf::Style::Close);
     m_context->m_states->Add(std::make_unique<MainMenu>(m_context));
 }
Game::~Game()
{

}

void Game::Run()
{
   sf::CircleShape shape(100.f);
   shape.setFillColor(sf::Color::Green);

   sf::Clock clock;
   sf::Time timeSinceLastFrame=sf::Time::Zero;


   while (m_context->m_window->isOpen())
   {
       timeSinceLastFrame+= clock.restart();


       while(timeSinceLastFrame > TIME_PER_FRAME)
       {
        timeSinceLastFrame-=TIME_PER_FRAME;

       m_context->m_states->ProcessStateChange();
       m_context->m_states->Getcurrent()->ProcessInput();
       m_context->m_states->Getcurrent()->Update(TIME_PER_FRAME);
       m_context->m_states->Getcurrent()->Draw();


       }
   }
}
#gdhdu