#include "graphs.h"

void drawClusters(const std::vector<Point>& points) {
    const int windowWidth = 800;
    const int windowHeight = 600;

    double minX = std::numeric_limits<double>::max(); 
    double maxX = std::numeric_limits<double>::min(); 
    double minY = std::numeric_limits<double>::max(); 
    double maxY = std::numeric_limits<double>::min(); 

    // Поиск минимальных и максимальных значений по координатам
    for (const auto& point : points) {
        if (point.x < minX) minX = point.x;
        if (point.x > maxX) maxX = point.x;
        if (point.y < minY) minY = point.y;
        if (point.y > maxY) maxY = point.y;
    }

    // Создание окна
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Clustering with K-Means and DBSCAN");

    // Массивы для хранения цветов для каждого кластера
    std::vector<sf::Color> colors = {
            sf::Color::Red,
            sf::Color::Green,
            sf::Color::Blue,
            sf::Color::Yellow,
            sf::Color::Magenta,
            sf::Color::Cyan
    };

    // Загрузка шрифта
    sf::Font font;
    if (!font.loadFromFile("/Users/nikitakalinin/Documents/Projects/Project_M/DSBA-CPP-2024-Project-main/Arial.ttf")) {
        std::cerr << "Could not load font 'Arial.ttf'\n"; 
        return;
    }

    // Главный цикл отрисовки
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); 
        }

        window.clear(sf::Color::White);

        // Отрисовка осей
        sf::Vertex xAxis[] =
                {
                        sf::Vertex(sf::Vector2f(50, windowHeight - 50)),
                        sf::Vertex(sf::Vector2f(windowWidth - 50, windowHeight - 50))
                };
        sf::Vertex yAxis[] =
                {
                        sf::Vertex(sf::Vector2f(50, windowHeight - 50)),
                        sf::Vertex(sf::Vector2f(50, 50))
                };
        window.draw(xAxis, 2, sf::Lines); 
        window.draw(yAxis, 2, sf::Lines); 

        // Отрисовка сетки
        for (int i = 50; i < windowWidth - 50; i += 50) {
            sf::Vertex line[] =
                    {
                            sf::Vertex(sf::Vector2f(i, windowHeight - 50), sf::Color(200, 200, 200)),
                            sf::Vertex(sf::Vector2f(i, 50), sf::Color(200, 200, 200))
                    };
            window.draw(line, 2, sf::Lines);
        }
        for (int i = 50; i < windowHeight - 50; i += 50) {
            sf::Vertex line[] =
                    {
                            sf::Vertex(sf::Vector2f(50, i), sf::Color(200, 200, 200)),
                            sf::Vertex(sf::Vector2f(windowWidth - 50, i), sf::Color(200, 200, 200))
                    };
            window.draw(line, 2, sf::Lines); 
        }

        // Отрисовка точек
        for (const auto& point : points) {
            sf::CircleShape shape(5);
            shape.setFillColor(colors[point.cluster % colors.size()]);

            // Масштабирование координат точки
            float x = static_cast<float>(50 + (point.x - minX) / (maxX - minX) * (windowWidth - 100));
            float y = static_cast<float>(windowHeight - 50 - (point.y - minY) / (maxY - minY) * (windowHeight - 100));

            shape.setPosition(x, y); 
            window.draw(shape); 
        }

        // Отрисовка меток на осях
        for (int i = 0; i <= 10; ++i) {
            // Метки по оси X
            sf::Text xLabel;
            xLabel.setFont(font);
            xLabel.setString(std::to_string(minX + i * (maxX - minX) / 10)); 
            xLabel.setCharacterSize(12); 
            xLabel.setFillColor(sf::Color::Black);
            xLabel.setPosition(50 + i * (windowWidth - 100) / 10, windowHeight - 45); 
            window.draw(xLabel); 

            // Метки по оси Y
            sf::Text yLabel;
            yLabel.setFont(font);
            yLabel.setString(std::to_string(minY + i * (maxY - minY) / 10));
            yLabel.setCharacterSize(12);
            yLabel.setFillColor(sf::Color::Black); 
            yLabel.setPosition(10, windowHeight - 50 - i * (windowHeight - 100) / 10); 
            window.draw(yLabel); 
        }

        window.display();
    }
}


