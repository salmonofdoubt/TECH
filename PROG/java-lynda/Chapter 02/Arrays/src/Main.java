import java.lang.reflect.Array;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        // 31 45 22 98 10
        // assign size of array, fixed
        int[] numbers = new int[5];

        numbers[0] = 31;
        numbers[1] = 45;
        numbers[2] = 22;
        numbers[3] = 98;
        numbers[4] = 10;

        int[] moreNumbers = {31, 45, 22, 98, 10};

        //Understand Arrays, Array
        Arrays.sort(numbers);
        System.out.println(Arrays.toString(numbers));
        //mem address
        System.out.println(moreNumbers);

        String[] myFavs = {"Twix", "Crunch", "Raiders"};

        //Raiders
        System.out.println(myFavs[2]);

        Change(myFavs);

        System.out.println(myFavs[2]);

        System.out.println(myFavs.length);

        //Array will work with mem reference rather than values
        System.out.println(Array.get(myFavs, 2));
    }

        private static void Change(String[] myStringArr) {
            myStringArr[2] = "Scotch";
        }
}