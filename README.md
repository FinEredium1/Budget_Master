# Welcome to Budget Master

The Personal Budget Manager is a program designed to help users manage their finances effectively. 
Users can create accounts, log in, deposit or withdraw funds, and view their account balance. 
The program provides a user-friendly interface for easy navigation and interaction. 
The program will help users effectively manage their finances by tracking income, expenses, 
and savings. Users will be able to create an account by providing a name and password. 
In the future, they will be able to use those credentials to log in securely, and access a 
dashboard displaying an overview of their financial status.

PROGRAM DOCUMENTATION: To run the program, compile the provided code using a C++ compiler that 
supports the SFML library. Ensure that the SFML library is properly linked during compilation. 
Once compiled, execute the program, and follow the on-screen instructions. If you are using this 
for the first time then you need to create your own account first. Simply, write a username and 
password and click the create account. The program will briefly close to process the data and 
next time you open the program, you can input that same user and password to log in to your 
account. Upon logging in, you will see a dashboard displaying your current wealth and at this 
point, you can either decide to deposit or withdraw money by simply clicking either of those 
two buttons. Once you have accomplised your tasks, simply close the program and it will keep 
track of your finances for next time you open it using your log in credencials. All the functions 
related to log in and account operations are within the log_in class and all the functions 
responsible for creating SFML background are in the text.hpp file. If I had more time, then I 
would have tried to:
- encrypt the data.txt file so no one could directly access that file.
- create a dashboard so which will display all records of your withdrawls and deposits.
- create a data visualization graph.
- Customizable settings.


CLASS DESCRIPTION: The code includes custom classes such as log_in, TextInput, TextDisplay, and 
Rectangle, each serving specific purposes. log_in manages user accounts and financial transactions. 
TextInput and TextDisplay handle user input and display text on the screen, respectively. 
Rectangle is a utility class to draw rectangular shapes on the GUI. These classes encapsulate 
data and functionality related to their respective responsibilities, enhancing the program's 
structure and organization.

LIST DATA STRUCTURE: The code uses a vector data structure to manage user accounts (vector<account*>) 
within the log_in class. Vectors provide dynamic resizing and efficient random access, making them 
suitable for storing and managing a variable number of accounts. This structure simplifies account 
management and supports scalability for handling a large number of users.

FILE I/O:  File I/O operations are incorporated into the log_in class to read and write account 
information from/to a file (data.txt). This file stores user account details such as usernames, 
passwords, and account balances. File I/O is essential for persisting user data across program 
sessions, ensuring data integrity, and facilitating user account management.

REFLECTIONS: Throughout this project, I gained valuable experience in designing and implementing a
 user-friendly financial management system. I encountered challenges related to the main design, 
 event handling, encrypting files and data management, but I learned effective strategies to 
 overcome them. If I were to redo this project, I would focus on improving code readability, 
 implementing additional features such as transaction history and data encryption for enhanced 
 security, and optimizing the user interface for better usability. These experiences will help 
 me improve the projects I will create in the future.