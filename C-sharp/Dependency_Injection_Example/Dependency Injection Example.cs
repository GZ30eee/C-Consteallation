using System;

public interface IMessageService
{
   void SendMessage(string message);
}

public class EmailService : IMessageService
{
   public void SendMessage(string message)
   {
       Console.WriteLine($""Email sent: {message}"");
   }
}

public class NotificationManager
{
   private readonly IMessageService _messageService;

   public NotificationManager(IMessageService messageService)
   {
       _messageService = messageService;
   }

   public void Notify(string message)
   {
       _messageService.SendMessage(message);
   }
}

class Program
{
   static void Main()
   {
       IMessageService emailService = new EmailService();
       var notificationManager = new NotificationManager(emailService);
       
       notificationManager.Notify(""Hello Dependency Injection!"");
   }
}
