import java.util.Scanner;

class Account {
    private int balance;

    public Account(int bal) {
        this.balance = bal;

    }
    public boolean is_balance(int w){


        if(balance >w){
            return true;
        }
        return false;
    }

    public void withdraw(int amt){
        balance = balance - amt;
        System.out.println("Withdraw done " + amt );
        System.out.println("Current balance : " + balance);

    }
}

class User  implements Runnable {
    private Account account;
    private String name;
    public User(Account account , String name){
        this.account = account;
        this.name = name;
    }

    public void run(){
       
        // problem area 
        // Synchronize

        synchronized(account){
            Scanner kb = new Scanner(System.in);
            System.out.println( name + " Enter amount to withdraw : ");
            int amt = kb.nextInt();
            // here account is the shared resource

        
        // now only one thread will be able to access this at a time
        if(account.is_balance(amt)){
            
            System.out.println(name);
            account.withdraw(amt);
        }
        else{
            System.out.println(name);
            System.out.println("Insufficient balance");
        }
    }

    }
}

public class Example {
    public static void main(String args[]) {

        Account a1 = new Account(1000);
        User u1 = new User(a1 , "Aditi"),u2 = new User(a1 , "Molshree");
        Thread t1 = new Thread(u1);
        Thread t2  = new Thread(u2);

        t1.start();
        t2.start();
    }
}
/*

OUTPUT : 
Aditi Enter amount to withdraw : 
600
Aditi
Withdraw done 600
Current balance : 400
Molshree Enter amount to withdraw : 
700
Molshree
Insufficient balance
 */
