public class Main {

    //needs to do something
    public static void main(String[] argv) {
        System.out.println("Here is the challenge...");
        Cats myCat = new Cats("White", 4, false);

        System.out.println("Here is my cat: Fur: " +
                myCat.fur + " Age: " +
                myCat.age + " Domestic: " +
                myCat.domestic);

        myCat.changeFur("Green");
        System.out.println("My cat fell into paint : Fur: " +
                myCat.fur + " Age: " +
                myCat.age + " Domestic: " +
                myCat.domestic);

        myCat.nextYear();
        System.out.println("Next year the cat is this : Fur: " +
                myCat.fur + " Age: " +
                myCat.age + " Domestic: " +
                myCat.domestic);

        String kitty = myCat.meaow("Meeeeaow");
        System.out.println("My cat greets you: " + kitty);

    }
}