import java.util.*;

class ArrayExample {
    int arr[] = new int[10];

    void inputArray() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 10 integers:");

        try {
            for (int i = 0; i < 10; i++) {
                arr[i] = sc.nextInt();
            }
        } catch (InputMismatchException e) {
            System.out.println("Give only integers ");
        }
    }

    void divideArray() {
        Scanner sc = new Scanner(System.in);

        try {
            System.out.print("Enter divisor: ");
            int n = sc.nextInt();

            for (int i = 0; i < 10; i++) {
                System.out.println(arr[i] / n);
            }
        } catch (ArithmeticException e) {
            System.out.println("You cannot divide by zero");
        }
    }

    public static void main(String[] args) {
        ArrayExample obj = new ArrayExample();
        obj.inputArray();
        obj.divideArray();
    }
}