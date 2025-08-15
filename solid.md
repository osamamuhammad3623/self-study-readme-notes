# Notes on SOLID principles

## Single Responsibility Principle (SRP)
### Concept
A class should have only one reason to change, meaning it should have only one job or responsibility.

### Why it's important
- Reduced Complexity: Classes are smaller and easier to understand.
- Improved Maintainability: Changes related to one responsibility won't inadvertently affect others.
- Higher Cohesion: The elements within a class are more closely related.
Example:

### Explanation
Let's say we have a `User` class that handles user data and also user persistence (saving to a database). This violates SRP.

#### Bad Example (Violates SRP):

    public class User {
        private String name;
        private String email;

        public User(String name, String email) {
            this.name = name;
            this.email = email;
        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        public String getEmail() {
            return email;
        }

        public void setEmail(String email) {
            this.email = email;
        }

        // Responsibility 1: User data management (getters/setters)

        // Responsibility 2: User persistence
        public void saveUserToDatabase() {
            // This is a simplified example. In a real app, use a proper ORM or DAO.
            try (Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb", "user", "password")) {
                String sql = "INSERT INTO users (name, email) VALUES (?, ?)";
                try (PreparedStatement statement = connection.prepareStatement(sql)) {
                    statement.setString(1, this.name);
                    statement.setString(2, this.email);
                    statement.executeUpdate();
                    System.out.println("User " + this.name + " saved to database.");
                }
            } catch (SQLException e) {
                // In a real app, handle this exception more gracefully
                System.err.println("Error saving user: " + e.getMessage());
            }
        }
    }


If we need to change how users are saved (e.g., switch to a NoSQL database or save to a file), we have to modify the User class. Also, if we change user data representation, we might also need to change the User class.

#### Good Example (Follows SRP):

We separate the persistence logic into its own class, say UserRepository.


    public class User {
        private String name;
        private String email;

        public User(String name, String email) {
            this.name = name;
            this.email = email;
        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        public String getEmail() {
            return email;
        }

        public void setEmail(String email) {
            this.email = email;
        }

        // User class is now only responsible for holding user data
    }

    public class UserRepository {
        public void save(User user) {
            // This is a simplified example. In a real app, use a proper ORM or DAO.
            try (Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb", "user", "password")) {
                String sql = "INSERT INTO users (name, email) VALUES (?, ?)";
                try (PreparedStatement statement = connection.prepareStatement(sql)) {
                    statement.setString(1, user.getName());
                    statement.setString(2, user.getEmail());
                    statement.executeUpdate();
                    System.out.println("User " + user.getName() + " saved to database by UserRepository.");
                }
            } catch (SQLException e) {
                // In a real app, handle this exception more gracefully
                System.err.println("Error saving user via UserRepository: " + e.getMessage());
            }
        }
    }

Now, the User class is only responsible for user data, and UserRepository is only responsible for user persistence.

## Open/Closed Principle (OCP)
### Concept
Software entities (classes, modules, functions, etc.) should be open for extension but closed for modification.

### Why it's important

- Stability: You can add new functionality without changing existing, tested code, reducing the risk of introducing bugs.
- Flexibility: Makes it easier to adapt the system to new requirements.


### Explanation

Imagine we have a PaymentProcessor class that processes payments. Initially, it only supports credit card payments.

#### Bad Example (Violates OCP):


    enum PaymentType {
        CREDIT_CARD,
        PAYPAL // Added later
    }

    public class PaymentProcessor {
        public void processPayment(double amount, PaymentType type) {
            if (type == PaymentType.CREDIT_CARD) {
                System.out.println("Processing credit card payment of $" + amount);
                // Logic for credit card payment
            } else if (type == PaymentType.PAYPAL) { // MODIFICATION: Added new payment type
                System.out.println("Processing PayPal payment of $" + amount);
                // Logic for PayPal payment
            }
            // If we add another payment type (e.g., Bitcoin), we have to modify this class again.
        }
    }

To add PayPal payments, we had to modify the PaymentProcessor class.

#### Good Example (Follows OCP):

We can use an interface or an abstract class and then create concrete implementations for each payment type.

    public interface PaymentMethod {
        void processPayment(double amount);
    }

    public class CreditCardPayment implements PaymentMethod {
        @Override
        public void processPayment(double amount) {
            System.out.println("Processing credit card payment of $" + amount);
            // Logic for credit card payment
        }
    }

    public class PayPalPayment implements PaymentMethod {
        @Override
        public void processPayment(double amount) {
            System.out.println("Processing PayPal payment of $" + amount);
            // Logic for PayPal payment
        }
    }

    // New payment method - EXTENSION
    public class BitcoinPayment implements PaymentMethod {
        @Override
        public void processPayment(double amount) {
            System.out.println("Processing Bitcoin payment of $" + amount);
            // Logic for Bitcoin payment
        }
    }


    public class PaymentProcessor {
        public void process(PaymentMethod paymentMethod, double amount) {
            // The PaymentProcessor class does not need to change
            // when new payment methods are added.
            paymentMethod.processPayment(amount);
        }
    }

Now, to add a new payment method (e.g., BitcoinPayment), we just create a new class implementing PaymentMethod. The PaymentProcessor class remains unchanged (closed for modification) but is open for extension (we can pass new PaymentMethod implementations to it).

## Liskov Substitution Principle (LSP)
### Concept
Subtypes must be substitutable for their base types without altering the correctness of the program. In simpler terms, if class S is a subtype of class T, then objects of type T may be replaced with objects of type S without any undesirable side effects.

### Why it's important

- Reliability: Ensures that inheritance hierarchies are well-designed and that polymorphism works as expected.
- Code Reusability: Allows you to use superclass references to operate on subclass objects confidently.

### Explanation

Consider a classic example with Rectangle and Square. If Square inherits from Rectangle and overrides setters in a way that breaks the Rectangle's contract, it violates LSP.

#### Bad Example (Violates LSP):

    public class Rectangle {
        protected int width;
        protected int height;

        public void setWidth(int width) {
            this.width = width;
        }

        public void setHeight(int height) {
            this.height = height;
        }

        public int getWidth() {
            return width;
        }

        public int getHeight() {
            return height;
        }

        public int getArea() {
            return width * height;
        }
    }

    public class Square extends Rectangle {
        @Override
        public void setWidth(int width) {
            super.setWidth(width);
            super.setHeight(width); // A square's width and height must be equal
        }

        @Override
        public void setHeight(int height) {
            super.setHeight(height);
            super.setWidth(height); // A square's width and height must be equal
        }
    }

    public class AreaCalculator {
        public static void printArea(Rectangle r) {
            r.setWidth(5);
            r.setHeight(4);
            // Expected area for a rectangle: 5 * 4 = 20
            // If r is a Square, setHeight(4) will also setWidth(4).
            // So, area will be 4 * 4 = 16, which is unexpected for client code
            // that assumes it's working with a generic Rectangle.
            System.out.println("Expected area: 20, Actual area: " + r.getArea());
            if (r.getArea() != 20 && r instanceof Square) {
                System.out.println("LSP Violated for Square!");
            } else if (r.getArea() == 20) {
                System.out.println("LSP Not Violated for Rectangle!");
            }
        }

        public static void main(String[] args) {
            Rectangle rectangle = new Rectangle();
            System.out.println("Testing Rectangle:");
            printArea(rectangle); // Output: Expected area: 20, Actual area: 20

            Rectangle square = new Square();
            System.out.println("\nTesting Square (as Rectangle):");
            printArea(square);    // Output: Expected area: 20, Actual area: 16. LSP Violated!
        }
    }

Here, Square changes the behavior of setWidth and setHeight in a way that a client expecting a Rectangle wouldn't anticipate. If you pass a Square to a method expecting a Rectangle, the behavior might be incorrect.

#### Good Example (Follows LSP):

One way to fix this is to not have Square inherit from Rectangle if their contracts for setting width and height are different. Instead, they could both implement a common Shape interface, or have a more generic base class.


    public interface Shape {
        int getArea();
    }

    public class Rectangle implements Shape {
        protected int width;
        protected int height;

        public Rectangle(int width, int height) {
            this.width = width;
            this.height = height;
        }

        public void setWidth(int width) {
            this.width = width;
        }

        public void setHeight(int height) {
            this.height = height;
        }

        public int getWidth() {
            return width;
        }

        public int getHeight() {
            return height;
        }

        @Override
        public int getArea() {
            return width * height;
        }
    }


    public class Square implements Shape {
        private int side;

        public Square(int side) {
            this.side = side;
        }

        public void setSide(int side) {
            this.side = side;
        }

        public int getSide() {
            return side;
        }

        @Override
        public int getArea() {
            return side * side;
        }
    }

    public class AreaCalculator {
        // This method now takes a Shape, which is more generic
        // and doesn't rely on specific setter behaviors of Rectangle.
        public static void printArea(Shape s) {
            System.out.println("Area: " + s.getArea());
        }

        public static void main(String[] args) {
            Rectangle rectangle = new Rectangle(5, 4);
            System.out.println("Testing Rectangle:");
            // To demonstrate the issue from the bad example, we'd need a method
            // that tries to manipulate width/height specifically.
            // For LSP, the key is that if a method expects a Rectangle,
            // and you give it a Square (if Square IS-A Rectangle),
            // it shouldn't break.

            // With the new design, Rectangle and Square are distinct types implementing Shape.
            // A method expecting a Shape can safely work with both.
            Shape rectShape = new Rectangle(5, 4);
            printArea(rectShape); // Area: 20

            Shape squareShape = new Square(5);
            printArea(squareShape); // Area: 25

            // If we had a method that specifically needed to resize a rectangle:
            resizeAndPrint(new Rectangle(3, 2));

            // We wouldn't pass a Square to a method designed to independently resize width/height
            // because Square doesn't have that capability in this good design.
            // If Square inherited Rectangle, LSP would be about ensuring that
            // Square behaves like a Rectangle in all contexts where a Rectangle is expected.
        }

        public static void resizeAndPrint(Rectangle r) {
            r.setWidth(10);
            r.setHeight(5);
            System.out.println("Resized Rectangle Area: " + r.getArea()); // Expected: 50
        }
    }

In this "good" example, Square and Rectangle are distinct. If you need to treat them polymorphically for area calculation, they can implement a common Shape interface. The key is that a Square doesn't pretend to be a Rectangle in a way that violates the Rectangle's contract (e.g., independent setting of width and height).

## Interface Segregation Principle (ISP)
### Concept: 
Clients should not be forced to depend on interfaces they do not use. It's better to have many small, specific interfaces than one large, general-purpose interface.

### Why it's important

- Reduced Coupling: Classes only depend on the methods they actually need.
- Improved Cohesion: Interfaces are more focused.
- Better Maintainability: Changes to an interface affect fewer clients.

### Explanation

Imagine a "fat" interface Worker with methods for working, eating, and sleeping.

#### Bad Example (Violates ISP):

    // "Fat" interface
    interface Worker {
        void work();
        void eat();
        void sleep(); // Not all workers might need to implement sleep in the same way or at all
    }

    class HumanWorker implements Worker {
        @Override
        public void work() {
            System.out.println("Human working");
        }

        @Override
        public void eat() {
            System.out.println("Human eating");
        }

        @Override
        public void sleep() {
            System.out.println("Human sleeping");
        }
    }

    class RobotWorker implements Worker {
        @Override
        public void work() {
            System.out.println("Robot working");
        }

        @Override
        public void eat() {
            // Robots might not "eat" in the human sense.
            // This method might be irrelevant or need a dummy implementation.
            System.out.println("Robot recharging (equivalent to eating)");
        }

        @Override
        public void sleep() {
            // Robots might not "sleep".
            // This method might be irrelevant or need a dummy implementation.
            System.out.println("Robot in standby (equivalent to sleeping)");
        }
    }

RobotWorker is forced to implement eat() and sleep() even if these concepts don't directly apply or have different meanings.

#### Good Example (Follows ISP):

We break down the Worker interface into smaller, more specific interfaces.


    public interface Workable {
        void work();
    }

    public interface Feedable {
        void eat();
    }

    public interface Restable {
        void sleep();
    }

    public class HumanWorker implements Workable, Feedable, Restable {
        @Override
        public void work() {
            System.out.println("Human working");
        }

        @Override
        public void eat() {
            System.out.println("Human eating");
        }

        @Override
        public void sleep() {
            System.out.println("Human sleeping");
        }
    }

    // RobotWorker only implements interfaces relevant to it.
    // If it needs a concept of "recharging", it could implement a different specific interface.
    public class RobotWorker implements Workable {
        @Override
        public void work() {
            System.out.println("Robot working efficiently");
        }

        // No need to implement eat() or sleep() if they don't make sense for a robot.
        // If it has a concept of charging, it could implement a Chargeable interface.
    }

    interface Chargeable {
        void charge();
    }

    class AdvancedRobotWorker implements Workable, Chargeable {
        @Override
        public void work() {
            System.out.println("Advanced Robot working");
        }

        @Override
        public void charge() {
            System.out.println("Advanced Robot charging");
        }
    }

Now, classes only implement the interfaces whose methods they actually use. RobotWorker only needs to be Workable. If it has a charging mechanism, it can implement a separate Chargeable interface.

## Dependency Inversion Principle (DIP)
### Concept:

High-level modules should not depend on low-level modules. Both should depend on abstractions (e.g., interfaces).
Abstractions should not depend on details. Details (concrete implementations) should depend on abstractions.

### Why it's important

- Decoupling: Reduces the dependency of high-level modules on the concrete implementations of low-level modules. This makes the system more flexible and easier to change.
- Testability: Easier to mock dependencies for unit testing.

### Explanation

Consider a NotificationService (high-level) that directly uses an EmailSender (low-level).

#### Bad Example (Violates DIP):

    // Low-level module
    public class EmailSender {
        public void sendEmail(String recipient, String message) {
            System.out.println("Sending email to " + recipient + ": " + message);
            // Actual email sending logic
        }
    }

    // High-level module
    public class NotificationService {
        private EmailSender emailSender; // Direct dependency on a concrete low-level module

        public NotificationService() {
            this.emailSender = new EmailSender(); // Instantiation of low-level module
        }

        public void sendNotification(String recipient, String message) {
            // Business logic for notification
            emailSender.sendEmail(recipient, message);
        }

        public static void main(String[] args) {
            NotificationService notificationService = new NotificationService();
            notificationService.sendNotification("test@example.com", "Hello from Bad DIP!");
        }
    }

Here, NotificationService directly depends on the concrete EmailSender. If we want to switch to SMS notifications or use a different email sending library, we have to modify NotificationService.

#### Good Example (Follows DIP):

We introduce an abstraction (interface) MessageSender, and both NotificationService and concrete senders depend on this abstraction.


    // Abstraction
    public interface MessageSender {
        void sendMessage(String recipient, String message);
    }

    // Low-level module implementing the abstraction
    public class EmailSender implements MessageSender {
        @Override
        public void sendMessage(String recipient, String message) {
            System.out.println("Sending email to " + recipient + ": " + message);
            // Actual email sending logic
        }
    }

    // Another low-level module implementing the abstraction
    public class SmsSender implements MessageSender {
        @Override
        public void sendMessage(String recipientPhoneNumber, String message) {
            System.out.println("Sending SMS to " + recipientPhoneNumber + ": " + message);
            // Actual SMS sending logic
        }
    }

    // High-level module depending on the abstraction
    public class NotificationService {
        private MessageSender messageSender; // Depends on the abstraction

        // Dependency is injected (Dependency Injection)
        public NotificationService(MessageSender messageSender) {
            this.messageSender = messageSender;
        }

        public void sendNotification(String recipient, String message) {
            // Business logic for notification
            messageSender.sendMessage(recipient, message);
        }

        public static void main(String[] args) {
            // Using EmailSender
            MessageSender emailer = new EmailSender();
            NotificationService emailNotificationService = new NotificationService(emailer);
            emailNotificationService.sendNotification("test@example.com", "Hello via Email (Good DIP)!");

            // Using SmsSender
            MessageSender smser = new SmsSender();
            NotificationService smsNotificationService = new NotificationService(smser);
            smsNotificationService.sendNotification("+1234567890", "Hello via SMS (Good DIP)!");
        }
    }

Now, NotificationService depends on the MessageSender interface, not on a concrete implementation. We can easily switch out EmailSender for SmsSender (or any other MessageSender implementation) without changing NotificationService. This is often achieved using Dependency Injection.
