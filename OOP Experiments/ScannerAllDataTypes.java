import java.util.Scanner;

class ScannerAllDataTypes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int intVal = sc.nextInt();
        float floatVal = sc.nextFloat();
        double doubleVal = sc.nextDouble();
        long longVal = sc.nextLong();
        short shortVal = sc.nextShort();
        byte byteVal = sc.nextByte();
        boolean boolVal = sc.nextBoolean();

        char charVal = sc.next().charAt(0);

        String word = sc.next();
        sc.nextLine();
        String sentence = sc.nextLine();
        System.out.println("");
        System.out.println("You entered:");
        System.out.println(intVal);
        System.out.println(floatVal);
        System.out.println(doubleVal);
        System.out.println(longVal);
        System.out.println(shortVal);
        System.out.println(byteVal);
        System.out.println(boolVal);
        System.out.println(charVal);
        System.out.println(word);
        System.out.println(sentence);
    }
}