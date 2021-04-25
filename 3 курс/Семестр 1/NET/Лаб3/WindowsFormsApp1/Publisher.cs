using System;

namespace WindowsFormsApp1
{
    class Publisher
    {
        public string name { get; set; }
        public string author { get; set; }
        public double price { get; set; }
        public string[] contents { get; set; }

        public Publisher(string name, string author, double price, string[] contents)
        {
            this.name = name;
            this.author = author;
            this.price = price;
            this.contents = contents;
        }
    }
}