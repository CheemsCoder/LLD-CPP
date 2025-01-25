#include <iostream>
using namespace std;

/*
======================= ABSTRACT FACTORY PATTERN =======================
The Abstract Factory Pattern is a creational design pattern. 
It provides an interface for creating families of related or dependent objects 
without specifying their concrete classes.

**When to Use:**
- You want to create a set of related objects (like buttons and textboxes) 
  that work well together.
- You want to enforce a common interface for object creation, ensuring 
  consistency across different products.

**Components of Abstract Factory Pattern:**
1. **Abstract Factory (IFactory):** Declares methods for creating abstract products.
2. **Concrete Factory (MacFactory, WindowsFactory):** Implements the creation of concrete products.
3. **Abstract Product (IButton, ITextBox):** Declares interfaces for a set of related products.
4. **Concrete Product (MacButton, WindowsButton, etc.):** Implements the Abstract Product interfaces.

**Advantages:**
- Encourages consistency in creating related objects.
- Supports the Open/Closed Principle by making it easier to add new families of products.
- Provides better scalability.

**UML Representation:**
AbstractFactory ---> ConcreteFactory1
                   ---> ConcreteFactory2
         |                     |
   AbstractProductA   ConcreteProductA1
   AbstractProductB   ConcreteProductB1
                                |
                        ConcreteProductB2

**Class Relationships:**
                      +-------------------+
                      |  GUIAbstractFactory |
                      +-------------------+
                                |
                +---------------+---------------+
                |                               |
         +--------------+               +--------------+
         |  MacFactory  |               | WindowsFactory|
         +--------------+               +--------------+
                |                               |
      +---------+--------+          +----------+--------+
      |                  |          |                   |
+--------------+   +--------------+   +--------------+   +--------------+
|  MacButton   |   | MacTextBox   |   |WindowsButton |   |WindowsTextBox|
+--------------+   +--------------+   +--------------+   +--------------+

**Flow:**
- `GUIAbstractFactory` decides which concrete factory to use based on input.
- The concrete factory creates specific product objects (e.g., `MacButton`).
- Products (like `Button` and `TextBox`) are used without knowing their concrete implementations.
=======================================================================
*/

// Abstract Product for Button
class IButton {
  public:
    virtual void Press() = 0; // Abstract method for pressing a button
};

// Concrete Product for Mac Button
class MacButton : public IButton {
  public:
    void Press() {
      cout << "Mac Button Pressed." << endl;
    }
};

// Concrete Product for Windows Button
class WindowsButton : public IButton {
  public:
    void Press() {
      cout << "Windows Button Pressed." << endl;
    }
};

// Abstract Product for TextBox
class ITextBox {
  public:
    virtual void ShowText() = 0; // Abstract method for showing a text box
};

// Concrete Product for Mac TextBox
class MacTextBox : public ITextBox {
  public:
    void ShowText() {
      cout << "Mac TextBox Created" << endl;
    }
};

// Concrete Product for Windows TextBox
class WindowsTextBox : public ITextBox {
  public:
    void ShowText() {
      cout << "Windows TextBox Created" << endl;
    }
};

// Abstract Factory Interface
class IFactory {
  public:
    virtual IButton* CreateButton() = 0; // Abstract method for creating a button
    virtual ITextBox* TextBox() = 0;     // Abstract method for creating a text box
};

// Concrete Factory for Mac
class MacFactory : public IFactory {
  public:
    IButton* CreateButton() {
      return new MacButton();
    }
    ITextBox* TextBox() {
      return new MacTextBox();
    }
};

// Concrete Factory for Windows
class WindowsFactory : public IFactory {
  public:
    IButton* CreateButton() {
      return new WindowsButton();
    }
    ITextBox* TextBox() {
      return new WindowsTextBox();
    }
};

// Factory Producer: Creates the appropriate factory based on the OS type
class GUIAbstractFactory {
  public:
    static IFactory* CreateFactory(string type) {
      if (type == "mac") {
        return new MacFactory();
      } else if (type == "windows") {
        return new WindowsFactory();
      } else {
        cout << "Please provide a valid OS type." << endl;
        return nullptr;
      }
    }
};

int main() {
  cout << "Enter Your Machine OS (mac/windows): " << endl;
  string osType;
  cin >> osType;

  IFactory* factory = GUIAbstractFactory::CreateFactory(osType);

  if (factory) { // Check if a valid factory was returned
    IButton* button = factory->CreateButton();
    button->Press();

    ITextBox* textbox = factory->TextBox();
    textbox->ShowText();

    // Clean up dynamically allocated memory
    delete button;
    delete textbox;
    delete factory;
  }

  return 0;
}
