public class PrintMessage {

    public static void main(String[] args) {

        System.out.println("EX.7 INTRODUCTION TO BASIC JAVA!");

    }

}



import java.util.Scanner;

 

public class InputOutput {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a value: ");

        int value = scanner.nextInt();

        System.out.println("You entered: " + value);


    }}



import java.util.Scanner;

 

public class AddNumbers {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter first number: ");

        int num1 = scanner.nextInt();

        System.out.print("Enter second number: ");

        int num2 = scanner.nextInt();

        int sum = num1 + num2;

        System.out.println("Sum: " + sum);

    }


}



import java.util.Scanner;

 

public class Calculator {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter first number: ");

        double num1 = scanner.nextDouble();

        System.out.print("Enter operator (+, -, *, /): ");

        char operator = scanner.next().charAt(0);

        System.out.print("Enter second number: ");

        double num2 = scanner.nextDouble();

       

        double result = 0;

        switch (operator) {

            case '+':

                result = num1 + num2;

                break;

            case '-':

                result = num1 - num2;

                break;

            case '*':

                result = num1 * num2;

                break;

            case '/':

                if (num2 != 0) {

                    result = num1 / num2;

                } else {

                    System.out.println("Error: Division by zero!");

                    return;

                }

                break;

            default:

                System.out.println("Invalid operator!");

                return;

        }

       

        System.out.println("Result: " + result);

    }


}