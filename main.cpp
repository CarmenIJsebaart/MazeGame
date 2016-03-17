#include <cassert>
#include <iostream>
#include <QFile>
#include <SFML/Graphics.hpp>

void check_pixel_color(sf::Color pixel_color, bool &game_screen, bool &game_over_screen, bool &winner_screen);

int main()
{
  { QFile f(":/files/arial.ttf"); f.copy("arial.ttf"); }
  { QFile f(":/files/Level.png"); f.copy("Level.png"); }

  const int window_height = 600;
  const int window_width = 800;
  assert(window_height == 600);
  assert(window_width == 800);

  sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Maze game", sf::Style::Titlebar | sf::Style::Close);

  sf::Image level_image;
  const std::string level("Level.png");
  assert(level != "");
  if(!level_image.loadFromFile(level))
  {
    std::cerr << level << " not found";
  }
  sf::Texture level_texture;
  level_texture.loadFromImage(level_image);
  sf::Sprite level_sprite(level_texture);

  sf::Font arial;
  const std::string font("arial.ttf");
  assert(font != "");
  if(!arial.loadFromFile(font))
  {
    std::cerr << font << "not found";
  }

  sf::Text begin_text;
  begin_text.setFont(arial);
  begin_text.setString("Press space to start!");
  begin_text.setCharacterSize(85);
  begin_text.setColor(sf::Color::Black);
  begin_text.setStyle(sf::Text::Bold);

  sf::Text game_over_text;
  game_over_text.setFont(arial);
  game_over_text.setString("Game over!");
  game_over_text.setCharacterSize(150);
  game_over_text.setColor(sf::Color::Black);
  game_over_text.setStyle(sf::Text::Bold);

  sf::Text winner_text;
  winner_text.setFont(arial);
  winner_text.setString("You won!");
  winner_text.setCharacterSize(190);
  winner_text.setColor(sf::Color::Black);
  winner_text.setStyle(sf::Text::Bold);

  sf::Text start_again_text;
  start_again_text.setFont(arial);
  start_again_text.setString("Press space to start again!");
  start_again_text.setCharacterSize(65);
  start_again_text.setColor(sf::Color::Black);
  start_again_text.setStyle(sf::Text::Bold);
  start_again_text.setPosition(sf::Vector2f(0, 200));

  bool intro_screen = true;
  bool game_screen = false;
  bool game_over_screen = false;
  bool winner_screen = false;

  while(window.isOpen())
  {
    while(intro_screen == true)
    {
      sf::Event event;

      while(window.pollEvent(event))
      {
        if(event.type == sf::Event::Closed)
        {
          window.close();
        }
      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
      {
        intro_screen = false;
        game_screen = true;
        int mouse_x = 725;
        int mouse_y = 575;
        sf::Mouse::setPosition(sf::Vector2i(mouse_x, mouse_y), window);
        assert(mouse_x == 725);
        assert(mouse_y == 575);
      }

      window.clear(sf::Color::Red);
      window.draw(begin_text);
      window.display();
    }


    while(game_screen == true)
    {
      sf::Event event;

      while(window.pollEvent(event))
      {
        switch(event.type)
        {
          case::sf::Event::Closed:
            window.close();
            break;
          case::sf::Event::MouseMoved:
          {
            std::cout << "Mouse has been moved" << std::endl;
            std::cout << event.mouseMove.x << "  " << event.mouseMove.y << std::endl;
            int mouse_x = event.mouseMove.x;
            int mouse_y = event.mouseMove.y;
            assert(mouse_x >= 0);
            assert(mouse_x <= window_width);
            assert(mouse_y >= 0);
            assert(mouse_y <= window_height);
            sf::Color pixel_color = level_image.getPixel(mouse_x, mouse_y);
            check_pixel_color(pixel_color, game_screen, game_over_screen, winner_screen);
            assert(pixel_color == sf::Color::Black || pixel_color == sf::Color::Blue || pixel_color == sf::Color::Green || pixel_color == sf::Color::Red);
            break;
          }
          default:
            break;
        }
      }

      window.clear();
      window.draw(level_sprite);
      window.display();
    }

    while(game_over_screen == true)
    {
      sf::Event event;
      while(window.pollEvent(event))
      {
        if(event.type == sf::Event::Closed)
        {
          window.close();
        }
      }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
      {
        game_over_screen = false;
        game_screen = true;
        int mouse_x = 725;
        int mouse_y = 575;
        sf::Mouse::setPosition(sf::Vector2i(mouse_x, mouse_y), window);
        assert(mouse_x == 725);
        assert(mouse_y == 575);
      }

      window.clear(sf::Color::Red);
      window.draw(game_over_text);
      window.draw(start_again_text);
      window.display();
    }

    while(winner_screen == true)
    {
      sf::Event event;
      while(window.pollEvent(event))
      {
        if(event.type == sf::Event::Closed)
        {
          window.close();
        }
      }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
      {
        winner_screen = false;
        game_screen = true;
        int mouse_x = 725;
        int mouse_y = 575;
        sf::Mouse::setPosition(sf::Vector2i(mouse_x, mouse_y), window);
        assert(mouse_x == 725);
        assert(mouse_y == 575);
      }

      window.clear(sf::Color::Red);
      window.draw(winner_text);
      window.draw(start_again_text);
      window.display();
    }
  }
}

void check_pixel_color(sf::Color pixel_color, bool &game_screen, bool &game_over_screen, bool &winner_screen)
{
  if(pixel_color == sf::Color::Blue)
  {
    game_screen = false;
    game_over_screen = true;
  }
  else if(pixel_color == sf::Color::Green)
  {
    game_screen = false;
    winner_screen = true;
  }
}

