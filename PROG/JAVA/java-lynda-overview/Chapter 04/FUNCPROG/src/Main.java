import java.awt.*;
import java.lang.Math;
import java.util.Random;

//lambda, uses not a class but an interface
public class Main {
    public static void main(String[] args) {
        //so a variable, of a type Interface holds the function, which has zero input
        Answerable phone = () -> "Hello";
        System.out.println(phone.answer());

        //n is the input
        //n%2.. is the function
        //n -> n % 2 != 0;

        Oddity number = n -> n % 2 != 0;
        System.out.println(number.oddOrEven(3));
    }
}

/*
From course: Learning Java

- [Narrator] In the past, whenever we've created a function, we've always had to put it inside a class.

With lambda, we can get around this. Lambdas are *anonymous functions* that you can create easily in Java without the
usual overhead of public, static, void, etc. It is a great tool if you need a quick function for a calculation in your
code.

Let's take a look at an example of this in Java. Here on line eight is an example of how lambda syntax works.
Usually in your functions, you'd have an access modifier, that's your public, private, etc., a return type, which would
be void and double whatever your function's returning, and the name of the function.
We don't do that here with lambda functions and that's what make them anonymous functions. Instead, we just have the
parameters, which in this case are none and then put the body of the code immediately after with a dash arrow -> and
write the body of the code, which is return "Hello."

This is erring right now because there are a couple of other things we need to set up, but let's take a look at another
example of an lambda function.
In the second lambda function on line 12, we have one input, which is n, and in the body of the function, we mod n by two to see if the input is odd or even.
If it is even, n mod two will return zero because mod gets the remainder of n divided by two, and if n is even, the remainder is zero. If n is odd, n mod two will return one because the remainder of n divided by two is one. Essentially, this lambda function will return false if the input n is even and true if the input n is odd. Now how do we make these errors go away? Well, we need to add the name of the function and return type somewhere but not here in our main method.
Instead, we'll be creating some interfaces that handle this portion for us. For this first example, we're going to create an interface called Answerable with an answer function that returns a string. So we're going to comment out this second lambda function here, and we're going to go up to our navigation bar and go File > New > Java Class, and in this case, we're going to be creating an interface, so we'll change that dropdown to Interface and we're going to name it Answerable. And inside of Answerable, we are going to create a method called String answer.
Now what do we do with this interface and the lambda function we created before? We are going to link them with a variable to create a reference. So going back to our main class, we're going to go ahead and create a variable of type Answerable. So we'll write Answerable, which is the interface we just created, and we're going to call this variable phone, and we're going to have it equal this function. So here a variable is holding the value of a function. Then we'll go ahead and add a semicolon here and our errors go away.
So what does this really mean? We are setting phone equal to this lambda function. This lambda function maps back to Answerable's answer function. So if we go System.out.println(phone.answer), we will be running our lambda function that we created above because this functionality maps to the signature String answer. So let's go ahead and run this in the console, and we see it return Hello.
Hello is printed out in the console because that is what our lambda function returns. So again, what does this mean? When we do Answerable phone equals this lambda function here on line eight, we are really setting phone.answer's implementation. This connects correctly because the signature for the answer function says that the function returns a string, and has zero inputs. And here in this implementation, we have zero inputs and we return a string.
Let's try doing the same thing for our second example here on line 12. So we'll go ahead and uncomment that and we're going to create a new interface. So we'll go Java Class, and then in the dropdown, Select Interface, and we're going to call this interface Predicate. Predicate is just a name for a function or expression that returns true or false. So we'll go ahead and create that interface, and in this interface, we're going to have the signature of a function that returns a boolean and is named test, and it's going to accept an integer called n.
Going back to our Main file, we're going to create a predicate variable to link this anonymous lambda implementation to the test function signature. So we'll go Predicate isOdd equals this implementation. And then we can go ahead and use this lambda function by going System.out.println(isOdd.test), and we'll give it the input two, and that's what our n is here. N is a parameter for this lambda function, and when we go two here, n gets the value of two, we go two mod two, and that is equal to zero, and so we get false as an output, and the fact that two is not odd.
Let's go ahead and run this and see what we get as an output and we do in fact get false. You may think it's strange that we don't have the keyword return, but it's actually not necessary here or in the previous example because the result of the evaluation is automatically returned. So we can actually remove return here, this semicolon as well as the curly brackets, and just have Hello. But why are we making these interfaces and lambda functions? Well, let's say I wanted to do another test called isEven.
I could go Predicate isEven, and it can be a predicate because isEven is going to accept one input, an integer called n, and it's going to output a boolean. So we can just do n, n mod two, is equal to zero, and that will be true if n is even, meaning n mod two equals zero, and it will be false if n is odd, which means that n mod two does not equal zero. And we can go ahead and test this out with isEven.test, and we'll give it two again.
Running the function, we get true in our console. What's so great about this is that we didn't need to create another class or a function signature to add the isEven variable and test method functionality. We created it with just one line of code. You've probably noticed that these lambda functions have a single purpose and return an immediate output without affecting any other objects in the code or producing an print side effects. This is what makes them a part of the functional programming style.
Now we've learned a lot in this course about the Java language, object-oriented and functional programming, as well as some of the basic building blocks of many programming languages. In the next video, we'll go over some next steps for how to deepen your coding knowledge.
* */