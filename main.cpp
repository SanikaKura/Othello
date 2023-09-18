#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "othello.h"
#include <fstream>
using namespace std;
using namespace sf;



void setText(sf::Text &text, float x, float y){

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(x, y));
}


int main() {

    board boardy(8, 8);
    pushfunc(boardy);

    vector<int> clickAddress = {27, 28, 35, 36};
    int black_turn = 1;
    int winner = 0;
    bool blackwin;
    int restart = 0;
    bool onePlayer;


    int x = 50 * 8;
    int y = 50 * 8;
    sf::RenderWindow window(sf::VideoMode(x, y), "SFML works!");
    sf::Text title;
    sf::Font fontType;
    fontType.loadFromFile("font.ttf");

    sf::Text oneplayer_option;
    oneplayer_option.setFont(fontType);
    oneplayer_option.setString("ONEPLAYER");
    oneplayer_option.setCharacterSize(24);
    oneplayer_option.setStyle(sf::Text::Bold);
    setText(oneplayer_option, 100, 220);

    sf::Text twoplayer_option;
    twoplayer_option.setFont(fontType);
    twoplayer_option.setString("TWOPLAYER");
    twoplayer_option.setCharacterSize(24);
    twoplayer_option.setStyle(sf::Text::Bold);
    setText(twoplayer_option, 300, 220);

    title.setFont(fontType);
    title.setString("WELCOME TO OTHELLO!");
    title.setCharacterSize(24);
    title.setStyle(sf::Text::Bold | sf::Text::Underlined);
    setText(title, x / 2.0f, (y / 2.0f) - 125);


    /*sf::Text name_input;
    name_input.setString("Enter your name: ");
    name_input.setCharacterSize(20);
    name_input.setFont(fontType);
    setText(name_input, x / 2.0f, (y / 2.0f) - 50);
    name_input.setStyle(sf::Text::Bold);
    string cursor = "|"; */
    sf::Text inputText;

    //inputText.setString("Enter your name: ");
    inputText.setFont(fontType);
    inputText.setCharacterSize(20);
    //setText(inputText, 800/2.0f, (600/2.0f)-75);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    window.close();
                }
            }
            if (event.type == Event::MouseButtonPressed) {
                if (Mouse::isButtonPressed(Mouse::Left)) {
                    if (0 < event.mouseButton.x && event.mouseButton.x < 200 ) {
                        onePlayer = true;
                        window.close();
                    }
                    else if (201 < event.mouseButton.x && event.mouseButton.x < 400 &&
                             0 < event.mouseButton.y && event.mouseButton.y < 400) {
                        onePlayer = false;
                        window.close();
                    }
                }
            }
        }
            window.clear(sf::Color::Blue);
            window.draw(title);
            window.draw(oneplayer_option);
            window.draw(twoplayer_option);
            window.display();
    }

    //board boardy(3, 26, 25);
    sf::RenderWindow gameWindow(sf::VideoMode(400, 500), "Othello");

    Sprite redX;
    Texture redXt;
    redXt.loadFromFile("redX.png");
    redX.setTexture(redXt);
    redX.setPosition(25, 415);

    Sprite win;
    Texture wint;
    wint.loadFromFile("win_image.jpg");
    win.setTexture(wint);
    win.setPosition(312, 415);

    Sprite black_;
    Texture tblack;
    tblack.loadFromFile("blacktile50.png");
    black_.setTexture(tblack);
    black_.setPosition(250, 427);

    Sprite white_;
    Texture twhite;
    twhite.loadFromFile("whitetile50.png");
    white_.setTexture(twhite);
    white_.setPosition(250, 427);


    Sprite blank;
    Texture blankt;
    Sprite blank1;
    Texture blankt1;
    Sprite blackdefault;
    Texture blackdefaultt;
    Sprite blackdefault1;
    Texture blackdefaultt1;
    Sprite white;
    Texture whitet;
    Sprite drawcell; Texture drawcellt;





    while (gameWindow.isOpen()) {
        gameWindow.clear(sf::Color::White);
        sf::Event eventType;




        while (gameWindow.pollEvent(eventType)) {
            /*if(eventType.key.code == sf::Keyboard::Enter){
                //window.clear(sf::Color::White);
                gameWindow.close(); } */
            if (eventType.type == sf::Event::Closed) {
                gameWindow.close();
            }
        }

        if (!onePlayer){
        for (int t = 0; t < 64; t++) {
            int xcoord = t % 8;
            int ycoord = t / 8;
            xcoord *= 50;
            ycoord *= 50;

            if (boardlist[t].color == 1) {
                drawcellt.loadFromFile("blacktile50.png");
                drawcell.setTexture(drawcellt);
                drawcell.setPosition(xcoord, ycoord);
                gameWindow.draw(drawcell);
            } else if (boardlist[t].color == 2) {
                drawcellt.loadFromFile("whitetile50.png");
                drawcell.setTexture(drawcellt);
                drawcell.setPosition(xcoord, ycoord);
                gameWindow.draw(drawcell);
            } else if (boardlist[t].color == 0) {
                drawcellt.loadFromFile("blank50.png");
                drawcell.setTexture(drawcellt);
                drawcell.setPosition(xcoord, ycoord);
                gameWindow.draw(drawcell);
            }
        }}  ///continuously draws board


        if (onePlayer){
            for (int t = 0; t < 64; t++) {
                int xcoord = t % 8;
                int ycoord = t / 8;
                xcoord *= 50;
                ycoord *= 50;
                drawcellt.loadFromFile("blank50.png");
                drawcell.setTexture(drawcellt);
                drawcell.setPosition(xcoord, ycoord);
                gameWindow.draw(drawcell);
            }

            blankt.loadFromFile("whitetile50.png");
            blank.setTexture(blankt);
            blank.setPosition(27%8 *50, 27/8 *50);
            gameWindow.draw(blank);
            blankt1.loadFromFile("whitetile50.png");
            blank1.setTexture(blankt1);
            blank1.setPosition(36%8 *50, 36/8 *50);
            gameWindow.draw(blank1);

            blackdefaultt.loadFromFile("blacktile50.png");
            blackdefault.setTexture(blackdefaultt);
            blackdefault.setPosition(28%8 *50, 28/8 *50);
            gameWindow.draw(blackdefault);

            blackdefaultt1.loadFromFile("blacktile50.png");
            blackdefault1.setTexture(blackdefaultt1);
            blackdefault1.setPosition(35%8 *50, 35/8 *50);
            gameWindow.draw(blackdefault1);

            /*blackdefaultt1.loadFromFile("blacktile50.png");
            blackdefault1.setTexture(blackdefaultt1);
            blackdefault1.setPosition(35%8 *50, 35/8 *50);
            gameWindow.draw(blackdefault1);*/
        }  ///draws default board


        if (onePlayer && (black_turn % 2 == 0)){ //computer turn WHITE
            int click;
            click = white_turn(black_turn); //returns a random valid position
            clickAddress.push_back(click);
            isvalid(click, black_turn);

            boardlist[click].color = 2;
            sleep(seconds(1));

            for (int flips = 0; flips < boardlist[click].turntiles.size(); flips++) {
                { boardlist[boardlist[click].turntiles[flips]].color =2 ;}
            }

            black_turn+=1;
            sleep(milliseconds(250));

            if (!gamecontinue(black_turn)) {
                winner += 1;
            }
        }

        for (int t = 0; t < 64; t++) {
            int xcoord = t % 8;
            int ycoord = t / 8;
            xcoord *= 50;
            ycoord *= 50;

            if (boardlist[t].color == 2) {
                drawcellt.loadFromFile("whitetile50.png");
                drawcell.setTexture(drawcellt);
                drawcell.setPosition(xcoord, ycoord);
                gameWindow.draw(drawcell);}
        }



        if (winner > 0) {
            gameWindow.draw(win);
            int blackpiece = 0;
            int whitepiece = 0;
            for (int u = 0; u < 64; u++) {
                if (boardlist[u].color == 1) { blackpiece += 1; }
                if (boardlist[u].color == 2) { whitepiece += 1; }
            }
            if (blackpiece > whitepiece) { blackwin = true; }
            else { blackwin = false; }
            if (blackwin) {
                gameWindow.draw(black_);
            }
            if (!blackwin) {
                gameWindow.draw(white_);
            }
        }




        while (gameWindow.pollEvent(eventType)) { ///regular left click and debug button code
            if (eventType.type == Event::Closed) {
                gameWindow.close();
            }
            if (eventType.type == Event::MouseButtonPressed) {
                if (Mouse::isButtonPressed(Mouse::Left)) {
                    int click;
                    if (0 < eventType.mouseButton.x && eventType.mouseButton.x < 400 &&
                        0 < eventType.mouseButton.y && eventType.mouseButton.y < 400) {

                        float clickcoordx = eventType.mouseButton.x / 50;
                        float clickcoordy = eventType.mouseButton.y / 50;
                        click = clickcoordx + clickcoordy * 8;

                        clickAddress.push_back(click);

                        if (click != 27 && click != 28 && click != 35 && click != 36) {
                            int counter = 0;
                            for (int o = 0; o < clickAddress.size(); o++) {
                                if (clickAddress[o] == click && boardlist[click].color != 0) {
                                    counter += 1;
                                }
                            }
                            if (boardlist[click].color == 0) {
                                if (counter == 0 && isadjacent(click, boardlist, black_turn) &&
                                    validFlip(click, black_turn) &&
                                    isvalid(click, black_turn)) {

                                    /*cout << endl << "flip_size__" << boardlist[click].flip.size() << endl;
                                    cout << "validflip __  " << boardlist[click].validflip.size() << endl;
                                    cout << "tiles_size____" << boardlist[click].turntiles.size();
                                    for (int o = 0; o < boardlist[click].validflip.size(); o++) {
                                        cout << "     " << boardlist[click].validflip[o] << "___";
                                    }
                                    cout << endl;
                                    for (int o = 0; o < boardlist[click].turntiles.size(); o++) {
                                        cout << "     " << boardlist[click].turntiles[o] << "___";
                                    }*/


                                    if (!onePlayer){
                                    black_turn += 1;
                                    if (black_turn % 2 == 0) {
                                        boardlist[click].color = 1;
                                        for (int flips = 0; flips < boardlist[click].turntiles.size(); flips++) {
                                            { boardlist[boardlist[click].turntiles[flips]].color = 1; }
                                        }
                                        cout << " _______" << boardlist[click].turntiles.size() << "_________ " << endl
                                             << endl;

                                    } else if (black_turn % 2 == 1) {
                                        boardlist[click].color = 2;
                                        for (int flips = 0; flips < boardlist[click].turntiles.size(); flips++) {
                                            { boardlist[boardlist[click].turntiles[flips]].color = 2; }
                                        }
                                        cout << " _______" << boardlist[click].turntiles.size() << "_______ " << endl
                                             << endl;
                                    } }

                                    if (onePlayer){
                                        boardlist[click].color = 1;
                                        for (int flips = 0; flips < boardlist[click].turntiles.size(); flips++) {
                                            { boardlist[boardlist[click].turntiles[flips]].color = 1; }
                                        }
                                        black_turn+=1;
                                    }


                                }
                            }
                        }

                    } else if (25 < eventType.mouseButton.x && eventType.mouseButton.x < 100 &&
                               /// debug button
                               415 < eventType.mouseButton.y && eventType.mouseButton.y < 490) {
                        restart += 1;

                    }
                } else if (Mouse::isButtonPressed(Mouse::Right)) {

                }
            }
            if (!gamecontinue(black_turn)) {
                winner += 1;
            }
        }


        for (int t = 0; t < 64; t++) {
            int xcoord = t % 8;
            int ycoord = t / 8;
            xcoord *= 50;
            ycoord *= 50;

            if (boardlist[t].color == 1) {
                drawcellt.loadFromFile("blacktile50.png");
                drawcell.setTexture(drawcellt);
                drawcell.setPosition(xcoord, ycoord);
                gameWindow.draw(drawcell);}
        }


        /*if (onePlayer && (black_turn % 2 == 0)){
            int click;
            click = white_turn(black_turn);
            clickAddress.push_back(click);
            isvalid(click, black_turn);

            boardlist[click].color = 2;
            sleep(seconds(1));

            for (int flips = 0; flips < boardlist[click].turntiles.size(); flips++) {
                { boardlist[boardlist[click].turntiles[flips]].color =2 ;}
            }
            if (!gamecontinue(black_turn+1)) {
                winner += 1;
            }
            sleep(seconds(1));
        }

        for (int t = 0; t < 64; t++) {
            int xcoord = t % 8;
            int ycoord = t / 8;
            xcoord *= 50;
            ycoord *= 50;

            if (boardlist[t].color == 2) {
                drawcellt.loadFromFile("whitetile50.png");
                drawcell.setTexture(drawcellt);
                drawcell.setPosition(xcoord, ycoord);
                gameWindow.draw(drawcell);}
        }*/


        gameWindow.draw(redX);

        /*if (winner > 0) {
            gameWindow.draw(win);
            int blackpiece = 0;
            int whitepiece = 0;
            for (int u = 0; u < 64; u++) {
                if (boardlist[u].color == 1) { blackpiece += 1; }
                if (boardlist[u].color == 2) { whitepiece += 1; }
            }
            if (blackpiece > whitepiece) { blackwin = true; }
            else { blackwin = false; }
        if (blackwin) {
            gameWindow.draw(black_);
        }
        if (!blackwin) {
            gameWindow.draw(white_);
        }
        }*/

        for( int squares = 0; squares < clickAddress.size(); squares ++) {
            //cout << boardlist[clickAddress[squares]].color << " ";
            int xcoord = clickAddress[squares] % 8;
            int ycoord = clickAddress[squares] / 8;
            xcoord *= 50;
            ycoord *= 50;
            /*if (boardlist[clickAddress[squares]].color == 1) {
                drawcellt.loadFromFile("blacktile50.png");
                drawcell.setTexture(drawcellt);
                drawcell.setPosition(xcoord, ycoord);
                gameWindow.draw(drawcell);
            } else if (boardlist[clickAddress[squares]].color == 2) {

                drawcellt.loadFromFile("whitetile50.png");
                drawcell.setTexture(drawcellt);
                drawcell.setPosition(xcoord, ycoord);
                gameWindow.draw(drawcell);
            }*/

            /*for (int r= 0; r < boardlist[squares].validflip.size(); r ++){
                cout <<"_FLIP_" <<  boardlist[squares].validflip[r] << "   ";
            }*/

        }
        cout << endl;

        if (restart % 2 == 1){
            boardlist.clear();
            pushfunc(boardy);
            vector<int> clickAddress = {27, 28, 35, 36};
            black_turn = 1;
            restart += 1;

            /*for (int c = 0; c < 64; c ++ ){
                boardlist[c].color = 0;
                boardlist[c].validflip.clear();boardlist[c].flip.clear();boardlist[c].turntiles.clear();
            }
            boardlist[27].color = 2;  boardlist[28].color =1;boardlist[35].color =1; boardlist[36].color =2;
            restart += 1;*/
        }



        gameWindow.display();
    }

    return 0;
}
