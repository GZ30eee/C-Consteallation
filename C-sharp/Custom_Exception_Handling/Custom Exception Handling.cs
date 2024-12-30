using System;

class CustomException : Exception
{
    public CustomException(string message) : base(message) { }
}

class Program
{
    static void Main()
    {
        try
        {
            ThrowCustomException();
        }
        catch (CustomException ex)
        {
            Console.WriteLine($""Caught exception: {ex.Message}"");
        }
    }

    static void ThrowCustomException()
    {
        throw new CustomException(""This is a custom exception!"");
    }
}
