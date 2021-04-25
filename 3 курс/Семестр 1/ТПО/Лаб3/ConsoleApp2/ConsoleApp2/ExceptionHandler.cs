using System;

namespace ConsoleApp2
{
    class ExceptionHandler : Exception
    {
        public string warn { get; set; }
        public ExceptionHandler(Field type)
        {
            switch (type)
            {
                case Field.Article:
                    warn = "Поле Название не может быть изменено";
                    break;
                case Field.Author:
                    warn = "Поле Имя автора не может быть изменено";
                    break;
                case Field.chapter:
                    warn = "Некооректные данные в поле Глава";
                    break;
                default:
                    warn = "Некорректные данные";
                    break;
            }
        }
    }


    enum Field
    {
        Article,
        Author,
        chapter
    }
}
