# Specs
### To start this project's review, I need to give a little intro about my computer. I have a MacBook, with these specs:
    CPU: 2,3 GHz Quad-Core Intel Core i5 
    RAM: 6 GB 2133 MHz LPDDR3 
    SSD: Macintosh HD 
> [!IMPORTANT]
> All of the testing was done with the same files that contained 1000, 10000, 100000, 1000000, 10000000 students.

# Information about the project
## The rule of five
The "Rule of Five" is a programming guideline that outlines five essential C++ class members, which manipulate resources. If you define one of these operators, you should define the remaining four to ensure proper management of resources (such as memory) in your class.
## What does the rule of five contain?
### Destructor: 
Responsible for releasing resources allocated by the class. It's invoked when an object of the class is destroyed or goes out of scope.
### Copy Constructor: 
Copies an object of the class, which uses the same resource(-es) as the original object. It's essential to ensure deep copying to avoid double deletion of the same resource.
### Copy Assignment Operator: 
Corresponds to the " = " operator. It copies the given object into an existing object that already has the same or similar resources. It's crucial to ensure that existing resources are released before assigning new ones.
### Move Constructor: 
Transfers resources from one object to another without copying them, simply transferring resource ownership. It's more efficient than deep copying because it doesn't copy resources but transfers them.
### Move Assignment Operator: 
Corresponds to the " = " operator but operates on moveable objects. Similar to the move constructor, it allows assigning another moveable object to an existing object, efficiently managing resources.
