public class Cats {

    //the template of Cats
    String fur;
    int age;
    boolean domestic;

    //the cat generator

    public Cats(String itsFur, int itsAge, boolean itsDomestic) {
        this.fur = itsFur;
        this.age = itsAge;
        this.domestic = itsDomestic;
    }

    public void changeFur(String newColor) {
        this.fur = newColor;
    }

    public int nextYear() {
        age += 1;
        return age;
    }

    public String meaow(String noise) {
        return noise;
    }
}