<?php


class Interest extends Model
{
    const HOBBY_NAME = ["Спорт", "Музыка", "Книги"];
    const HOBBY_LINKS = ["Sport", "Music", "Books"];
    const HOBBY_DESCRIPTION = ["Мой любимый вид спорта - Волейбол! Игра, в которой быстрота, реакция, сила, мощь и красота слились воедино 💖",
        "Игра на гитаре и пианино уносит в параллельную реальность, особенно, когда звучит Шопен 🎵",
        "И, конечно, погружаться на досуге в другой мир, в который тебя уносят авторы книг, бесценно"];

    public static $path = "/assets/img/";
    public function __construct()    {
    }
}