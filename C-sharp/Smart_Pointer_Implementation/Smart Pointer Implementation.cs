using System;

public class SmartPointer<T> where T : class
{
    private T _pointer;

    public SmartPointer(T pointer)
    {
        _pointer = pointer;
    }

    public T Pointer => _pointer;

    public void Release()
    {
        _pointer = null;
        Console.WriteLine("Pointer released.");
    }
}

class Program
{
    static void Main()
    {
        var obj = new object();
        var smartPointer = new SmartPointer<object>(obj);
        Console.WriteLine("Object created.");
        smartPointer.Release();
    }
}
