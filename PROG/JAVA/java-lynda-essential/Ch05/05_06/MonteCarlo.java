package samplesimulation;

import java.util.Arrays;

public class MonteCarlo
{
    public static void main(String[] args)
    {
        System.out.println("Probability of Drawing 3 marbles of the same color-");
        System.out.println("100 trials: " + marbleSimulation(100));
        System.out.println("1000 trials: " + marbleSimulation(1000));
        System.out.println("10000 trials: " + marbleSimulation(10000));
    }

    /**
     * Runs numTrials trials of a Monte Carlo simulation of drawing 3 marbles 
     * out of a bowl containing 3 blue marbles and 3 white marbles. Marbles are 
     * not replaced once drawn.
     * 
     * @param numTrials
     *          - the number of times the method will attempt to draw 3 marbles
     * @returns a double - the fraction of times 3 marbles of the same color 
     *          were selected.
     */

    public static String marbleSimulation(int numTrials)
    {
        final int B = 1;
        final int W = 2;

        double number = 0.0;
        double result = 0.0;

        for (int t = 0; t < numTrials; t++)
        {
            result++;

            int[] bowl =
            { B, B, B, W, W, W };
            int[] drawMarbles = new int[3];

            for (int draw = 0; draw < 3; draw++)
            {
                int index = (int) (Math.random() * bowl.length);
                drawMarbles[draw] = bowl[index];
                int[] newBowl = new int[bowl.length - 1];
                int j = 0;
                for (int i = 0; i < bowl.length; i++)
                {
                    if (i == index)
                    {
                        continue;
                    }
                    newBowl[j] = bowl[i];
                    j++;
                }
                bowl = newBowl;
            }

            if (drawMarbles[0] == drawMarbles[1] && drawMarbles[1] == drawMarbles[2])
            {
                number++;
               // System.out.println("winner");
            }
            //System.out.println(Arrays.toString(drawMarbles));
        }

        return "Results: " + (number / result);
    }
}