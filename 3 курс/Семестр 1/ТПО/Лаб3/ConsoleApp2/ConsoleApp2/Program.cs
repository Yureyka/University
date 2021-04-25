using System;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("---------------------ИЗДАТЕЛЬСТВО---------------------");

            Publish book_1 = new Publish("Поваренная книга анархиста", "Уильям Пауэлл", 1200, "Нет");
            book_1[0] = "Введение";
            book_1[1] = "История";
            book_1[2] = "Создание";
            book_1[3] = "Применение";
            book_1.Print();
            book_1.Circulation(new Random().Next(100));
            book_1.PrintСirculation();

            Console.WriteLine("\n------------------------------------------------------");

            Publish book_2 = new Publish("Сделай сам", "Николай Степанович Амеба", 150, "Да");
            book_2[0] = "Введение";
            book_2[1] = "Сделай";
            book_2[2] = "Выброси";
            book_2.Print();
            book_2.Circulation(new Random().Next(100));
            book_2.PrintСirculation();

            try
            {
                int b = 0;
                book_2.Article = "Сделай сам";
            }
            catch (ExceptionHandler exception)
            {
                Console.WriteLine($"\nПопытка изменить поле Название.\nОшибка: {exception.warn}");
            }

            Console.ReadKey();
        }
    }
}
