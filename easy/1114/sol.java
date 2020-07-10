class Foo {
    int counter = 0;
    
    public Foo() {}

    public synchronized void first(Runnable printFirst) throws InterruptedException {
        while(counter != 0) {
            wait();
        }
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        counter++;
        notifyAll();
    }

    public synchronized void second(Runnable printSecond) throws InterruptedException {
        while(counter != 1) {
            wait();
        }
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        counter++;
        notifyAll();
    }

    public synchronized void third(Runnable printThird) throws InterruptedException {
        while(counter != 2) {
            wait();
        }
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
        counter++;
        notifyAll();
    }
}
