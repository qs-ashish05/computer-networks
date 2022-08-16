import java.util.Scanner;
import java.lang.math;

class Hamming_code{

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter The data (D3 D2 D1 D0): ");
        System.out.println("Enter D3: ");
        int D3 = sc.nextInt();
        System.out.println("Enter D2: ");
        int D2 = sc.nextInt();
        System.out.println("Enter D1: ");
        int D1 = sc.nextInt();
        System.out.println("Enter D0: ");
        int D0 = sc.nextInt();

        if((D3 == 0 || D3 == 1) && (D2 == 0 || D2 == 1) && (D1 == 0 || D1 == 1) && (D0 == 0 || D0 == 1)){
            System.out.println("Data is valid");
        }
        else{
            System.out.println("Data is Invalid");
        }

        
        System.out.println("The Input data is (D3 D2 D1 D0) : "+D3+D2+D1+D0);


        System.out.println("Chose parity Sceme : \n\t1.Even\t2.Odd");
        int parity = sc.nextInt();
        sc.close();

        if(parity == 1 || parity == 0){
            System.out.println("Parity scheme is valid");
        }
        else{
            System.out.println("parity scheme is Invalid");
        }

        double r = 0;
        double a = 2;

        int A;
        A = Math.pow(a,r);

        double B = 5 + r;
    }
}