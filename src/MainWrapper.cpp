#include <SFML/Graphics/Rect.hpp>

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
    sf::Rect<int> rec;
    MainWrapper App;
    return App.execute();
}