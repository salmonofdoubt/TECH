import java.awt.*;
import java.lang.Math;
import java.util.Random;

/*
class Dog
play()

class Cat
play()

why not have myDog and myCat accessing the same method?

class Dog implements Pet
class Cat implements Pet

interface Pet
play()

interfaces are a definition of behaviour

*/

public class Main {
    public static void main(String[] args) {
        Dog myDog = new Dog();
        Cat myCat = new Cat();

        if (myDog instanceof Dog) {
            myDog.play();
        }
        if (myCat instanceof Cat) {
            myCat.play();
        }

        // You could also do this if bored:
        Pet myPet;
        Random rand = new Random();
        int n = rand.nextInt(2);

        if (n == 0) {
            myPet = new Dog();
        } else {
            myPet = new Cat();
        }
        myPet.play();
    }
}
