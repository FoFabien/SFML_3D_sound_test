#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

// quick code to test sound positioning
int main()
{
    std::cout << "Loading..." << std::endl;
    sf::SoundBuffer bL, bR;
    if (!bL.loadFromFile("04L.wav"))
        return -1;
    if (!bR.loadFromFile("04R.wav"))
        return -1;

    sf::Listener::setPosition(0, 0, 0);
    sf::Listener::setDirection(1.f, 0.f, 0.f);
    sf::Listener::setGlobalVolume(100);
    sf::Sound sL, sR;
    sL.setBuffer(bL);
    sR.setBuffer(bR);

    sL.setPosition (-1, -1.f, 0);
    sL.setRelativeToListener(true);
    sL.play();

    sR.setPosition (1, -1.f, 0);
    sR.setRelativeToListener(true);

    sL.play();
    sR.play();

    std::cout << "Playing sound..." << std::endl;
    while(sL.getStatus() == sf::Sound::Playing || sR.getStatus() == sf::Sound::Playing)
    {
        sf::sleep(sf::milliseconds(10));
    }
    sL.stop();

    return 0;
}
