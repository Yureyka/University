using System;

namespace ConsoleApp2
{
    abstract class Pub
    {
        private string article;
        private string author;
        private string[] chapter = new string[5];

        public string Article
        {
            get { return article; }
            set { if (article == null) { article = value; } else { throw new ExceptionHandler(Field.Article); } }
        }

        
        public string Author
        {
            get { return author; }
            set { if (author == null) { author = value; } else { throw new ExceptionHandler(Field.Author); } }
        }

        public int price { get; set; }

        public int ChaptersCount { get; private set; } = 0;

        public string this[int i]
        {
            get
            {
                if (i >= 0 && i <= ChaptersCount) { return chapter[i]; }
                else { throw new ExceptionHandler(Field.chapter); }
            }
            set
            {
                if (i == ChaptersCount) { chapter[i] = value; ChaptersCount++; }
                else if (i >= 0 && i <= ChaptersCount) { chapter[i] = value; }
                else { throw new ExceptionHandler(Field.chapter); }
            }
        }

        public Pub(string article, string author, int price)
        {
            this.article = article;
            this.author = author;
            this.price = price;
        }

        public virtual void Print()
        {
            Console.WriteLine($"\nКнига: {article}\nИмя автора: {author}\nСтоимость: {price}\n");
        }

        public void Contents()
        {
            Console.WriteLine("-------Оглавление-------");
            for (int i = 0; i < ChaptersCount; i++)
            {
                Console.WriteLine($"Глава {i + 1}......{this[i]}");
            }
        }

        public abstract void PrintСirculation();
    }
}
