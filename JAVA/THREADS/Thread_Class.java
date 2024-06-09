// points :
// if we implement a class from Thread class then that class
// cannot have any other Parent class as  multiple inheritance 
// is not allowed  in JAVA 
// so making threads from Runnable Interface is advisable
class A extends Thread {
    public void run() {
        int i ;
        for(i=1;i<=10;i++){
            System.out.println("i = "+ i + " Thread A" );
        }
        
    }
}

class B extends Thread {
    public void run() {
        int i ;
        for(i=1;i<=10;i++){
            System.out.println("i = "+ i + " Thread B" );
        }
        
    }
}

public class Example {
    public static void main(String args[]){

        // a class inheriting from Thread class
        // then the objects of inherited class act as threads only

        A o1 = new A(); // o1 and o2 are acting as threads 
        B o2 = new B();

        o1.start();
        o2.start();
    }
}
