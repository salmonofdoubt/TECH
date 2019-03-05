public class Spider extends Insect {

    boolean isPoisonous;

    public Spider(int age, boolean isPoisonous) {
        super(age, 8);
        this.isPoisonous = isPoisonous;
    }
    //this one overwrites the say() method from Insect
    public void says() {
        System.out.println("Spider says");
    }
}
