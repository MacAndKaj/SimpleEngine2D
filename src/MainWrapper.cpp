#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics.hpp>
#include <random>
#include <functional>
#include <cstdlib>
#include <cmath>
#include <Engine.hpp>
#include <Windows/MainWindow.hpp>

class MainWrapper
{
public:
    int execute();
};

int MainWrapper::execute()
{
    return 0;
}



int main()
{
    eng::Engine engine;
    auto window = std::make_unique<MainWindow>(engine);
    return window->run();
}