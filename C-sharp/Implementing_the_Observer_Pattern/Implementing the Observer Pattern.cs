using System;
using System.Collections.Generic;

public interface IObserver
{
    void Update(string message);
}

public class Subject
{
    private readonly List<IObserver> observers = new List<IObserver>();

    public void Attach(IObserver observer)
    {
        observers.Add(observer);
    }

    public void Notify(string message)
    {
        foreach (var observer in observers)
            observer.Update(message);
    }
}

public class ConcreteObserver : IObserver
{
    public void Update(string message)
    {
        Console.WriteLine($""Observer received: {message}"");
    }
}

class Program
{
    static void Main()
    {
        var subject = new Subject();
        
        var observer1 = new ConcreteObserver();
        subject.Attach(observer1);

        subject.Notify(""Hello Observers!"");
    }
}
