using System;
using System.Drawing;

namespace WindowsFormsApp2
{
    [Serializable]
    public class Publisher
    {
        public string name { get; set; }
        public string author { get; set; }
        public int price { get; set; }
        public string contents { get; set; }
        public DateTime date { get; set; }
        public string photo { get; set; }

        public Publisher(string name, string author, int price, string contents, DateTime date, string photo)
        {
            this.name = name;
            this.author = author;
            this.price = price;
            this.contents = contents;
            this.date = date;
            this.photo = photo;
        }
    }
}