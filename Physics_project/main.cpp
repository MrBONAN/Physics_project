#include "Headers.h"

#include <sstream>
int main ()
{
    sf::RenderWindow window(sf::VideoMode(1050, 700), "SFML works!");
    window.setFramerateLimit(60);

    string path = "Icons_2.png";
    OBJ::Init(path);

    Interface intface(window);

    //std::stringstream ss;
    //{
    //    boost::archive::text_oarchive oa(ss);
    //
    //    player to_save;
    //    to_save.username = "bla";
    //    to_save.password = "blo";
    //    to_save.inv = {
    //            { 1, 17 },
    //            { 2, 11 },
    //            { 3, 8800 },
    //            { 4, 0 },
    //    };
    //
    //    oa << to_save;
    //} // <-- destructor of text_oarchive
    //std::cout << "Serialized stream: " << std::quoted(ss.str()) << std::endl;
    //player loaded;
    //{
    //    boost::archive::text_iarchive ia(ss);
    //    ia >> loaded;
    //}
    //std::cout << "Roundtrip username:" << std::quoted(loaded.username)
    //    << " password:" << std::quoted(loaded.password) << std::endl;
    //for (auto& it : loaded.inv) {
    //    std::cout << " - item " << it.itemID << " count:" << it.itemCount << std::endl;
    //}

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            intface.checkAllInteractions(event);
        }

        window.clear(sf::Color(200, 200, 200, 255));
        
        intface.show();
        window.display();
    }

    return 0;
}

class PlayerInventory {
    friend class boost::serialization::access;
    template <class Archive> void serialize(Archive& ar, unsigned) {
        ar& itemID& itemCount;
    }

public:
    int itemID;
    int itemCount;
};

class player {
    friend class boost::serialization::access;
    template <class Archive> void serialize(Archive& ar, unsigned) {
        ar& username& password& inv;
    }

public:
    std::string                  username;
    std::string                  password;
    std::vector<PlayerInventory> inv;
};