#include "graphs.h"

void drawClusters(const std::vector<Point>& points) {
    // Размеры окна
    const int windowWidth = 800;
    const int windowHeight = 600;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "K-Means Clustering");

    // Массивы для хранения цветов для каждого кластера
    std::vector<sf::Color> colors = {
            sf::Color::Red,
            sf::Color::Green,
            sf::Color::Blue,
            sf::Color::Yellow,
            sf::Color::Magenta,
            sf::Color::Cyan
    };

    // Главный цикл отрисовки
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        // Отрисовка точек
        for (const auto& point : points) {
            sf::CircleShape shape(5); // Радиус точки
            shape.setFillColor(colors[point.cluster % colors.size()]);
            shape.setPosition(static_cast<float>(point.x), static_cast<float>(point.y));
            window.draw(shape);
        }

        window.display();
    }
}


