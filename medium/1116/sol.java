class ZeroEvenOdd {
    private int n;
    private boolean zeroTurn = true;
    private int counter = 1;
    
    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public synchronized void zero(IntConsumer printNumber) throws InterruptedException {
        for(int i=0; i<n; i++) {
            while(!zeroTurn) wait();
            printNumber.accept(0);
            zeroTurn = false;
            notifyAll();
        }
    }

    public synchronized void even(IntConsumer printNumber) throws InterruptedException {
        for(int i=2; i<=n; i+=2) {
            while(zeroTurn || counter%2 == 1) wait();
            printNumber.accept(counter);
            counter++;
            zeroTurn = true;
            notifyAll();
        }
    }

    public synchronized void odd(IntConsumer printNumber) throws InterruptedException {
        for(int i=1; i<=n; i+=2) {
            while(zeroTurn || counter%2 == 0) wait();
            printNumber.accept(counter);
            counter++;
            zeroTurn = true;
            notifyAll();
        }
    }
}
