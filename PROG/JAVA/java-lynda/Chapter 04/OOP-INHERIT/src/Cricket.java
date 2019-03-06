class Cricket extends Insect {

    double length;

    public Cricket(int age, double length) {
        super(age, 6);
        //System.out.println(super.age);
        this.length = length;
    }

    public void says() {
        System.out.println("Cricket says");
    }

    public void jumps() {
        System.out.println("Cricket jumps");
    }

}
