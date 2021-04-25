using System;

namespace ConsoleApp2
{
    class Publish : Pub, ICircutable
    {
        private int copies = 0;
        private string status;

        public string Status
        {
            get
            {
                Random rand = new Random();
                int n = rand.Next(100);
                if (n < 50)
                    status = "Да";
                else
                    status = "Нет";
                return status;
            }
            set { status = value; }
        }

        public Publish(string article, string author, int price, string status) : base(article, author, price)
        {
            this.status = status;
        }

        new public void Print()
        {
            Console.WriteLine($"\nНазвание: {Article}\nИмя автора: {Author}\nСтоимость: {price}\n");
            Contents();
        }

        public override void PrintСirculation()
        {
            Console.WriteLine($"Осталось: {copies} копий");
            Console.WriteLine($"Доступно к продаже: {status}");
        }

        public void Circulation(int copies)
        {
            this.copies = copies;
        }

        public int GetCirc()
        {
            return copies;
        }

    }
}
