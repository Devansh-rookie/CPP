class T1 extends Thread{
    public void run(){
        for(int i=0;i < 30;i++){
            System.out.println("Good Morning");
            try{Thread.sleep(1000);}
            catch(Exception e){}
        }
    }
}

class T2 extends Thread{
    public void run(){
        for(int i=0;i < 15;i++){
            System.out.println("Bye");
            try{Thread.sleep(2000);}
            catch(Exception e){}
        }
    }
}


public class neww{
    public static void main(String[] args) {
        Thread t1 = new Thread(new T1());
        Thread t2 = new Thread(new T2());

        t1.start();
        t1.setPriority(Thread.MAX_PRIORITY);
        t2.start();
    }
}