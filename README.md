Contact Manager

A C++ console-based Contact Manager that allows users to efficiently manage and classify their contacts using a custom Dynamic Array (DArray) data structure.
The project demonstrates Object-Oriented Programming (OOP) principles and implements CRUD operations (Create, Read, Update, Delete) along with a classification system to organize contacts into categories such as Friends, Family, and Work.

🚀 Features

➕ Add new contacts with name, phone number, email, and category

📋 View all contacts in a formatted list

🔍 Search for contacts by name, phone number, or category

✏️ Edit existing contact information

❌ Delete contacts from the list

🗂️ Classify contacts by category (Friends, Family, Work)

💾 Manage data dynamically in memory using a custom DArray implementation

🧠 Concepts Used

Object-Oriented Programming (OOP)

Classes and Encapsulation

Dynamic Memory Allocation

Custom Data Structure (Dynamic Array)

CRUD Operations

(Optional) File Handling for persistent data

🏗️ Project Structure
📁 ContactManager
│
├── 📄 main.cpp         → Entry point, handles menu and user interaction  
├── 📄 Contact.h        → Defines the Contact class (name, phone, email, category)  
├── 📄 Contact.cpp      → Implements Contact class methods  
├── 📄 DArray.h         → Template class for the Dynamic Array implementation  
└── 📄 README.md        → Project documentation  



🛠️ Tech Stack

Language: C++

IDE: Code::Blocks / Visual Studio / VS Code

Compiler: g++

⚙️ Installation & Run

Clone this repository:

git clone https://github.com/YourUsername/contact-manager-cpp.git


Open the project in your IDE or terminal.

Compile the code:

g++ main.cpp Contact.cpp -o contact_manager


Run the program:

./contact_manager

🧩 Example Output
==== Contact Manager ====
1. Add Contact
2. View Contacts
3. Search Contact
4. Edit Contact
5. Delete Contact
6. Exit
Choose an option: 1

Enter Name: Ahmed
Enter Phone: 0109876543
Enter Email: ahmed@gmail.com
Enter Category (Friends / Family / Work): Work
Contact added successfully!

--------------------------------
Name: Ahmed
Phone: 0109876543
Email: ahmed@gmail.com
Category: Work
--------------------------------
