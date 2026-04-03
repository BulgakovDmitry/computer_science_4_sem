#include <SFML/Graphics.hpp>

int main()
{
    const int windowWidth = 800;
    const int windowHeight = 600;
    const float speed = 300.0f; // пикселей в секунду

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML movement");
    window.setFramerateLimit(60);

    sf::RectangleShape player(sf::Vector2f(80.0f, 80.0f));
    player.setFillColor(sf::Color::Green);
    player.setPosition(100.0f, 100.0f);

    sf::Clock clock;

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Vector2f movement(0.0f, 0.0f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            movement.x -= speed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            movement.x += speed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            movement.y -= speed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            movement.y += speed * deltaTime;

        player.move(movement);

        // Ограничение движения внутри окна
        sf::Vector2f pos = player.getPosition();
        sf::Vector2f size = player.getSize();

        if (pos.x < 0)
            pos.x = 0;
        if (pos.y < 0)
            pos.y = 0;
        if (pos.x + size.x > windowWidth)
            pos.x = windowWidth - size.x;
        if (pos.y + size.y > windowHeight)
            pos.y = windowHeight - size.y;

        player.setPosition(pos);

        window.clear(sf::Color::Black);
        window.draw(player);
        window.display();
    }

    return 0;
}