#include "log_in.h"
#include "text.hpp"

int main()
{
    ifstream file("data.txt"); // load in file for reading and writing
    ofstream file1("data.txt", ios::app);
    log_in lg;

    string name = "";
    double amount = 5;


    int screenWidth = 1440;
    int screenHeight = 840;


    RenderWindow window(VideoMode(screenWidth, screenHeight), "Eredium INC");
    window.setFramerateLimit(60);
    TextInput User_input(sf::Vector2f(480, 45), sf::Vector2f(310, 330), 320, 335); // Creates textinput for username
    TextInput Pass_input(sf::Vector2f(480, 45), sf::Vector2f(310, 410), 320, 415); // Creates textinput for password


    Pass_input.setActive(false); 
    User_input.setActive(false); // Initially set it to inactive


    Rectangle Top(Vector2f(1440, 240), Vector2f(0,0), Color::Red); // Top cover
    Rectangle userpass_cover(Vector2f(780, 200), Vector2f(50, 300), Color::Red); // Username and Password screen cover


    TextDisplay header("Welcome to Personal Budget Manager", 0, 60, Vector2f(100,50), Color::Black); // Display only
    TextDisplay header1("BANK OF EREDIUM", 1, 40, Vector2f(1040,180), Color::Black); // Company name

    TextDisplay user("Username: ", 0, 40, Vector2f(100,320), Color::Black); // Display only
    TextDisplay pass("Password: ", 0, 40, Vector2f(100,400), Color::Black); // Display only

    Rectangle log(Vector2f(270, 150), Vector2f(150, 600), Color::Red); // Creates button cover for log in
    TextDisplay log_text("Log In", 0, 40, Vector2f(220,650), Color::Black); // Display only
    Rectangle create(Vector2f(370, 150), Vector2f(520, 600), Color::Red); // Creates button cover for create account
    TextDisplay create_text("Create Account", 0, 40, Vector2f(570,650), Color::Black); // Display only

    
    Rectangle next_page(Vector2f(1440, 600), Vector2f(0, 240), Color::White); // Next page cover 
    Rectangle deposit(Vector2f(270, 150), Vector2f(150, 600), Color::Red); // Deposit cover
    TextDisplay deposit_text("Deposit", 0, 40, Vector2f(220,650), Color::Black); // Display only
    Rectangle withdraw(Vector2f(370, 150), Vector2f(520, 600), Color::Red); // Withdraw cover
    TextDisplay withdraw_text("Withdraw", 0, 40, Vector2f(570,650), Color::Black); // Display only

    TextDisplay display_name("", 0, 40, Vector2f(150,450), Color::Black); // Initalizes text input for later use
    TextDisplay display_amount("", 0, 40, Vector2f(150,500), Color::Black);

    Rectangle next_next_cover(Vector2f(1440, 220), Vector2f(0, 230), Color::Red); // Text input prompt cover
    TextDisplay ask_amount("Input Amount: ", 0, 40, Vector2f(150,300), Color::Black); // Displays amount
    TextInput amnt(Vector2f(120, 45), sf::Vector2f(440, 300), 450, 310); // Amount input

    RectangleShape submit_button(Vector2f(140, 80)); // submit button
    submit_button.setFillColor(Color::White);
    submit_button.setOutlineThickness(5);
    submit_button.setOutlineColor(Color::Black);
    submit_button.setPosition(Vector2f(730, 290));
    TextDisplay submit_text("Submit", 0, 40, Vector2f(740,300), Color::Black);




    bool logged_in = false;
    bool depo = false;
    bool submit = false;
    bool with = false;
    Event event;

    while (window.isOpen())
    {

        window.clear(Color::White);
        
        Top.draw(window);
        userpass_cover.draw(window);
        header.draw(window);
        header1.draw(window);
        user.draw(window);
        pass.draw(window);

        log.draw(window);
        log_text.draw(window);
        create.draw(window);
        create_text.draw(window);

        if (logged_in) { // This is essentially next page after log in
            next_page.draw(window);
            deposit.draw(window);
            deposit_text.draw(window);
            withdraw.draw(window);
            withdraw_text.draw(window);

            display_name.setText("Hi " + name);
            display_name.draw(window);
            display_amount.setText("Your account has " + to_string(amount));
            display_amount.draw(window);
        }

        if (depo||with){ // Page that appears if you try to deposit or withdraw
            next_next_cover.draw(window);
            ask_amount.draw(window);
            amnt.draw(window, submit);
            window.draw(submit_button);
            submit_text.draw(window);
        }


        while (window.pollEvent(event))
        {

            if (event.type == Event::Closed)
            {
                window.close();
            }
            else if (event.type == Event::MouseButtonPressed) { // Keeps track of mouse event
                if (event.mouseButton.button == Mouse::Left) {
                    Vector2i mousePosition = Mouse::getPosition(window);
                    // Sets Username box active
                    if ((mousePosition.x >=310 && mousePosition.x <= 790) && (mousePosition.y >= 330 && mousePosition.y <= 375) && !logged_in){ 
                        User_input.setActive(true);
                    }
                    else {
                        User_input.setActive(false);
                    }

                    // Sets Password box active
                    if ((mousePosition.x >=310 && mousePosition.x <= 790) && (mousePosition.y >= 410 && mousePosition.y <= 455 && !logged_in) ){
                        Pass_input.setActive(true);
                    }
                    else {
                        Pass_input.setActive(false);
                    }

                    // Occurs if you try to deposit
                    if ((mousePosition.x >=150 && mousePosition.x <= 420) && (mousePosition.y >= 600 && mousePosition.y <= 750) && logged_in ){
                        depo = true;
                        with = false;
                    }
                    // Occurs if you try to withdraw
                    if ((mousePosition.x >=520 && mousePosition.x <= 890) && (mousePosition.y >= 600 && mousePosition.y <= 750) && logged_in ){
                        with = true;
                        depo = false;

                    }

                    // Asks user for money input
                    if ((mousePosition.x >=740 && mousePosition.x <= 870) && (mousePosition.y >= 300 && mousePosition.y <= 380) && logged_in && depo){
                        file.close();
                        file1.close();
                        lg.deposit("data.txt", stod(amnt.get_text())); // 2nd parameter is supposed to be a double
                        ifstream file("data.txt");
                        ofstream file1("data.txt", ios::app);
                        amount += stod(amnt.get_text());
                    }

                    // Asks user for money input
                    if ((mousePosition.x >=740 && mousePosition.x <= 870) && (mousePosition.y >= 300 && mousePosition.y <= 380) && logged_in && with){
                        file.close();
                        file1.close();
                        lg.withdraw("data.txt", stod(amnt.get_text())); // 2nd parameter is supposed to be a double
                        ifstream file("data.txt");
                        ofstream file1("data.txt", ios::app);
                        if (amount - stod(amnt.get_text()) >= 0){
                            amount -= stod(amnt.get_text());
                        }
                    }


                    // Sets amount box to active
                    if ((mousePosition.x >=440 && mousePosition.x <= 540) && (mousePosition.y >= 300 && mousePosition.y <= 345) && (depo||with)){
                        amnt.setActive(true);
                    }

                    else {
                        amnt.setActive(false);
                    }
                        

                    // Log in button
                    if ((mousePosition.x >=150 && mousePosition.x <= 420) && (mousePosition.y >= 600 && mousePosition.y <= 750 && !logged_in) ){
                        lg.push_in(file);
                        if (lg.access_account(User_input.get_text(), Pass_input.get_text())){
                            logged_in = true;
                            name = User_input.get_text();
                            amount = lg.get_amount();
                        }
                    }

                    // Create new account button
                    if ((mousePosition.x >=520 && mousePosition.x <= 890) && (mousePosition.y >= 600 && mousePosition.y <= 750) && !logged_in ){
                        lg.create_account(User_input.get_text(), Pass_input.get_text(), file1);
                        cout << "New Account created with " << User_input.get_text() << endl;
                        cout << "Closing Program to process new account..." << endl;
                        window.close();
                    }

                }
            }
            else if (event.type == sf::Event::TextEntered) {
                if (User_input.isActive()) {
                    User_input.handleInput(event, false);
                }
                if (Pass_input.isActive()) {
                    Pass_input.handleInput(event, false);
                }
                if (amnt.isActive()){
                    amnt.handleInput(event, true);
                }
            }
        }

        User_input.draw(window, logged_in);
        Pass_input.draw(window, logged_in);


        window.display();
    }
    return 0;
}