public class Main {
//This Main does not use any other classes
    public static void main(String[] args) {
        String userInput = "entertainment";
        String uppercased = userInput.toUpperCase();
        System.out.println(userInput);
        System.out.println(uppercased);

        //which is 'e'
        char firstCharacter = userInput.charAt(0);
        System.out.println(firstCharacter);

        //does it contain a substring when it's lower cased
        System.out.println("Contains: " +
                userInput.contains("Enterta".toLowerCase()));
    }
}
